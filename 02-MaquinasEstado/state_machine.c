#include "state_machine.h" // Interfaz que exporta

unsigned ContarPalabras(FILE *in)
{
	unsigned nw = 0;
	typedef enum
	{
		IN,
		OUT
	} State;
	State state = OUT;

	for (int c; (c = getc(in)) != EOF;)
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	return nw;
}