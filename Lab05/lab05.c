#include <stdlib.h>
#include "Lab05_Task1.c"
#include "Lab05_Task2.c"
#include "Lab05_Task3.c"
#include "Lab05_Task4.c"

void print_bold(char* sentence, char* bold_color, char* reset_color)
{
    printf("%s", bold_color);
    printf("%s", sentence);
    printf("%s", reset_color);
}

int main() {
    char* bold_color = "\033[1;30m";
    char* reset_color = "\033[0m";
    print_bold("Task 1: One-Dimensional Fixed-Size Array\n", bold_color, reset_color);
    const int INT_SIZE = sizeof(int);
    task_1(INT_SIZE);

    print_bold("\nTask 2: Two-Dimensional Fixed-Size  Array\n", bold_color, reset_color);
    task_2(INT_SIZE);

    print_bold("\nTask 3: Two-Level Jagged Array\n", bold_color, reset_color);
    task_3(INT_SIZE);

    const int CHAR_SIZE = sizeof(char);
    const int SHORT_SIZE = sizeof(short);
    const int DOUBLE_SIZE = sizeof(double);
    print_bold("\nTask 4: Structure with Mixed Field Sizes and Alignment Impact\n", bold_color, reset_color);
    task_4(INT_SIZE, CHAR_SIZE, SHORT_SIZE, DOUBLE_SIZE);
    
    return 0;
}