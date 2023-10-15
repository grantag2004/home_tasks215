#include <stdio.h>
#include <stdlib.h>

typedef struct Inode{
    struct data *p;
    struct Inode *next;
} spisok;

struct data{
    double f;
    char *s[2];/*массив из 2 элементов, каждый из которых - указатель на символ*/
};

void print(spisok *);
void push(spisok **, double, char *);
void copy(spisok *, spisok **);

int main(void)
{
    spisok *L2 = NULL;
    spisok *L1 = NULL;
    
    push(&L1, 3.5, "12");
    push(&L1, 4.0, "ab");
    push(&L1, 10.2, "!#");
    print(L1);
    copy(L1, &L2);
    print(L2);
    
}

void print(spisok *L)
{
    if (L == NULL)
        printf("Empty");
    else
        {
            while (L != NULL)
            {
                printf("%f %s", L -> p -> f, (char *)(L -> p -> s));    
                L = L -> next;
            }
            putchar('\n');
        }
}

void push(spisok **L, double x, char *ss)
{
    char *ss1, *ss2;
    ss1 = ss;
    ss2 = ++ss;
    char *s[2] = {ss1, ss2};
    if (*L == NULL)
    {
        spisok *member = (spisok *) malloc(sizeof(spisok));
        member -> p -> f = x;
        (member -> p -> s)[0] = s[0];
        (member -> p -> s)[1] = s[1];
        member -> next = NULL;
        *L = member;
    }
    else
        {
            spisok *member = (spisok *) malloc(sizeof(spisok));
            member -> p -> f = x;
            (member -> p -> s)[0] = s[0];
            (member -> p -> s)[1] = s[1];
            member -> next = NULL;
            spisok *dublic = *L;
            while (dublic -> next != NULL)
                dublic = dublic -> next;
            dublic -> next = member;
        }
}

void copy(spisok *L1, spisok **L2)
{
    if (L1 = NULL)
        *L2 = NULL;
    else
        {
            spisok *member = (spisok *) malloc(sizeof(spisok));
            member -> next = L1 -> next;
            member -> p -> f = L1 -> p -> f;
            (member -> p -> s)[0] = (L1 -> p -> s)[0];
            (member -> p -> s)[1] = (L1 -> p -> s)[1];
            *L2 = member;
            
            while (L1 != NULL)
            {
                spisok *member = (spisok *) malloc(sizeof(spisok));
                member -> next = L1 -> next;
                member -> p -> f = L1 -> p -> f;
                (member -> p -> s)[0] = (L1 -> p -> s)[0];
                (member -> p -> s)[1] = (L1 -> p -> s)[1];
                L1 = L1 -> next;
            }
        }
}
