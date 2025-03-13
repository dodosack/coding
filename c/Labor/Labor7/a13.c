#include <stdio.h>
int main (){
    int eingabe[4];
for (int i = 0; i < 4; i++)
{
    
    scanf("%d", &eingabe[i]);

}
float summe = 0;
for (int i = 0; i < 4; i++)
{
    summe += eingabe[i];
}

printf("Summe: %.0f\n",summe);
printf("Durchschnitt: %f",summe/4.0);

return 0;
}