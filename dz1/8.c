#include <stdio.h>

char *strstr_(char *, char *);
int len(char *);

int main(void)
{
    char *s1 = "abbcbbaa", *s2 = "bb";
    char *s;
    while ((s = strstr_(s1, s2)) != NULL)
        s1 = s + len(s2);
    printf("%s\n", s1);
}

/*find s2 in s1*/
char *strstr_(char *s1, char *s2)
{
    int l1 = len(s1), l2 = len(s2);
    int i, j, z;
    for (i = 0; i <= len(s1) - len(s2);i++)
    {
        int kol = 0;
        z = 0;
        for (j = i;j < i + len(s2);j++)
            if (s1[j] == s2[z++])
                kol++;
        if (kol == len(s2)){
            return &s1[i];
        }
    }
    return NULL;
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
