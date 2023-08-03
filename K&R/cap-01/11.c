// ¿Cómo probaría el programa para contar palabras?
// ¿Qué clase de entrada es la más conveniente para descubrir errores si éstos existen?

#include <stdio.h>

unsigned ContarPalabras(FILE *);
    
int main (void) {
    printf ("%d\n", ContarPalabras(stdin));
    return 0;
}

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