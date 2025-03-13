#include <stdio.h>
void append(char *zeichenkette1, char *zeichenkette2)
{
while (*zeichenkette1 != '\0')
{
    zeichenkette1++;//der startwert von 1 ist somit der nullterminator

}
while (*zeichenkette2 != 0)//jetzt 2 bis null terminator laufen lassen 
{
    *zeichenkette1 = *zeichenkette2;
    zeichenkette1++;
    zeichenkette2++;//gemeinsam bis null terminator 
}
*zeichenkette1 = '\0'; // nullterminat0r setzen 


}

int main(){


char buffer[40] = "Hallo ";
append(buffer, "Welt");
printf("%s\n", buffer);

    return 0;
}