#include <stdio.h>
int find_min(int arr[]);
int find_max(int arr[]);


int main(){
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Bitte geben sie ihre %dte Zahl ein:\n", i + 1);
        scanf("%d", &arr[i]);
}
int biggest_number = find_max(arr);
int smallest_number = find_min(arr);
printf("Deine Gröste zahl ist %d und deine Kleinste %d\n", biggest_number, smallest_number);
return 0;
}

int find_min(int arr[]){

    int smallest = arr[0]; // erste zahl zu beginn die kleinste 

    for (int i = 1; i < 5; i++) // da nur 5 elemente und wir smallest arr[0] können wir von 1 bis 4 durch iterieren
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];// wenn der ein kleineres element gefunden wird dann wird smallest aktualiesirt
        }
        
    }
    return smallest;
};
int find_max(int arr[]){

    int biggest = arr[0];

    for (int  i = 1; i < 5; i++)
    {
        if (arr[i]> biggest)//grösseress geufnden
        {
            biggest = arr[i];// biggest aktualisieren 
            /* code */
        }

        }
        return biggest;
    
};