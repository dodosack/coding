#include <stdio.h>

int minimum( int *array_numbers,int lanege){

    int minimum_zahl;
     minimum_zahl = array_numbers[0];
    for ( int i = 1; i < lanege; i++)
    {
        if (array_numbers[i] < minimum_zahl)
        {
            minimum_zahl = array_numbers[i];
        }
        
    }
    return minimum_zahl;
  }


  