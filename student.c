#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50
#define MAX_COURSE 30
#define FILENAME "students.txt"

struct Student {
    int id;
    char name[MAX_NAME];
    int roll;
    char course[MAX_COURSE];
    float gpa;
    int age;
    char email[50];
};

// Function prototypes
void displayMenu();
int getChoice();
void addStudent(struct Student *students, int *count);
void viewStudents(struct Student *students, int count);
void editStudent(struct Student *students, int count);
void removeStudent(struct Student *students, int *count);
void searchStudent(struct Student *students, int count);
void sortStudents(struct Student *students, int count);
void saveToFile(struct Student *students, int count);
int loadFromFile(struct Student *students);
void clearInputBuffer();
int validateRoll(int roll);
int validateGPA(float gpa);
void removeNewline(char *str);
void displayStudentDetails(struct Student student);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // Load existing data
    count = loadFromFile(students);
    printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
    printf("Loaded %d existing students.\n", count);

    while (1) {
        displayMenu();
        choice = getChoice();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                editStudent(students, count);
                break;
            case 4:
                removeStudent(students, &count);
                break;
            case 5:
                searchStudent(students, count);
                break;
            case 6:
                sortStudents(students, count);
                break;
            case 7:
                saveToFile(students, count);
                printf("\nData saved successfully!\n");
                break;
            case 8:
                saveToFile(students, count);
                printf("\nGoodbye! Data saved automatically.\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\n==========================================\n");
    printf("        STUDENT MANAGEMENT SYSTEM        \n");
    printf("==========================================\n");
    printf("1. Add New Student\n");
    printf("2. View All Students\n");
    printf("3. Edit Student\n");
    printf("4. Remove Student\n");
    printf("5. Search Students\n");
    printf("6. Sort Students\n");
    printf("7. Save Data\n");
    printf("8. Exit\n");
    printf("==========================================\n");
    printf("Enter your choice (1-8): ");
}

int getChoice() {
    int choice;
    while (scanf("%d", &choice) != 1) {
        printf("Invalid input! Please enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return choice;
}

void addStudent(struct Student *students, int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nMaximum student limit reached!\n");
        return;
    }

    struct Student newStudent;
    newStudent.id = *count + 1;

    printf("\n--- ADD NEW STUDENT ---\n");
    
    printf("Enter student name: ");
    fgets(newStudent.name, MAX_NAME, stdin);
    removeNewline(newStudent.name);
    
    do {
        printf("Enter roll number: ");
        scanf("%d", &newStudent.roll);
        clearInputBuffer();
    } while (!validateRoll(newStudent.roll));
    
    printf("Enter course: ");
    fgets(newStudent.course, MAX_COURSE, stdin);
    removeNewline(newStudent.course);
    
    do {
        printf("Enter GPA (0.0-4.0): ");
        scanf("%f", &newStudent.gpa);
        clearInputBuffer();
    } while (!validateGPA(newStudent.gpa));
    
    printf("Enter age: ");
    scanf("%d", &newStudent.age);
    clearInputBuffer();
    
    printf("Enter email: ");
    fgets(newStudent.email, 50, stdin);
    removeNewline(newStudent.email);
    
    students[*count] = newStudent;
    (*count)++;
    
    printf("\nStudent added successfully!\n");
}

void viewStudents(struct Student *students, int count) {
    if (count == 0) {
        printf("\nNo students recorded yet.\n");
        return;
    }
    
    printf("\n==========================================\n");
    printf("              ALL STUDENTS               \n");
    printf("==========================================\n");
    printf("ID | Name               | Roll | Course        | GPA  | Age | Email\n");
    printf("---|--------------------|----- |---------------|------|-----|------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-2d | %-18s | %-4d | %-13s | %.2f | %-3d | %s\n", 
               students[i].id, students[i].name, students[i].roll, 
               students[i].course, students[i].gpa, students[i].age, students[i].email);
    }
    printf("==========================================\n");
    printf("Total Students: %d\n", count);
}

void editStudent(struct Student *students, int count) {
    if (count == 0) {
        printf("\nNo students to edit.\n");
        return;
    }
    
    int id;
    printf("\nEnter student ID to edit: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\n--- EDITING STUDENT ID %d ---\n", id);
            displayStudentDetails(students[i]);
            
            printf("\nEnter new name: ");
            fgets(students[i].name, MAX_NAME, stdin);
            removeNewline(students[i].name);
            
            do {
                printf("Enter new roll number: ");
                scanf("%d", &students[i].roll);
                clearInputBuffer();
            } while (!validateRoll(students[i].roll));
            
            printf("Enter new course: ");
            fgets(students[i].course, MAX_COURSE, stdin);
            removeNewline(students[i].course);
            
            do {
                printf("Enter new GPA (0.0-4.0): ");
                scanf("%f", &students[i].gpa);
                clearInputBuffer();
            } while (!validateGPA(students[i].gpa));
            
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            clearInputBuffer();
            
            printf("Enter new email: ");
            fgets(students[i].email, 50, stdin);
            removeNewline(students[i].email);
            
            printf("\nStudent updated successfully!\n");
            return;
        }
    }
    printf("\nStudent ID not found!\n");
}

void removeStudent(struct Student *students, int *count) {
    if (*count == 0) {
        printf("\nNo students to remove.\n");
        return;
    }
    
    int id;
    printf("\nEnter student ID to remove: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            printf("\nRemoving: %s (Roll: %d)\n", students[i].name, students[i].roll);
            
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("\nStudent removed successfully!\n");
            return;
        }
    }
    printf("\nStudent ID not found!\n");
}

void searchStudent(struct Student *students, int count) {
    if (count == 0) {
        printf("\nNo students to search.\n");
        return;
    }
    
    char search[MAX_NAME];
    printf("\nEnter name or course to search: ");
    fgets(search, MAX_NAME, stdin);
    removeNewline(search);
    
    printf("\n--- SEARCH RESULTS ---\n");
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strstr(students[i].name, search) || strstr(students[i].course, search)) {
            displayStudentDetails(students[i]);
            printf("\n");
            found++;
        }
    }
    
    if (!found) {
        printf("No matching students found.\n");
    } else {
        printf("Found %d matching student(s).\n", found);
    }
}

void sortStudents(struct Student *students, int count) {
    if (count == 0) {
        printf("\nNo students to sort.\n");
        return;
    }
    
    printf("\nSort by: 1) Name 2) Roll Number 3) GPA 4) Age\n");
    printf("Enter choice: ");
    int choice = getChoice();
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int swap = 0;
            
            switch (choice) {
                case 1: // Sort by name
                    if (strcmp(students[j].name, students[j + 1].name) > 0) swap = 1;
                    break;
                case 2: // Sort by roll number
                    if (students[j].roll > students[j + 1].roll) swap = 1;
                    break;
                case 3: // Sort by GPA (descending)
                    if (students[j].gpa < students[j + 1].gpa) swap = 1;
                    break;
                case 4: // Sort by age
                    if (students[j].age > students[j + 1].age) swap = 1;
                    break;
            }
            
            if (swap) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    printf("\nStudents sorted successfully!\n");
    viewStudents(students, count);
}

void saveToFile(struct Student *students, int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("\nError saving to file!\n");
        return;
    }
    
    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d|%s|%d|%s|%.2f|%d|%s\n", 
                students[i].id, students[i].name, students[i].roll, 
                students[i].course, students[i].gpa, students[i].age, students[i].email);
    }
    
    fclose(file);
}

int loadFromFile(struct Student *students) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        return 0; // No file exists yet
    }
    
    int count;
    fscanf(file, "%d\n", &count);
    
    for (int i = 0; i < count; i++) {
        fscanf(file, "%d|%49[^|]|%d|%29[^|]|%f|%d|%49[^\n]\n", 
               &students[i].id, students[i].name, &students[i].roll, 
               students[i].course, &students[i].gpa, &students[i].age, students[i].email);
    }
    
    fclose(file);
    return count;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validateRoll(int roll) {
    if (roll <= 0) {
        printf("Roll number must be positive! Try again.\n");
        return 0;
    }
    return 1;
}

int validateGPA(float gpa) {
    if (gpa < 0.0 || gpa > 4.0) {
        printf("GPA must be between 0.0 and 4.0! Try again.\n");
        return 0;
    }
    return 1;
}

void removeNewline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

void displayStudentDetails(struct Student student) {
    printf("ID: %d | Name: %s | Roll: %d | Course: %s | GPA: %.2f | Age: %d | Email: %s", 
           student.id, student.name, student.roll, student.course, 
           student.gpa, student.age, student.email);
}
