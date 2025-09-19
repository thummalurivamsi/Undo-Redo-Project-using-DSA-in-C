#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode
{
    void *data;
    struct StackNode *next;
} StackNode;

typedef struct
{
    StackNode *top;
} Stack;

Stack *create_stack();
void push(Stack *stack, void *data);
void *pop(Stack *stack);
void clear_stack(Stack *stack, void (*freeData)(void *));
void free_stack(Stack *stack, void (*freeData)(void *));

#endif
