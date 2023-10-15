#include <stdio.h>

int equal(char *, char *);
int len(char *);
int count_spaces(char *);

int main(void)
{
    char *s1 = "   b   b  ", *s2 = " b b", *s3 = "    1    ";
    printf("%d\n", equal(s1, s2));
    printf("%d\n", equal(s1, s3));
    printf("%d\n", equal(s2, s3));
}

int equal(char *s1, char *s2)
{
    int l1 = len(s1) - count_spaces(s1);
    int l2 = len(s2) - count_spaces(s2);
    char m1[l1], m2[l2];
    char *s11 = s1;
    char *s22 = s2;
    int i = 0;
    while (*s11 != '\0')
    {
        if (*s11 != ' '){
            m1[i++] = *s11;   
        }
        s11++;
    }
    
    i = 0;
    while (*s22 != '\0')
    {
        if (*s22 != ' '){
            m2[i++] = *s22;   
        }
        s22++;
    }
    
    int kol = 0;
    i = 0;
    while (i++ < l1 && *m1 == *m2)
        kol++;
    if (kol == l1 && kol == l2)
        return 1;
    else    
        return 0;
}

int count_spaces(char *s)
{
    int l = 0;
    while (*s != '\0')
    {
        if (*s == ' ')
            l++;
        s++;
    }
    return l;
}

int len(char *s)
{
    int l = 0;
    while (*s++ != '\0')
    {
        l++;
    }
    return l;
}
