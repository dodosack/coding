#include <stdio.h>



int main () {

int zeile , spalte;
int i ,  j , n ;


scanf("%i  %i" , &zeile, &spalte);

    for ( i = 1; i <= zeile; i++)
    {
       if (i % 2 != 0 ) //ungeradezeile
       {
       for (n = 1; n <= spalte ; n++)
       { if (n % 2 != 0 )
       {
        printf("+");/* code */
       }
       
        else{
      printf("-");
        }
       }
       
       }

    else{
for (j = 1; j <= spalte ; j++)
       {

    if (j % 2 == 0)
    {
       printf("+");
    }
    else{
     printf("-"); }
       
       }
    }   
    
    printf("\n");
    }
    
    return 0;

} 