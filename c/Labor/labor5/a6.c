#include <stdio.h>
int main (){
    int start_index = 0;
    int end_index = 0;
    char eingabe[41];
    scanf("%40s %d %d", eingabe,&start_index,&end_index);
    printf("%s %d-%d: ", eingabe, start_index, end_index);

    for (; start_index <= end_index; start_index++)
    {
        printf("%c",eingabe[start_index]);
    }
    
    

    return 0;
}