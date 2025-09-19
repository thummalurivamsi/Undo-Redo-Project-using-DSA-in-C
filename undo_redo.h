#ifndef UNDO_REDO_H
#define UNDO_REDO_H

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    INSERT,
    DELETE
} ActionType;

typedef struct
{
    ActionType type;
    char *text;
    int position;
} Action;

typedef struct
{
    Stack *undoStack;
    Stack *redoStack;
    char textBuffer[1000]; // Current text content
} UndoRedo;

int get_input();
void print_menu();
UndoRedo *create_undo_redo();
void perform_action(UndoRedo *ur, ActionType type, const char *text, int position);
void undo(UndoRedo *ur);
void redo(UndoRedo *ur);
void free_undo_redo(UndoRedo *ur);
void print_current_text(UndoRedo *ur);
void print_stack(Stack *stack);
void print_undo_stack(UndoRedo *ur);
void print_redo_stack(UndoRedo *ur);

#endif
