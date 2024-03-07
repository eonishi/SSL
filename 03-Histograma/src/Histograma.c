#include "../include/Histograma.h"
/*
long* GenerarHistograma(FILE *in, int *histograma)
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
}*/

int *GenerarHistograma(FILE *INPUT, int *histograma)
{
    typedef enum
    {
        OUT,
        IN
    } State;

    unsigned longitud = 0;
    State s = OUT;

    for (int c; (c = getc(INPUT)) != EOF;)
    {
        switch (c)
        {
        case '\n':
            s = OUT;
            histograma[longitud]++;
            longitud = 0;
            break;

        case ' ':
            s = OUT;
            histograma[longitud]++;
            longitud = 0;
            break;

        case '\t':
            s = OUT;
            histograma[longitud]++;
            longitud = 0;
            break;

        default:
            s = IN;
            longitud++;
            break;
        }
    }
    if (s == IN)
        {
            s = OUT;
            histograma[longitud]++;
        }

    return histograma;
}

void PrintHistograma(int *histograma, char symbol)
{
    for (int i = 1; i < 100; i++)
        if (histograma[i] > 0)
        {
            printf("%2d ", i);
            for (int j = 0; j < histograma[i]; j++)
                printf("%c", symbol);
            printf("\n");
        }
}
