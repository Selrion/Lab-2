#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>


int funcinp(int s,int st,int matrix[16][16])
{
        printf("\n������� �������� �������� ������� � �������� [%d][%d] - ", s + 1, st + 1);

        while ((scanf_s("%d", &matrix[s][st]) != 1))
        {
            printf("\n�������� ���� ��������� ������� ������!(������� ����� �����)");
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

    printf("\n������� ������� ������� - ");
    scanf_s("%d", &p);

    if (p <= 0) { printf("����� ������� �� ����������"); return 0; }
    else if (p == 1) { printf("������������ ������ �������, ���� �����, ������� �� ����� ������"); return 0; }
    else if (p > 5) { printf("��������� ���������� �� ������� ������������� ������ �� ���� 5 �������"); return 0; }
    

    if (p > 0)
    {
        for (s = 0; s < p; s++)
            for (st = 0; st < p; st++)
            {
                /*printf("������� �������� �������� ������� � �������� [%d][%d] - ", s + 1, st + 1);
                scanf_s("%d", &matrix[s][st]);*/
                funcinp(s, st, matrix);
                
  
            }
        printf("���������� �������\n");
        
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
                        sumgl += matrix[s][st]; // ������� ���������
                    }

                    if (s + st == p - 1)
                    {
                        sumvt += matrix[s][st]; //�������������� ���������
                    }

                    sumgtr = matrix[0][1] + matrix[1][2] + matrix[2][0] + matrix[1][0] + matrix[2][1] + matrix[0][2];
                    sumvtr = matrix[1][2] + matrix[2][1] + matrix[0][0] + matrix[1][0] + matrix[0][1] + matrix[2][2];
                    determ = sumgl + sumgtr - sumvt + sumvtr;
                }

            printf("������������ �������� ������� %d ������� ����� - %d", p, determ);
        }

        if (p == 2)
        {
            for (s = 0; s < p; s++)
                for (st = 0; st < p; st++)
                {
                    if (s == st)
                    {
                        sumgl += matrix[s][st]; // ������� ���������
                    }

                    if (s + st == p - 1)
                    {
                        sumvt += matrix[s][st]; //�������������� ���������
                    }
                }
            determ = sumgl - sumvt;
            printf("������������ �������� ������� %d ������� ����� - %d", p, determ);
        }

    }


    return 0;
}
