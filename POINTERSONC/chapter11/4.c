#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int     value;
    struct  node    *p_next;
}node;

int main(void)
{
    node    head;
    node    *node1 = malloc( sizeof( struct node ) );
    node    *node2 = malloc( sizeof( struct node ) );
    node    *node3 = malloc( sizeof( struct node ) );

    node1->value = 5;
    node1->p_next = node2;

    node2->value = 10;
    node2->p_next = node3;

    node3->value = 15;
    node3->p_next = NULL;

    head = *node1;

    printf("%d\n", head.p_next->p_next->value );

    return 0;
}
