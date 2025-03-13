#include <stdio.h>
#include<stdlib.h>


struct Rechenwerte
{
    float z1;
    float z2;
    float z3;
    float z4;
}value1;



int main(){

//eingabe
scanf("%f/%f", &value1.z1, &value1.z2);
scanf("%f/%f", &value1.z3, &value1.z4);

//verarbeitung
float zaehler_multi, zaehler_division, nenner_multi, nenner_division;
zaehler_multi = value1.z1 * value1.z3;
nenner_multi = value1.z2 * value1.z4;
zaehler_division = value1.z1 * value1.z4;
nenner_division = value1.z2 * value1.z3;

//ausgabe
printf("(%.1f/%.1f)*(%.1f/%.1f)=(%.1f/%.1f)\n", value1.z1, value1.z2, value1.z3, value1.z4, zaehler_multi, nenner_multi);

printf("(%.1f/%.1f)/(%.1f/%.1f)=(%.1f/%.1f)", value1.z1, value1.z2, value1.z3, value1.z4, zaehler_division, nenner_division);

return EXIT_SUCCESS;
}