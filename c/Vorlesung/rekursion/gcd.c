#include <stdio.h>

int gcd_rekursiv(int a, int b);
int gcd_iterativ(int a, int b);

int main() {
    int a, b;
    printf("Geben Sie zwei Zahlen ein: ");
    scanf("%d %d", &a, &b);

    printf("GCD (Rekursiv): %d\n", gcd_rekursiv(a, b));
    printf("GCD (Iterativ): %d\n", gcd_iterativ(a, b));

    return 0;
}

int gcd_rekursiv(int a, int b) {
    if (b == 0){ return a;}
    return gcd_rekursiv(b, a % b);
}

int gcd_iterativ(int a, int b) {
    while (b != 0) {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}
