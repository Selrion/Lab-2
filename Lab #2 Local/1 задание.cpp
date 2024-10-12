#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



int main()
{
    int e = 0;
    int matrixsize,line,column;
    int matrix[4][4];


    printf("Input size of matrix: ");
    scanf_s("%d",&matrixsize);
    
    printf("\nEnter matrix size of %d:\n ", matrixsize);

    for (line = 0; line < matrixsize; line++)
        for (column = 0; column < matrixsize; column++)
        {
            try
            {
            }
            catch ()
            {
            }
        }

    for (line = 0; line < matrixsize; line++)
    {
        for (column = 0; column < matrixsize; column++)
        {
            printf("%d ", matrix[line][column]);
        }
        printf("\n");
    }
    return 0;

}
