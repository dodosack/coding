#include <stdio.h>
int main()
{
    char eingabe[40];
    scanf("%39s", eingabe);
    int index = 0;

    for (; eingabe[index] != '\0'; index++) // besser mit while machen weil erst erhöt und dann erst geprüft wird
    {
    }
    

    for (; index - 1 >= 0; index--)

    {
        printf("%c",eingabe[index-1]);//ohen minus eins wied nullterminator ausgegebn

   }
   
   
    return 0;
}