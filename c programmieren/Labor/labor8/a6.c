#include <stdio.h>

void capital_letter(char string[20], char *ergebnis, int *index);
int main()
{
    char ergebnis;
    int index = 0;
    char string[20]= {'\0'};// geht nicht 
    scanf("%19s", string);

    capital_letter(string, &ergebnis, &index);

    printf("%c", ergebnis);
    return 0;
}

void capital_letter(char string[20], char *ergebnis, int *index)
{

    if (string[(*index)] >= 'A' && string[(*index)] <= 'Z')
    {
        // Gossbuchstabe
        *ergebnis = string[(*index)];
        return;
    }

    else
    {*ergebnis = ' ';
        if (string[(*index)] != '\0' )// weil danach noch plus 1 gemacht wird 
        {
            /* code */ (*index)++;
        capital_letter(string, ergebnis, index);
        }
        
      else{
          return;
      }  
       
    }
}