#include <stdio.h>

int main() {
    char tasks[20][100];   // Stores up to 20 tasks of max 100 characters
    int count = 0;         // Number of tasks added
    int choice;            // Menu choice variable

    while (1) {
        // Simple menu
        printf("\n--- TO-DO LIST ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add a new task
            printf("Enter task: ");
            getchar(); // clears leftover newline
            fgets(tasks[count], 100, stdin);
            count++;
        }
        else if (choice == 2) {
            // Display all tasks
            printf("\nYour Tasks:\n");
            for (int i = 0; i < count; i++) {
                printf("%d. %s", i + 1, tasks[i]);
            }
        }
        else if (choice == 3) {
            // Exit program
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
