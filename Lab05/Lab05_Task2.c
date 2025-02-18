#include "Lab05_Task2.h"
#include <stdio.h>
#include <stdlib.h>

void task_2_print(const int INT_SIZE, int i, int j, int* matrix, size_t row_size)
{
    printf("Beginning print helper...\n");
    printf("Address of matrix:");
    printf("\t%d\n", matrix);

    printf("*(matrix+i)+j:");
    printf("\t\t%d\n", matrix+i*row_size+j);

    printf("Difference of");
    printf("\t\t%d\n", i*INT_SIZE* //Break mid-line for emphasis
        4 // number of columns per row = size of second index
        +j*INT_SIZE); // return to the rest of the line

    printf("\n"); // break paragraphs
}

void task_2(const int INT_SIZE) {
    /* Given matrix starts at 0x2000, compute the address of matrix[2][1], matrix[0][3]. */
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int i = 2;
    int j = 1;
    printf("&matrix[%d][%d]:", i, j);
    printf("\t\t%d\n", &matrix[i][j]); // Two subscripts didn't work for only one "*"

    task_2_print(INT_SIZE, i, j, &matrix, 4);

    i = 0;
    j = 3;
    printf("&matrix[%d][%d]:", i, j);
    printf("\t\t%d\n", &matrix[i][j]); // Two subscripts didn't work for only one "*"
    task_2_print(INT_SIZE, i, j, &matrix, 4);
}

void task_2_just_for_fun(const int INT_SIZE) {
    /* Given matrix starts at 0x2000, compute the address of matrix[2][1], matrix[0][3]. */
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    printf("Address of matrix:");
    printf("\t\t%d\n", matrix);
    printf("matrix+1:");
    printf("\t\t\t%d\n", matrix+1);
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("&matrix[%d][%d]:", i, j); 
            printf("\t\t\t%d\n", &matrix[i][j]);

            printf("*(matrix+i)+j:");
            printf("\t\t\t%d\n", *(matrix+i)+j);

            printf("\n"); // break paragraphs
        }
    }
}

/* This breaks the linker if not commented out
int main()
{
    const int INT_SIZE = sizeof(int);
    task_2(INT_SIZE);
    return 0;
}
*/
