
/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "undo_redo.h"

int get_input()
{
    int choice;
    int result;

    while (1)
    {
        printf("➡️  Enter choice: ");
        result = scanf("%d", &choice); // Read input from the user

        if (result == 1)
        {
            // Successfully read a number
            break;
        }
        else
        {
            // Invalid input, clear input buffer
            printf("❌ Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ; // Discard invalid characters
        }
    }

    return choice;
}
