#include <stdio.h>
#include <stdlib.h>

typedef struct spisok {
    int elem;
    struct spisok *next;
} queue;

void print(queue *);
int is_empty(queue *);
void push(queue **, int);
int pop(queue **);
int size(queue *);

int main(void)
{
    queue *q = NULL;
    if (is_empty(q))
        printf("Empty\n");
    else
        printf("Not empty\n");
        
    push(&q, 3);
    push(&q, 5);
    push(&q, 1);
    print(q);
    printf("Size of queue = %d\n", size(q));
    
    printf("%d\n", pop(&q));
    print(q);
    
}

void print(queue *q)
{
    if (is_empty(q))
        printf("Queue is empty");
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

int is_empty(queue *q)
{
    if (q == NULL)
        return 1;
    else
        return 0;
}

void push(queue **q, int x)
{
    if (*q == NULL)
    {
        queue *qq = (queue *) malloc(sizeof(queue));
        qq -> elem = x;
        qq -> next = NULL;
        *q = qq;
    }
    else
    {
        queue *qq = *q;
        while (qq -> next != NULL)
            qq = qq -> next;
        queue *tail = (queue *) malloc(sizeof(queue));
        tail -> elem = x;
        tail -> next = NULL;
        qq -> next = tail;
    }
}

int pop(queue **q)
{
    if (is_empty(*q))
        printf("Queue is empty");
    else
    {
        queue *head = *q;
        *q = (*q) -> next;
        int head_elem = head -> elem;
        free(head);
        return head_elem;
    }
}

int size(queue *q)
{
    int len = 0;
    while (q != NULL)
    {
        len ++;
        q = q -> next;
    }  
    return len;
}

