#include <stdio.h>

void  swap(int *ptr_a,int *ptr_b);
int main(){

    int var_a = 10;
   char  var_b = 'A';
    void *ptr;

    ptr = &var_a;
    printf("%d", *(int*)ptr);// type cast 

    return 0;
}


void swap(int *ptr_a,int *ptr_b){

    int tmp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = tmp;

    
}