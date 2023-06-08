/* imprime la tabla Fahrenheit-Celsius para fahr = 300, 280 ... 0 */
#include <stdio.h>

#define LOWER 0   /* límite inferior */
#define UPPER 300 /* límite superior */
#define STEP 20   /* tamaño del decrecimiento (en este caso) */

int main(void)
{
    printf("Fahrenh\tCelsius\n"); // impresión del encabezado

    for (float fahr = UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%3.0f\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}