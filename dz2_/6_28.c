#include <stdio.h>
#include <stdlib.h>

typedef struct spisok {
    int elem;
    struct spisok *next;
} node;

void print(node *);
void push_left(node **, int);
void push_right(node **, int);
void change_first_last(node *);
void delete_first(node **, int);
void delete_all(node **, int);
void dublicate(node **, int);

int main()
{
    node *head = NULL;
    push_right(&head, 4);
    push_right(&head, 2);
    push_right(&head, 6);
    push_right(&head, 1);
    
    
    print(head);
    change_first_last(head);
    print(head);
    
    
    delete_first(&head, 2);
    print(head);
    
    
    push_right(&head, 6);
    push_right(&head, 10);
    print(head);
    delete_all(&head, 6);
    print(head);
    
    push_right(&head, 4);
    dublicate(&head, 4);
    print(head);
    
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
                printf("%d ", member -> elem);
                member = member -> next;
            }
        putchar('\n');
}

/*add new node in head*/
void push_left(node **head, int x)
{
    node *member = (node *) malloc(sizeof(node));
    member -> elem = x;
    member -> next = *head;
    *head = member;
}

/*add new node in the end*/
void push_right(node **head, int x)
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

void change_first_last(node *head)
{
    if ((head != NULL) && ((head -> next != NULL)))
    {
        node *member = head;
        while (member -> next != NULL)
            member = member -> next;
        int tmp = head -> elem;
        head -> elem = member -> elem;
        member -> elem = tmp;
    }
}

void delete_first(node **head, int x)
{
    node *member = *head;
    if (member != NULL)
    {
        if (((member -> elem) == x) && ((member -> next) == NULL)){
            *head = NULL;
	    free(*head);
	}
        else if (((member -> elem) == x) && ((member -> next) != NULL)){
	    node *p = *head;
            *head = member -> next;
	    free(p);
	}
        else
            while (member != NULL)
                {
                    if ((member -> next != NULL) && (member -> next -> elem == x))
                        {
			    node *p = member -> next;
                            member -> next = member -> next -> next;
			    free(p);
                            exit;
                        }
                    member = member -> next;
                }
    }
}

void delete_all(node **head, int x)
{
    node *member = *head;
    if (member != NULL)
    {
        if (((member -> elem) == x) && ((member -> next) == NULL)){
            *head = NULL;
	    free(*head);
        }
        else if (((member -> elem) == x) && ((member -> next) != NULL)){
            node *p = *head;
            *head = member -> next;
            free(p);
        }
        else
            while (member != NULL)
                {
                    if ((member -> next != NULL) && (member -> next -> elem == x))
                        {
			    node *p = member -> next;
                            member -> next = member -> next -> next;
			    free(p);
                        }
                    member = member -> next;
                }
    }
}

void dublicate(node **head, int x)
{
    node *member = *head;
    if (member != NULL) 
    {
        while (member != NULL)
        {
            if (member -> elem == x)
            {
                node *p = (node *) malloc(sizeof(node));
                p -> elem = x;
                p -> next = member -> next;
                member -> next = p;
                member = member -> next -> next;
            }
            else
                member = member -> next;
        }
    }
}
