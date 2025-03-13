//habe zuerst rekursiv gemacth

#include <stdio.h>
 int potenz_zwischenspeicher, zwischenspeicher;
int rechner(int *zahl_1, int *zahl_2, int *potenz);
int main(){
int zahl_1, zahl_2, potenz;
scanf("%d %d %d", &zahl_1, &zahl_2, &potenz);
int ergebnis = rechner(&zahl_1, &zahl_2, &potenz);
printf("%d", ergebnis);

return 0;
}
int rechner(int *zahl_1, int *zahl_2, int *potenz){
   
    if ((*potenz) == 0 )
    {
        return 1;
    }
    else{
        potenz_zwischenspeicher = (*potenz) - 1;

        zwischenspeicher = ((*zahl_1) + (*zahl_2));
        return zwischenspeicher * rechner(zahl_1, zahl_2, &potenz_zwischenspeicher);
    }
}