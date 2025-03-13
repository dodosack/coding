#include <stdbool.h>
#include "mymath.h"
bool isEven(int number_to_test)
{
    if (number_to_test % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}