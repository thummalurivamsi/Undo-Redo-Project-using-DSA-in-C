/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "undo_redo.h"

// Helper function to free Action
void free_action(void *data)
{
    Action *action = (Action *)data;
    free(action->text);
    free(action);
}

UndoRedo *create_undo_redo()
{
    UndoRedo *ur = (UndoRedo *)malloc(sizeof(UndoRedo));
    ur->undoStack = create_stack();
    ur->redoStack = create_stack();
    ur->textBuffer[0] = '\0'; // empty initial text
    return ur;
}

void apply_action(UndoRedo *ur, Action *action, int reverse)
{
    if (action->type == INSERT)
    {
        if (reverse)
        {
            // Remove inserted text
            ur->textBuffer[strlen(ur->textBuffer) - strlen(action->text)] = '\0';
        }
        else
        {
            strcat(ur->textBuffer, action->text);
        }
    }
    else if (action->type == DELETE)
    {
        if (reverse)
        {
            strcat(ur->textBuffer, action->text);
        }
        else
        {
            int len = strlen(ur->textBuffer);
            ur->textBuffer[len - strlen(action->text)] = '\0';
        }
    }
}

void perform_action(UndoRedo *ur, ActionType type, const char *text, int position)
{
    Action *action = (Action *)malloc(sizeof(Action));
    action->type = type;
    action->text = strdup(text);
    action->position = position;

    apply_action(ur, action, 0); // apply normally
    push(ur->undoStack, action);
    clear_stack(ur->redoStack, free_action);

    printf("✅ Action performed\n");
    print_current_text(ur);
}

void undo(UndoRedo *ur)
{
    Action *action = (Action *)pop(ur->undoStack);
    if (!action)
    {
        printf("Nothing to undo!\n");
        return;
    }
    apply_action(ur, action, 1); // reverse
    push(ur->redoStack, action);
    printf("✅ Undo completed\n");
    print_current_text(ur);
}

void redo(UndoRedo *ur)
{
    Action *action = (Action *)pop(ur->redoStack);
    if (!action)
    {
        printf("Nothing to redo!\n");
        return;
    }
    apply_action(ur, action, 0); // normal
    push(ur->undoStack, action);
    printf("✅ Redo completed\n");
    print_current_text(ur);
}

void free_undo_redo(UndoRedo *ur)
{
    free_stack(ur->undoStack, free_action);
    free_stack(ur->redoStack, free_action);
    free(ur);
}

void print_current_text(UndoRedo *ur)
{
    printf("👉 Current Text: \"%s\"\n", ur->textBuffer);
}

// Print all actions in the stack
void print_stack(Stack *stack)
{
    StackNode *node = stack->top;
    int index = 0;
    if (!node)
    {
        printf("Empty!\n");
        return;
    }
    while (node)
    {
        Action *action = (Action *)node->data;
        printf("%d: %s \"%s\" at position %d\n", index,
               action->type == INSERT ? "Insert" : "Delete",
               action->text, action->position);
        node = node->next;
        index++;
    }
}

// Print undo stack
void print_undo_stack(UndoRedo *ur)
{
    printf("👉 Undo Stack:\n");
    print_stack(ur->undoStack);
}

// Print redo stack
void print_redo_stack(UndoRedo *ur)
{
    printf("👉 Redo Stack:\n");
    print_stack(ur->redoStack);
}