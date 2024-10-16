#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


int task_1()
{
    int matrixsize, line, column, determ, sumgtr, sumvtr;
    int sumgl = 0;
    int sumvt = 0;
    int matrix[4][4];
   
        printf("Input size of matrix: ");
        scanf_s("%d", &matrixsize);

        if (matrixsize <= 0) { printf("No such matrix exists"); return 0; }
        if (matrixsize == 1) { printf("The determinant of this matrix is ​​equal to the number itself"); return 0; }
        if (matrixsize > 5) { printf("This programm can't calculate this"); return 0; }
        

        printf("Input matrix size of %d:\n", matrixsize);

        for (line = 0; line < matrixsize; line++)
            for (column = 0; column < matrixsize; column++)
            {
                if (scanf_s("%d", &matrix[line][column]) != 1)
                {
                    printf("Wrong type of data!");
                    exit(1);
                }
            }
        


    if (matrixsize == 2)
    {
        for (line = 0; line < matrixsize; line++)
            for (column = 0; column < matrixsize; column++)
            {
                if (line == column)
                {
                    sumgl += matrix[line][column];
                }

                if (line + column == matrixsize - 1)
                {
                    sumvt += matrix[line][column];
                }
            }
        determ = sumgl - sumvt;
        printf("Matrix determinant size of %d = %d", matrixsize, determ);
    }

    if (matrixsize == 3)
    {
        for (line = 0; line < matrixsize; line++)
            for (column = 0; column < matrixsize; column++)
            {
                if (line == column)
                {
                    sumgl += matrix[line][column];
                }

                if (line + column == matrixsize - 1)
                {
                    sumvt += matrix[line][column];
                }

                sumgtr = matrix[0][1] + matrix[1][2] + matrix[2][0] + matrix[1][0] + matrix[2][1] + matrix[0][2];
                sumvtr = matrix[1][2] + matrix[2][1] + matrix[0][0] + matrix[1][0] + matrix[0][1] + matrix[2][2];
                determ = sumgl + sumgtr - sumvt + sumvtr;
            }

        printf("Matrix determinant size of %d = %d", matrixsize, determ);
    }
    
}

int main()
{
    while (1)
    {
        rewind(stdin);
        puts("\nTo continue task 1 press '1':");
        if (getc(stdin) == '1') 
        {
            task_1();
        }
        else
        {
            return 0;
        }
    }
}
