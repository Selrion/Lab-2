#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>


int funcinp(int s,int st,int matrix[16][16])
{
        printf("\nВведите значение элемента матрицы с индексом [%d][%d] - ", s + 1, st + 1);

        while ((scanf_s("%d", &matrix[s][st]) != 1))
        {
            printf("\nНеверный ввод повторите попытку заново!(Вводите целые числа)");
            printf("\n");
            exit(1);
        }

    return (int (matrix));
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int s, st, p, determ;
    int sumgl = 0;
    int sumvt = 0;
    int sumgtr = 0;
    int sumvtr = 0;
    int n = 0;
    int matrix[16][16];

    printf("\nВведите порядок матрицы - ");
    scanf_s("%d", &p);

    if (p <= 0) { printf("Такой матрицы не существует"); return 0; }
    else if (p == 1) { printf("Определитель данной матрицы, само число, подсчет не имеет смысла"); return 0; }
    else if (p > 5) { printf("Программа рассчитана на подсчет определителей матриц не выше 5 порядка"); return 0; }
    

    if (p > 0)
    {
        for (s = 0; s < p; s++)
            for (st = 0; st < p; st++)
            {
                /*printf("Введите значение элемента матрицы с индексом [%d][%d] - ", s + 1, st + 1);
                scanf_s("%d", &matrix[s][st]);*/
                funcinp(s, st, matrix);
                
  
            }
        printf("Полученная матрица\n");
        
        printf("|\n");
        printf("V\n");


        for (s = 0; s < p; s++)
        {
            for (st = 0; st < p; st++)
            {
                printf("%d ", matrix[s][st]);
            }
            printf("\n");
        }


        if (p == 3)
        {
            for (s = 0; s < p; s++)
                for (st = 0; st < p; st++)
                {
                    if (s == st)
                    {
                        sumgl += matrix[s][st]; // главная диагональ
                    }

                    if (s + st == p - 1)
                    {
                        sumvt += matrix[s][st]; //второстепенная диагональ
                    }

                    sumgtr = matrix[0][1] + matrix[1][2] + matrix[2][0] + matrix[1][0] + matrix[2][1] + matrix[0][2];
                    sumvtr = matrix[1][2] + matrix[2][1] + matrix[0][0] + matrix[1][0] + matrix[0][1] + matrix[2][2];
                    determ = sumgl + sumgtr - sumvt + sumvtr;
                }

            printf("Определитель введённой матрицы %d порядка равен - %d", p, determ);
        }

        if (p == 2)
        {
            for (s = 0; s < p; s++)
                for (st = 0; st < p; st++)
                {
                    if (s == st)
                    {
                        sumgl += matrix[s][st]; // главная диагональ
                    }

                    if (s + st == p - 1)
                    {
                        sumvt += matrix[s][st]; //второстепенная диагональ
                    }
                }
            determ = sumgl - sumvt;
            printf("Определитель введённой матрицы %d порядка равен - %d", p, determ);
        }

    }


    return 0;
}
