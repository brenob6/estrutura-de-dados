#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
  void *data;
  struct node *next;
} node;

typedef struct stack {
  node *top;
  size_t nelems;
  int width;

} stack;

void * stack_create(int width);
void stack_push(stack *s, const void *data);
bool stack_pop(stack *s, void *addr);
void stack_destroy(stack *s);
