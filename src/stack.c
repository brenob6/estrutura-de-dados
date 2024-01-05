#include "../inc/stack.h"
#include <string.h>
#include <stdlib.h>

void * stack_create(int width)
{
    stack *s = malloc(sizeof(stack));
    s->width = width;
    s->top = NULL;
    s->nelems = 0;
    return s;
}

void stack_push(stack *s, const void *data)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = malloc(s->width);
    memcpy(new_node->data, data, s->width);
    new_node->next = s->top;
    s->top = new_node;
    s->nelems++;
}

bool stack_pop(stack *s, void * addr)
{
    if(s->nelems == 0) return false;
    memcpy(addr, s->top->data, s->width);
    free(s->top->data);
    free(s->top);
    s->nelems--;
    return true;
}

void stack_destroy(stack *s)
{
    while(s->top != NULL)
    {
        node *aux = s->top->next; 
        free(s->top->data);
        free(s->top);
        s->top = aux;
    }
    free(s);
}
