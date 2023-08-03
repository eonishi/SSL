#include <stdio.h>
#include <assert.h>
// Histograma de la longitud de palabras

int* GenerarHistograma(FILE *, int *);
void PrintHistograma(int *);

int main(void)
{
    int histograma[100] = {0};
    GenerarHistograma(stdin, histograma);
    PrintHistograma(histograma);

    return 0;
}

int* GenerarHistograma(FILE *in, int *histograma)
{
    typedef enum
    {
        IN,
        OUT
    } State;
    State state = OUT;
    int longitud = 0;

    for (int c; (c = getc(in)) != EOF;)
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            histograma[longitud]++;
            longitud = 0;
        }
        else 
        {
            state = IN;
            longitud++;
        }
    return histograma;
}

void PrintHistograma(int *histograma)
{
    for (int i = 1; i < 100; i++)
        if (histograma[i] > 0)
        {
            printf("%2d\t", i);
            for (int j = 0; j < histograma[i]; j++)
                printf("-");
            printf("\n");
        }
}
