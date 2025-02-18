#include <stdlib.h>
#include "Lab05_Task2.c"
#include "Lab05_Task1.c"

int main() {
    printf("Task 1: One-Dimensional Fixed-Size Array\n");
    const int INT_SIZE = sizeof(int);
    task_1(INT_SIZE);

    printf("\nTask 2: Two-Dimensional Fixed-Size  Array\n");
    task_2(INT_SIZE);

    printf("\nTask 3: ");

    return 0;
}