#include <stdio.h>

int main()
{
  int grad = -20;
  int fahrenheit;
  printf("Celsius Fahrenheit\n");
  while (grad <= 300) // variable als erstes oder zweites?
  {
    fahrenheit = ((grad * 9) / 5) + 32;

    printf("%5d         %4d\n", grad, fahrenheit);
    grad = grad + 20;
  }

  return 0;
}