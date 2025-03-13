#include <stdio.h>
int main(){
    char char1 = 'a';
    char arraay[] = "niggas";

    char *p_char1;
    p_char1 = &char1;
    char *p_array = arraay;
    
    printf("%c %p\n", *p_array,p_array );
   // p_array++;
    printf("%c %p", *(p_array +1), p_array+1);

    return 0;
}