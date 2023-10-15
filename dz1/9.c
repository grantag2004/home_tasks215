#include <stdio.h>

void change(char *, char **);
int len(char *);
void print(char *);

int main(void)
{
    char s[] = "1faf3dsfdas", *t = "gbgbgbgb";
    printf("%s\n", s);
    printf("%s\n", t);
    change(s, (char **)&t);
    print(t);
}

void print(char *s)
{
    while (*s != '\0'){
        printf("%c", *s);
        s++;
    }
    putchar('\n');
}

void change(char *s, char **t)
{
    int l_q = len(s) + len((char *)*t);    
    char q[l_q];
    char *ss = s;
    int i = 0;
    while (*ss != '\0'){
        if (*ss >= '0' && *ss <= '9')
            q[i++] = *ss;
        ss++;
    }
    char *tt = *t;
    while (*tt != '\0'){
        q[i++] = *tt;
        tt++;
    }
    while (*s != '\0'){
        if (!(*s >= '0' && *s <= '9'))
            q[i++] = *s;
        s++;
    }    
    *t = (char *)q;
}

int len(char *s)
{
    int l = 0;
    while (*s++ != '\0'){
        l++;
    }
    return l;
}
