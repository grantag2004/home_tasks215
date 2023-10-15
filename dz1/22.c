#include <stdio.h>
#define MAXLEN 100
void sdvig(double *, int, double m[]);
void print(double *, int);

int main(void)
{
    double mas[] = {1, 2, 3, 4, 5, 6};
    int len = (sizeof mas) / sizeof(double);
    double m[len];
    sdvig(mas, len, m);
    print(m, len);
}

void print(double *mas, int len)
{
    int i;
    for (i = 0; i <= len - 1;i++)
    {
        printf("%f ", *mas);
        mas++;
    }
    putchar('\n');
}

void sdvig(double *mas, int len, double m[])
{
    if (len >= 20)
    {
        int i;
        int ind;
        for (i = 0;i < len;i++)
        {
            if (i >= 0 && i <= 19)
                ind = len - (20 - i);
            else
                ind = i - 20;
            m[ind] = *mas;
            mas++;
        }
    }
    else
    {
        int k = 20 % len;
        int i;
        int ind;
        for (i = 0;i < len;i++)
        {
            if (i >= 0 && i <= k - 1)
                ind = len - (k - i);
            else
                ind = i - k;
            m[ind] = *mas;
            mas++;
        }
    }
}
