#include<stdio.h>
int main (){
    int i;
    int *ptr;
    int **ptrptr;
    ptr = &i;
    ptrptr = &ptr;
    **ptrptr = 1;
    printf("%d\n", i);
    printf("%d\n", *ptr);
    **ptrptr = 2;
        printf("%d", **ptrptr);
    return 0;
}