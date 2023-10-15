#include <stdio.h>
#define M 2
#define N 2
#define K 2

void input(int x, int y, int matrix[x][y]);
void output(int x, int y, int matrix[x][y]);
void multiplication(int matrix1[M][N], int matrix2[N][K], int matrix[M][K]);

int main(void)
{
    int matrix1[M][N], matrix2[N][K], matrix[M][K];
    input(M, N, matrix1);
    input(N, K, matrix2);
    output(M, N, matrix1);
    output(N, K, matrix2);
    multiplication(matrix1, matrix2, matrix);
    output(M, K, matrix);
}

void input(int x, int y, int matrix[x][y])
{
    for (int i = 0;i < x;i++)
        for (int j = 0;j < y;j++)
            scanf("%d", &matrix[i][j]);
}

void output(int x, int y, int matrix[x][y])
{
    for (int i = 0;i < x;i++)
    {
        for (int j = 0;j < y;j++)
            printf("%d ", matrix[i][j]);
        putchar('\n');
    }
}

void multiplication(int matrix1[M][N], int matrix2[N][K], int matrix[M][K])
{
    for (int i = 0;i < M;i++)
        for (int j = 0;j < K;j++)
        {
            int sum = 0;
            for (int z = 0;z < N;z++)
                sum += matrix1[i][z] * matrix2[z][j];
            matrix[i][j] = sum;
        }
}


