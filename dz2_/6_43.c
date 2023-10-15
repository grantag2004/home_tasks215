#include <stdio.h>
#include <stdlib.h>

typedef struct spisok {
    int elem;
    struct spisok *next;
} stack;

void print(stack *);
int is_empty(stack *);
void push(stack **, int);
int pop(stack **);
int size(stack *);

int main(void)
{
    stack *q = NULL;
    if (is_empty(q))
        printf("Empty\n");
    else
        printf("Not empty\n");
        
    push(&q, 3);
    push(&q, 5);
    push(&q, 1);
    print(q);
    printf("Size of stack = %d\n", size(q));
    
    printf("%d\n", pop(&q));
    print(q);
    printf("Size of stack = %d\n", size(q));
    
}

void print(stack *q)
{
    if (is_empty(q))
        printf("Stack is empty");
    else
    {
        while (q != NULL)
        {
            printf("%d ", q -> elem);
            q = q -> next;
        }
        putchar('\n');
    }
}

int is_empty(stack *q)
{
    if (q == NULL)
        return 1;
    else
        return 0;
}

void push(stack **q, int x)
{
    if (*q == NULL)
    {
        stack *qq = (stack *) malloc(sizeof(stack));
        qq -> elem = x;
        qq -> next = NULL;
        *q = qq;
    }
    else
    {
        stack *qq = *q;
        while (qq -> next != NULL)
            qq = qq -> next;
        stack *tail = (stack *) malloc(sizeof(stack));
        tail -> elem = x;
        tail -> next = NULL;
        qq -> next = tail;
    }
}

int pop(stack **q)
{
    if (is_empty(*q))
        printf("Stack is empty");
    else
    {
        if ((*q) -> next == NULL)
        {
            int tail_elem = (*q) -> elem;
            *q = NULL;
            free(*q);
            return tail_elem;
        }
        else
        {
            stack *p = *q;
            while (p -> next -> next != NULL)
                p = p -> next;
            int tail_elem = p -> next -> elem;
            free(p -> next);
            p -> next = NULL;
            return tail_elem;
        }
    }
}

int size(stack *q)
{
    int len = 0;
    while (q != NULL)
    {
        len ++;
        q = q -> next;
    }  
    return len;
}

