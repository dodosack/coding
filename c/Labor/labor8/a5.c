#include <stdio.h>
void rechner(float *x, float *a, int *n, float *ergebnis);
int main(){
    int n;
    float x, a, ergebnis;
    ergebnis = 0;
   // basis = 0;//kp ob das noetig ist
    scanf("%f %f %d", &a,&x,&n);
    rechner(&x, &a, &n, &ergebnis);
    printf("%.1f\n", ergebnis);
    return 0;
}


void rechner(float *x, float *a, int *n, float *ergebnis){
    if ((*n) == 0) {
        return; // Basisfall: n erreicht 0
    }
    
    float basis = ((*a) + 2 * (*n) * (*x));
    *ergebnis += basis; 
    (*n)--;
    rechner(x, a, n, ergebnis); // Rekursiver Aufruf mit reduziertem n
}
