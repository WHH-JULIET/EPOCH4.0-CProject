#include <stdio.h>

struct Expense {
    char name[50];    // name of expense
    float amount;     // money spent
};

int main() {
    struct Expense exp[20];
    int count = 0;
    float total = 0;  // total expense value
    int choice;

    while (1) {
        printf("\n--- EXPENSE TRACKER ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. View Total\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add new expense
            printf("Enter name: ");
            getchar();
            fgets(exp[count].name, 50, stdin);

            printf("Enter amount: ");
            scanf("%f", &exp[count].amount);

            total += exp[count].amount;
            count++;
        }
        else if (choice == 2) {
            // Show all expenses
            for (int i = 0; i < count; i++) {
                printf("%s - %.2f\n", exp[i].name, exp[i].amount);
            }
        }
        else if (choice == 3) {
            // Show total spent so far
            printf("Total Expense: %.2f\n", total);
        }
        else if (choice == 4) {
            break;
        }
    }

    return 0;
}
