#include <stdio.h>
int faculty(int *zahl);
int main()
{

    int eingabe;
    scanf("%3d", &eingabe);
    // printf("%d\n", eingabe);
    int neu = faculty(&eingabe);
    printf("%d\n", neu);


    return 0;
}

int faculty(int *zahl){
    int zwischen_speicher;
    if (*zahl ==  0|| *zahl == 1)
    {
        return 1;
    }

    else{
        int zwischen_speicher = (*zahl) - 1;
        return (*zahl)*(faculty(&zwischen_speicher));
    }
}  