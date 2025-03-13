#include <stdio.h>
#include <string.h>
int palindrome(char str[]){
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end)
    {
        if (str[start]!= str[end])
        {
            return 0; /* code */
        }
        start++;
        end--;
    }
    return 1;
}

int main(){

    char arr[] = "AADAA";
    int n = strlen(arr) - 1;
    printf("%d\n", palindrome(arr));
    return 0;
}
