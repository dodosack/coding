#include <stdio.h>
int main(){

int zeile , spalte , i ;
int n , m;



scanf("%d %d", &zeile , &spalte);
printf("\n");

for ( n = 1; n <= zeile; n++)
{

if (n == zeile || n == 1)
{
    

for ( i = 1; i <= spalte; i++)
{
    if (i  <= spalte )
    {
        printf("*");
    }
    
    
}

}
else if (1 < n &&  zeile > n)
{
   for (m = 1; m <=spalte; m++)
   {
  
   
    if (m == 1 || m == spalte)
    {
        printf("*");
       
    } else {
            printf(" ");
        }
    }
  

   
}

printf("\n");
}
    return 0;

}