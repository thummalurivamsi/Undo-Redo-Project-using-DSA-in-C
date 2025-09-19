/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/
#include "stack.h"

Stack *create_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, void *data)
{
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

void *pop(Stack *stack)
{
    if (!stack->top)
        return NULL;
    StackNode *node = stack->top;
    stack->top = node->next;
    void *data = node->data;
    free(node);
    return data;
}

void clear_stack(Stack *stack, void (*freeData)(void *))
{
    while (stack->top)
    {
        StackNode *node = stack->top;
        stack->top = node->next;
        if (freeData)
            freeData(node->data);
        free(node);
    }
}

void free_stack(Stack *stack, void (*freeData)(void *))
{
    clear_stack(stack, freeData);
    free(stack);
}
