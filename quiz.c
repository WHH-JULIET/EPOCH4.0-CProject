#include <stdio.h>

int main() {
    int answer;     // stores user answer
    int score = 0;  // stores score

    printf("=== QUIZ GAME ===\n");

    // Question 1
    printf("\n1) What is 2 + 2?\n");
    printf("1) 3\n2) 4\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 2) score++;

    // Question 2
    printf("\n2) What is the capital of India?\n");
    printf("1) Delhi\n2) Mumbai\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 1) score++;

    // Final result
    printf("\nYour Score: %d/2\n", score);

    return 0;
}
