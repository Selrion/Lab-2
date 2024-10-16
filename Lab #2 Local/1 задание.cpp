#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


int task_1()
{
    int matrixsize, line, column, determ, sumgtr, sumvtr;
    int b = 1;
    int sumgl = 0;
    int sumvt = 0;
    int matrix[4][4];
   while(b)
   {
       printf("\nInput size of matrix: ");

       if (scanf_s("%d", &matrixsize) != 1) { rewind(stdin); printf("Wrong type of data!"); }
       else if (matrixsize <= 0) { rewind(stdin); printf("\nNo such matrix exists");  }
       else if (matrixsize == 1) { rewind(stdin); printf("The determinant of this matrix is ​​equal to the number itself");  }
       else if (matrixsize > 4) { rewind(stdin); printf("This programm can't calculate this");  } // fix!
       else { printf("\nInput matrix with size of %d:\n", matrixsize); }

       for (line = 0; line < matrixsize; line++)
       {
           for (column = 0; column < matrixsize; column++)
           {
               int n = scanf_s("%d", &matrix[line][column]);
               if (n != 1)
               {
                   b = 0;
               }
           }
       }
       if (b == 0)
       {
           printf("\nWrong type of data!");
       }



       if ((matrixsize == 2) && (b != 0))
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
           printf("\nMatrix determinant size of %d = %d", matrixsize, determ);

           printf("\nFor continue press 1, for exit 0 - ");
           scanf_s("%d", &b);
       }



       if ((matrixsize == 3) && (b != 0))
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

           printf("\nFor continue press 1, for exit 0 - ");
           scanf_s("%d", &b);
       }

   }
   return 0;

}

int main()
{
    while (1)
    {
        rewind(stdin);
        rewind(stdout);
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
