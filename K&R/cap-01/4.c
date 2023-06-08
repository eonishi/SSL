#include <stdio.h>

/* imprime la tabla Fahrenheit-Celsius para fahr = 0, 20, ..., 300 */

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* límite inferior de la tabla de temperaturas */
    upper = 300; /* límite superior */
    step = 20;   /* tamaño del incremento */

    
    printf("Celsius\tFarenehit\n"); // impresión del encabezado

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%6.1f\t%3.0f\n", celsius, fahr);
        fahr = fahr + step;
    }
}