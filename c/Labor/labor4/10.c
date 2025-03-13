#include <stdio.h>
#include <stdbool.h> // 1 0 probieren 
bool prime(int eingabe)
{

    if (eingabe <= 1)
    {
        return false;
        
    }
    
   for ( int i = 2; i <= eingabe/2 ; i++)
   {
    
    if (eingabe % i == 0)
    {
        return false; // nach return nix mehr 
        //continue;
    }
 
   
   }
   return true;
}