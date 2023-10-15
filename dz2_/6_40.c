#include <stdio.h>
#include <stdlib.h>

typedef struct spisok {
    char elem;
    struct spisok *next;
} node;

void print(node *);
void push_left(node **, char);
void push_right(node **, char);
void create(node *, node *, node **);

int main()
{
    node *L1 = NULL;
    node *L2 = NULL;
    node *L3 = NULL;
    
    push_right(&L1, '4');
    push_right(&L1, '2');
    push_right(&L1, '6');
    push_right(&L1, '1');
    print(L1);
    
    push_right(&L2, '9');
    push_right(&L2, '4');
    push_right(&L2, '5');
    push_right(&L2, '2');
    print(L2);   
    
    create(L1, L2, &L3);
    print(L3);

    
    return 0;
}

void print(node *head)
{
    node *member = head;
    if (member == NULL)
        printf("Empty");
    else
        while (member != NULL)
            {
                printf("%c ", member -> elem);
                member = member -> next;
            }
        putchar('\n');
}

/*add new node in head*/
void push_left(node **head, char x)
{
    node *member = (node *) malloc(sizeof(node));
    member -> elem = x;
    member -> next = *head;
    *head = member;
}

/*add new node in the end*/
void push_right(node **head, char x)
{
    node *member = (node *) malloc(sizeof(node));
    member -> elem = x;
    member -> next = NULL;
    if (*head != NULL)
        {
            node *p = *head;
            while (p -> next != NULL)
                p = p -> next;
            p -> next = member; 
        }
    else
        {
            *head = member;
        }
}

void create(node *L1, node *L2, node **L3)
{
    node *L11 = L1, *L22 = L2;
    *L3 = NULL;
    if (L1 == NULL)
    {
        if (L2 != NULL)
        {
            node *L33 = (node *) malloc(sizeof(node));
            L33 -> elem = L22 -> elem;
            L33 -> next = NULL;
            *L3 = L33;
            L22 = L22 -> next;
        }
        node *L33 = *L3;
        while (L22 != NULL)
        {
            node *p = (node *) malloc(sizeof(node));
            p -> elem = L22 -> elem;
            p -> next = NULL;
            L33 -> next = p;
            L33 = L33 -> next;
            L22 = L22 -> next;    
        }
    }
    
    if (L2 == NULL)
    {
        if (L1 != NULL)
        {
            node *L33 = (node *) malloc(sizeof(node));
            L33 -> elem = L11 -> elem;
            L33 -> next = NULL;
            *L3 = L33;
            L11 = L11 -> next;
        }
        node *L33 = *L3;
        while (L11 != NULL)
        {
            node *p = (node *) malloc(sizeof(node));
            p -> elem = L11 -> elem;
            p -> next = NULL;
            L33 -> next = p;
            L33 = L33 -> next;
            L11 = L11 -> next;    
        }
    }
    
    while (L11 != NULL)
    {
        L22 = L2;
        while ((L22 != NULL) && (L11 -> elem != L22 -> elem))
            L22 = L22 -> next;
        if (L22 == NULL)
        {
            push_right(L3, L11 -> elem);
        }
        L11 = L11 -> next;
    }
    L11 = L1;
    L22 = L2;
    
    while (L22 != NULL)
    {
        L11 = L1;
        while ((L11 != NULL) && (L11 -> elem != L22 -> elem))
            L11 = L11 -> next;
        if (L11 == NULL)
        {
            push_right(L3, L22 -> elem);
        }
        L22 = L22 -> next;
    }

}
