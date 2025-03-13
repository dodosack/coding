#include <stdio.h>


    int kleinstezahl(int num1, int num2)
    {

        int ausgabe;
        if (num1 < num2)
        {
            ausgabe = num1;
        }
        else
        {
            ausgabe = num2;
        }
        return ausgabe;
    }

    int z = kleinstezahl(4, 8);
    return 0;

