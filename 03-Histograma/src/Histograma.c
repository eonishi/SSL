#include"../include/Histograma.h"


int* GenerarHistograma(FILE *in, int *histograma)
{
    typedef enum
    {
        IN,
        OUT
    } State;
    State state = OUT;
    unsigned longitud = 0;

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
    if (state == IN) {
        histograma[longitud]++;
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
