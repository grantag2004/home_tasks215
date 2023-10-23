#include <stdio.h>
#include <stdlib.h>

struct data 
{
    double f;
    char *s[2];
};

struct lnode 
{
    struct data *p;
    struct lnode *next;
};

void push(struct lnode *, int, char *, char *);
void copy(struct lnode *, struct lnode *);
void print(struct lnode *);

int main()
{
    struct lnode *L1, *L2;
    L1 = (struct lnode *) malloc(sizeof(struct data));
    L1 -> p -> s = (char *) calloc(2, sizeof(char));
    L1 -> next = NULL;
    
    L2 = (struct lnode *) malloc(sizeof(struct data));
    L2 -> p -> s = (char *) calloc(2, sizeof(char));
    L2 -> next = NULL;
    
    push(L1, 5, "abcd", "123");
    push(L1, 2, "dd", "1010");
    push(L1, 0, "trh", "777");
    print(L1);
    copy(L1, L2);
    print(L2);
    
    return 0;
}

void print(struct lnode *L)
{
    while (L != NULL)
    {
        printf("%f %s %s \n", L -> p -> f, (L -> p -> s)[0], (L -> p -> s)[1]);
        L = L -> next;
    }
}

void push(struct lnode *L, int f, char *s1, char *s2)
{
    if (L -> next == NULL)
    {
        L -> p -> f = f;
        (L -> p -> s)[0] = s1;
        (L -> p -> s)[1] = s2;
        L -> next = (struct lnode *) malloc(sizeof(struct data));
        L -> p -> s = (char *) calloc(2, sizeof(char));
        L -> next = NULL;
    }
    else
    {
        while (L -> next != NULL)
            L = L -> next;
        L -> p -> f = f;
        (L -> p -> s)[0] = s1;
        (L -> p -> s)[1] = s2;
        L -> next = (struct lnode *) malloc(sizeof(struct data));
        L -> p -> s = (char *) calloc(2, sizeof(char));
        L -> next = NULL;        
    }
}

void copy(struct lnode *L1, struct lnode *L2)
{
    while (L1 != NULL)
    {
        push(L2, L1 -> p -> f, (L1 -> p -> s)[0], (L1 -> p -> s)[1]);
        L1 = L1 -> next;
    }
}
