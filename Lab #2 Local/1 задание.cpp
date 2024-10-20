#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


int task_1()
{
    int matrixsize, line, column;
    double determ, sumgtr, sumvtr;
    int b = 1;
    int sumgl = 1;
    int sumvt = 1;
    double matrix[4][4];

   while(b)
   {
       printf("\nInput size of matrix: ");

       if (scanf_s("%d", &matrixsize) != 1) { printf("Wrong type of data!"); return 0;}
       else if (matrixsize == 0) { rewind(stdin); printf("\nNo such matrix exists");}
       else if (matrixsize < 0)  { rewind(stdin); printf("\nNo such matrix exists");}
       else if (matrixsize == 1) {printf("The determinant of this matrix equals itself"); return 0; }
       else if (matrixsize > 4)  {printf("This programm can't calculate this"); return 0;} 
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

           printf("\nFor continue - 1, for exit - 0:  ");
           scanf_s("%d", &b);
       }

   }
   return 0;

}

int task_2()

{
    char text[1000];
    int c = 1;
    while (c)
    {
        printf("\nInput text:\n");

        rewind(stdin);
        fgets(text, sizeof(text), stdin);
        
        int length = strlen(text);

        printf("Strings with repeats:\n");

        for (int i = 0; i < length - 1; i++)
        {
            if (text[i] == text[i + 1])
            {
                int start = i;

                while (text[i] == text[i + 1])
                {
                    i++;
                }

                int end = i;
                
                for (int j = start; j <= end; j++)
                {
                    printf("%c", text[j]);
                }
              
                printf("\n");
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
            printf("\nWrong type of data!");
            break;
        }
    }
}
