#include <stdio.h>
int main(){
    int n;
    float x, a, basis, ergebnis;
    ergebnis = 0;
    basis = 0;//kp ob das noetig ist
    scanf("%f %f %d", &a,&x,&n);

    for ( int i = 1; i <= n ; i++)
    {
        basis = (a + 2 * i * x);
        ergebnis += basis;
    }
    printf("%.1f", ergebnis);
    return 0;
}