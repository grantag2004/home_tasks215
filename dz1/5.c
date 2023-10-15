#include <stdio.h>

void change_sign(double *, int);
void print(double *, int);

int main(void)
{
    double X[] = {1, 3, -3, 2, -10, 1, 3};
    int len = sizeof X / sizeof(double);
    change_sign(X, len);
    print(X, len);
    return 0;
}

void change_sign(double *m, int len)
{
    for (int i = 0;i < len;i++)
        if (m[i] < 0)
            m[i] = -m[i];
}

void print(double *m, int len)
{
    for (int i = 0;i < len;i++)
        printf("%f ", m[i]);
    putchar('\n');
}




