// Imprimir una palabra por linea

#include <stdio.h>

void PalabraPorLinea(FILE *);

int main(void)
{

	PalabraPorLinea(stdin);
	return 0;
}

void PalabraPorLinea(FILE *in)
{
	typedef enum
	{
		IN,
		OUT
	} State;
	State state = OUT;

	for (int c; (c = getc(in)) != EOF;)
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT || state == IN)
		{
			state = IN;
			printf("%c", c);

			if (state == OUT)
				printf("\n");
		}
}