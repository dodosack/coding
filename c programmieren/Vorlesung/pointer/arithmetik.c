#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int zeilen 3;
const int spalten 3;
int main()
{
    int matrix[zeilen][spalten];
    // int zufallszahl = rand() % 100;
    for (int i = 0; i < zeilen; i++)
    {

        for (int j = 0; j < spalten; j++)
        {
            matrix[i][j] = rand() % 100; // zahlen zwischen 0 und 99
        }
    }

    for (int i = 0; i < zeilen; i++)
    {
        for (int j = 0; j < spalten; j++)
        {

            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    int sum_matrix(matrix);

    return 0;
}



int sum_matrix(const int matrix[zeilen], const int matrix[spalten])
{

    int total = 0;
}