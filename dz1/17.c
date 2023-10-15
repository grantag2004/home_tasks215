#include <stdio.h>

void print(double *, int);
void sort(double *, int);
void swap(double *, double *);

int main(void)
{
    double X[] = {20, 19, 18, 15, 16, 17};
    int len = (sizeof X) / sizeof(double);
    sort(X, len);
    print(X, len);
}

void print(double X[], int len)
{
    int i;
    for (i = 0;i < len;i++)
        printf("%f ", X[i]);
    putchar('\n');
}

void sort(double X[], int len)
{
    int i, j;
    for (i = 1;i < len;i++)
    {
        for (j = i;j > 0 && X[j - 1] > X[j];j--)
            swap(&X[j - 1], &X[j]);
    }
}

void swap(double *n, double *m)
{
    double k = *n;
    *n = *m;
    *m = k;
}
