/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "undo_redo.h"

int main()
{
    UndoRedo *ur = create_undo_redo();
    int choice;
    char input[100];

    while (1)
    {
        // Display menu
        print_menu();

        choice = get_input();

        switch (choice)
        {
        case 1:
            printf("Enter text to insert: ");
            while (getchar() != '\n')
                ; // Clear input buffer
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = 0; // Remove trailing newline
            perform_action(ur, INSERT, input, strlen(ur->textBuffer));
            break;

        case 2:
            printf("Enter number of characters to delete from end: ");
            while (getchar() != '\n')
                ; // Clear input buffer
            fgets(input, 100, stdin);
            int count = atoi(input);
            int len = strlen(ur->textBuffer);

            if (count <= 0 || count > len)
            {
                printf("Invalid number of characters!\n");
            }
            else
            {
                char deleted[100];
                strcpy(deleted, ur->textBuffer + len - count);
                perform_action(ur, DELETE, deleted, len - count);
            }
            break;

        case 3:
            undo(ur);
            break;

        case 4:
            redo(ur);
            break;

        case 5:
            print_undo_stack(ur);
            break;

        case 6:
            print_redo_stack(ur);
            break;

        case 7:
            // free and exit
            free_undo_redo(ur);
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Please enter a number between 1 and 7\n");
            break;
        }
    }

    return 0;
}

void print_menu()
{
    printf("\n╔══════════════════════════╗\n");
    printf("      UNDO / REDO SYSTEM      \n");
    printf("╚══════════════════════════╝\n\n");

    printf("╔════╦════════════════════╗\n");
    printf("║ No ║ Option             ║\n");
    printf("╠════╬════════════════════╣\n");
    printf("║ 1  ║ Insert text        ║\n");
    printf("║ 2  ║ Delete text        ║\n");
    printf("║ 3  ║ Undo               ║\n");
    printf("║ 4  ║ Redo               ║\n");
    printf("║ 5  ║ Show Undo List     ║\n");
    printf("║ 6  ║ Show Redo List     ║\n");
    printf("║ 7  ║ Exit               ║\n");
    printf("╚════╩════════════════════╝\n");
}
