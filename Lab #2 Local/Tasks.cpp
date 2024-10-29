#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


int task_1()
{
    int matrixsize, line, column;
    double determ, sumgtr, sumvtr;
    int b = 1;
    double sumgl = 1;
    double sumvt = 1;
    double matrix[4][4];

   while(b)
   {
       printf("\nInput size of matrix: ");

       if (scanf_s("%d", &matrixsize) == 0) { rewind(stdin); printf("Wrong type of data!"); return 0; }
       else if (matrixsize == 0) {rewind(stdin); printf("\nNo such matrix exists");}
       else if (matrixsize < 0)  {rewind(stdin); printf("\nNo such matrix exists");}
       else if (matrixsize == 1) {rewind(stdin); printf("The determinant of this matrix equals itself"); return 0; }
       else if (matrixsize > 4)  {rewind(stdin); printf("This programm can't calculate this"); return 0;}
       else {printf("\nInput matrix with size of %d:\n", matrixsize);}

       for (line = 0; line < matrixsize; line++)
       {
           for (column = 0; column < matrixsize; column++)
           {
               if (scanf_s("%lf", &matrix[line][column]) != 1)
               {
                   b = 0;
               }
           }
       }

       if (b == 0)
       {
           rewind(stdin);
           printf("\nWrong type of data!");
       }



       if ((matrixsize == 2) && (b != 0))
       {
           for (line = 0; line < matrixsize; line++)
               for (column = 0; column < matrixsize; column++)
               {
                   if (line == column)
                   {
                       sumgl *= matrix[line][column];
                   }

                   if (line + column == matrixsize - 1)
                   {
                       sumvt *= matrix[line][column];
                   }
               }
           determ = sumgl - sumvt;
           printf("\nMatrix determinant size of %d = %.0lf", matrixsize, determ);

           printf("\nContinue - 1 \nExit - 0\n \nEnter: ");
           scanf_s("%d", &b);

           switch (b)
           {
           case 1:
           {
               b = 1;
               break;
           }
           case 0:
           {
               b = 0;
               break;
           }
           default:
               rewind(stdin);
               printf("Wrong type of data! Exiting...");
               b = 0;
               break;
           }
       }


       if ((matrixsize == 3) && (b != 0))
       {
           for (line = 0; line < matrixsize; line++)
               for (column = 0; column < matrixsize; column++)
               {
                   if (line == column)
                   {
                       sumgl *= matrix[line][column];
                   }

                   if (line + column == matrixsize - 1)
                   {
                       sumvt *= matrix[line][column];
                   }

                   sumgtr = matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[1][0] * matrix[2][1] * matrix[0][2];
                   sumvtr = matrix[1][2] * matrix[2][1] * matrix[0][0] + matrix[1][0] * matrix[0][1] * matrix[2][2];
                   determ = sumgl + sumgtr - sumvt - sumvtr;
               }

           printf("Matrix determinant size of %d = %.0lf", matrixsize, determ);
           
           printf("\nContinue - 1 \nExit - 0\n \nEnter: ");
           scanf_s("%d", &b);
           
           switch (b)
           {
           case 1:
           {
               b = 1;
               break;
           }
           case 0:
           {
               b = 0;
               break;
           }
           default:
               rewind(stdin);
               printf("Wrong type of data! Exiting...");
               b = 0;
               break;
           }
       }

   }
   return 0;

}

int task_2()

{
    char str[100][100];
    int symbols = 0;
    int c = 1;
    int i,j,n;
    
    while (c)
    {
        printf("Enter count of strings: ");

        if (scanf_s("%d", &n) == 0) {rewind(stdin); printf("Wrong type of data!"); return 0; }
        else if (n == 0) {rewind(stdin); printf("Please input number over 0"); return 0; }

        
            printf("\nEnter strings with enter`s: ");
            for (i = 0; i < n; i++)
            {
                scanf_s("%s", &str[i], 100);
            }
        
        
        
            printf("\nStrings with repeats: ");

            for (i = 0; i < n; i++)
            {
                int len = strlen(str[i]);
                for (j = 0; j < len - 1; j++)
                {
                    if (str[i][j] == str[i][j + 1])
                    {
                        printf("\n%s\n", str[i]);
                        break;
                    }
                }
            }
        
        
    
       
            printf("\nContinue - 1 \nExit - 0\n \nEnter: ");
            scanf_s("%d", &c);
            switch (c)
            {
            case 1:
            {
                c = 1;
                break;
            }
            case 0:
            {
                c = 0;
                break;
            }
            default:
                rewind(stdin);
                printf("Wrong type of data! Exiting...");
                c = 0;
                break;
            }

    }
    
    return 0;
}

int main()
{
    
    while (1)
    {
        fflush(stdin);
        fflush(stdout);
        int ts;
        char tasks[] = 
            "\n"
            "\nPlease choose a task:"
            "\n"
            "\nTask 1 - '1'"
            "\nTask 2 - '2'"
            "\nExit - '0'"
            "\n"
            "\nEnter: ";
        printf("%s",tasks);
        scanf_s("%d",&ts);

        switch(ts)
        {
        case 1:
        {
            task_1();
            break;
        }
        case 2:
        {
            task_2();
            break;
        }
        case 0:
        {
            return 0;
            break;
        }
        default:
            rewind(stdin);
            printf("\nWrong type of data!");
            break;
        }
    }
}
