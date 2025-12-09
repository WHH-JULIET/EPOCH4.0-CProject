#include <stdio.h>

struct Student {
    char name[50];  // student name
    int roll;       // student roll number
};

int main() {
    struct Student s[20];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- STUDENT MANAGEMENT SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add student details
            printf("Enter name: ");
            getchar();
            fgets(s[count].name, 50, stdin);

            printf("Enter roll number: ");
            scanf("%d", &s[count].roll);

            count++;
        }
        else if (choice == 2) {
            // Show all students
            for (int i = 0; i < count; i++) {
                printf("%s - Roll %d\n", s[i].name, s[i].roll);
            }
        }
        else if (choice == 3) {
            break;
        }
    }

    return 0;
}
