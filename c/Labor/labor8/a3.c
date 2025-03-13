#include <stdio.h>
int faculty(int *zahl);
int input(int *eingabe);

int main()
{

    int eingabe;
    
    // printf("%d\n", eingabe);
    eingabe = input(&eingabe);
    int neu;

    neu = faculty(&eingabe);

    printf("%d! = %d\n",eingabe, neu);


    return 0;
}


int faculty(int *zahl){

    if (*zahl ==  0|| *zahl == 1)
    {
        return 1;
    }

    else{
        int zwischen_speicher = (*zahl) - 1;
        return (*zahl)*(faculty(&zwischen_speicher));
    }
}  

int input(int *eingabe){

scanf("%3d", eingabe);
return *eingabe;
}