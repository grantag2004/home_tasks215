#include <stdio.h>
#include <string.h>
#define MAX 10

void first(char **);
void second(char **);
void third(char **);
void print_3symb(char *);
void print(char *);
int len(char *);

int main(void)
{
    char *mas[MAX] = {"abdsf", "213begin3513", "123", "434253626626262", NULL};
    first((char **)&mas);/*mas - указатель на первый элемент => *mas - первый элемент <=> указатель на первый символ строки*/
    second((char **)mas);
    third((char **)mas);
}

void first(char **mas)
{
    char **massive = mas;
    char *m = *massive;
    while (*massive != NULL)
    {
       print_3symb((char *) m);
       (massive)++;
       m = *massive;
    }
}

void print_3symb(char *s)
{
    printf("%c ", *s++);
    printf("%c ", *s++);
    printf("%c\n", *s);
}

void second(char **mas)
{
    char **massive = mas;
    int max_len = 0;
    char *max_str = NULL;
    while (*massive != NULL)
    {
        if (len(*massive) >= max_len){
            max_len = len(*massive);
            max_str = *massive;
        }
        massive++;
    }
    print(max_str);
}

void third(char **mas)
{
    char **massive = mas;
    char *s = "begin";
    int i = 0;
    while (*massive != NULL)
    {
        if (strstr(*massive, s) != NULL)
            printf("%s\n", *massive);
        massive++;
    }
}


void print(char *s)
{
    while (*s != '\0'){
        printf("%c ", *s);
        s++;
    }
    putchar('\n');
}

int len(char *s)
{
    int l = 0;
    while (*s++ != '\0'){
        l++;    
    }
    return l;
}
