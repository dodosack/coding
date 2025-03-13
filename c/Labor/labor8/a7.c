#include <stdio.h>
#include <stdbool.h>
#include <math.h> // für sqrtl
bool is_prime(int *eingabe, int *teiler);
int main()
{

    int eingabe;
    scanf("%d", &eingabe);
    int teiler = sqrtl(eingabe);
    printf("%d", is_prime(&eingabe, &teiler));
    return 0;
}//anschauen
bool is_prime(int *eingabe, int *teiler)
{

    if (  (*eingabe) <= 1) //  zahl und 0  und 1
    {
        return false;
    }
    else if ((*eingabe) == 2)
    {
        return true;
    }
    
    else
    {
        if ((*teiler) == 0) // muss nur bis 2 prüfen// erfolgreich geprüft  
        {
            return true;
        }

        else
        {
            if ((*eingabe) % (*teiler) == 0)
            {
                return false;
            }

            *teiler = (*teiler) - 1;
          return  is_prime((eingabe), teiler);
        }
    }
}