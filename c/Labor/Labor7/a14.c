#include<stdio.h>
int main (){

    int array[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &array[i]);

    }
    for (int i = 0; i < 4; i++)
    {
        /* code */
    printf("%d ", array[i]);
    }
    array[2] = 42;
    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        /* code */
    printf("%d ", array[i]);
    }
    return 0;
}