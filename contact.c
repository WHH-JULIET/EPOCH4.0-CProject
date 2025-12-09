#include <stdio.h>

struct Contact {
    char name[50];   // stores contact name
    char phone[20];  // stores contact phone number
};

int main() {
    struct Contact list[20];  // list of contacts
    int count = 0;            // number of saved contacts
    int choice;

    while (1) {
        printf("\n--- CONTACT BOOK ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add a new contact
            printf("Enter name: ");
            getchar();
            fgets(list[count].name, 50, stdin);

            printf("Enter phone: ");
            fgets(list[count].phone, 20, stdin);

            count++;
        }
        else if (choice == 2) {
            // Show all saved contacts
            printf("\nContacts:\n");
            for (int i = 0; i < count; i++) {
                printf("%s - %s", list[i].name, list[i].phone);
            }
        }
        else if (choice == 3) {
            // exit
            break;
        }
    }

    return 0;
}
