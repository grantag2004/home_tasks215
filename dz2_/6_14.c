#include <stdio.h>
#include <math.h>
struct point{
    int x;
    int y;
};

struct point_with_color{
    int x;
    int y;
    char *color;
};

struct complex{
    int R;/*вещественна часть комплексного числа*/
    int I;/*мнимая часть числа*/
};

struct rational{
    int p;/*числитель*/
    int q;/*знаменатель*/
};

main(void)
{
    return 0;
}

/*Функции для структуры point*/
struct point make_point(int x, int y)
{
    struct point q;
    q.x = x;
    q.y = y;
    return q;
}

double distance_from_start(int x, int y)
{
    double sqrt(double);
    return sqrt(x * x + y * y);
}

double distance_between_two_points(int x1, int y1, int x2, int y2)
{
    double sqrt(double);
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

/*Функции для структуры point_with_color*/
struct point_with_color make_point_with_color(int x, int y, char *color)
{
    struct point_with_color q;
    q.x = x;
    q.y = y;
    q.color = color;
    return q;
}

/*Функции для структуры complex*/
struct complex make_complex(int R, int I)
{
    struct complex q;
    q.R = R;
    q.I = I;
    return q;    
}

struct complex sum_complex(int R1, int I1, int R2, int I2)
{
    struct complex q;
    q.R = R1 + R2;
    q.I = I1 + I2;
    return q;
}

struct complex subtraction_complex(int R1, int I1, int R2, int I2)
{
    struct complex q;
    q.R = R1 - R2;
    q.I = I1 - I2;
    return q;
}

struct complex multiplication_complex(int R1, int I1, int R2, int I2)
{
    struct complex q;
    q.R = R1 * R2 - I1*I2;
    q.I = R1 * I2 + R2 * I1;
    return q;
}

/*Функции для структуры rational*/
struct rational make_rational(int p, int q)
{
    struct rational dr;
    dr.p = p;
    dr.q = q;
    return dr;    
}

int NOD(int n1, int n2)
{
    if (n1 == 0)
        return n2;
    if (n2 == 0)
        return n2;
    if (n1 >= n2)
        n1 %= n2;
    else
        n2 %= n1;
    return NOD(n1, n2);
}

struct rational addition_rational(int p1, int q1, int p2, int q2)
{
    struct rational dr;
    dr.p = p1 * q2 + p2 * q1;
    dr.q = q1 * q2;
    if (NOD(dr.p, dr.q) != 1)
    {
        dr.p /= NOD(dr.p, dr.q);
        dr.q /= NOD(dr.p, dr.q);
    }
    return dr;
}

struct rational subtraction_rational(int p1, int q1, int p2, int q2)
{
    struct rational dr;
    dr.p = p1 * q2 - p2 * q1;
    dr.q = q1 * q2;
    if (NOD(dr.p, dr.q) != 1)
    {
        dr.p /= NOD(dr.p, dr.q);
        dr.q /= NOD(dr.p, dr.q);
    }
    return dr;
}

struct rational multiplication_rational(int p1, int q1, int p2, int q2)
{
    struct rational dr;
    dr.p = p1 * p2;
    dr.q = q1 * q2;
    if (NOD(dr.p, dr.q) != 1)
    {
        dr.p /= NOD(dr.p, dr.q);
        dr.q /= NOD(dr.p, dr.q);
    }
    return dr;
}
