//habe zuerst rekursiv gemacth

#include <stdio.h>
 
int rechner(int *zahl_1, int *zahl_2, int *potenz);
int main(){
int zahl_1, zahl_2, potenz;
scanf("%d %d %d", &zahl_1, &zahl_2, &potenz);
int ergebnis = rechner(&zahl_1, &zahl_2, &potenz);
printf("%d", ergebnis);

return 0;
}
int rechner(int *zahl_1, int *zahl_2, int *potenz){
 int  zwischenspeicher = 1;
 int basis = (*zahl_1) + (*zahl_2);
 for (int i = 0; i < (*potenz); i++)
 {
     zwischenspeicher*=(basis);
    }

    return zwischenspeicher;
}