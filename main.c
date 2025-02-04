#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Student {
    int id;
    char answers[10];
};

struct Result {
    int id;
    int score;
};

int main()
{
    int student_count;
    printf("Enter the number of students: ");
    scanf("%d", &student_count);

    struct Student students[student_count];
    struct Result results[student_count];
    char answer_key[10];
    int i, j;
    int correct, incorrect;

    printf("Enter the answer key (10 characters, A B C D):\n");
    for (i = 0; i < 10; i++) {
        scanf(" %c", &answer_key[i]);
    }

    printf("\nEnter student information\n");

    for (j = 0; j < student_count; j++) {
        printf("\nStudent ID: ");
        scanf("%d", &students[j].id);

        correct = 0;
        incorrect = 0;

        printf("Enter answers (10 characters, A B C D): ");
        for (i = 0; i < 10; i++) {
            scanf(" %c", &students[j].answers[i]);
            if (answer_key[i] == students[j].answers[i]) {
                correct++;
            } else {
                incorrect++;
            }
        }

        results[j].id = students[j].id;
        results[j].score = correct - (int)ceil(incorrect / 4.0);  
        if (results[j].score < 0) results[j].score = 0;

        printf("Correct: %d, Incorrect: %d, Score: %d\n", correct, incorrect, results[j].score);
    }

    printf("\nExam Results:\n");
    printf("------------------------------\n");
    printf("Student ID  |  Score\n");
    printf("------------------------------\n");

    for (j = 0; j < student_count; j++) {
        printf("%10d  |  %3d\n", results[j].id, results[j].score);
    }

    return 0;
}
