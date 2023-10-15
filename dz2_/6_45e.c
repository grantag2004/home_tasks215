#include <stdio.h>
#include <stdlib.h>

typedef struct derevo{
    int elem;
    struct derevo *left;
    struct derevo *right;
} Tree;

void add(Tree **, int);
int count_elem(Tree *, int, int);

int main(void)
{
    Tree *t = NULL;
    add(&t, 5);
    add(&t, 2);
    add(&t, 1);
    add(&t, 6);
    printf("%d\n", count_elem(t, 0, 2));/*Print count of elements on level 2*/
    return 0;
}

void add(Tree **t, int x)
{
    if (*t == NULL)
    {
        Tree *q = (Tree *) malloc(sizeof(Tree));
        q -> elem = x;
        q -> left = NULL;
        q -> right = NULL;
        *t = q;
    }
    else
    {
        Tree *q = *t;
        if (x >= q -> elem)
            add(&(q -> right), x);
        else
            add(&(q -> left), x);
    }
}

int count_elem(Tree *t, int level_current, int level)
{
    int k = 0;
    if (t == NULL)
        return 0;
    else if (level_current == level)
        return 1;
    else
    {
        k += count_elem(t -> left, level_current + 1, level);
        k += count_elem(t -> right, level_current + 1, level);
    }
    return k;
    /*return (level_current > 0) ? 0:k;*/
}
