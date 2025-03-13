#include <stdio.h>
#include <string.h>

void reverse(char arr[]);


int main (
){
    char arr[100];
    printf("Bitte zeichenkette eingeben ohne leerzeichen und max 100 zeichen!!\n");
    scanf("%99s", arr);

    reverse(arr);

    return 0;
}

void reverse(char arr[]){

   // int lenght = strlen(arr);

   int lenght = 0;
while (arr[lenght] != '\0')
{
    lenght++;
}

   

   printf("laenge betragt %d\n", lenght);

   for (int i = lenght - 1; i >= 0; i--)
   {
       printf("%c", arr[i]);
    }
    
};
