#include <stdio.h>

int main()
{
    int blankSeguidos = 0;

    for (int c = getchar(); c != EOF; c = getchar())
        if (c == ' ')
        {
            ++blankSeguidos;
            if (blankSeguidos == 1)
                putchar(c);
        }
        else
        {
            blankSeguidos = 0;
            putchar(c);
        }
}