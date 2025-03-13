#include <stdio.h>

int main()
{

    int fahrenheit;
    float grad;
    printf("Fahrenheit      Celsius\n");

    for (fahrenheit = -20; fahrenheit <= 300; fahrenheit += 20)
    {
        grad = 5 * ((fahrenheit - 32) / 9.00);
        printf("%10d %12.2f\n", fahrenheit, grad);
    }

    return 0;
}