#include <stdio.h>
#include <stdlib.h>

void task_2_print(const int INT_SIZE, int i, int j, int* matrix)
{
    printf("Address of matrix:");
    printf("\t%d\n", matrix);

    printf("*(matrix+i)+j:");
    printf("\t\t%d\n", *(matrix+i)+j);

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
    // Figuring out 2d pointers was a pain, so I decided against a dedicated print function.
    // I think I'll just copy-paste the print statements instead.
    // It's a pain, but I just don't know why the compiler doesn't understand "**"
    printf("Address of matrix:");
    printf("\t%d\n", matrix);
    
    printf("&matrix[%d][%d]:", i, j); 
    printf("\t\t%d\n", &matrix[i][j]);

    printf("*(matrix+i)+j:");
    printf("\t\t%d\n", *(matrix+i)+j);

    printf("Difference of");
    printf("\t\t%d\n", i*INT_SIZE*
        4 // number of columns per row = size of second index
        +j*INT_SIZE);



    printf("\n"); // break paragraphs

    i = 0;
    j = 3;

    printf("&matrix[%d][%d]:", i, j); 
    printf("\t\t%d\n", &matrix[i][j]); // Two subscripts didn't work for only one "*"
    task_2_print(INT_SIZE, i, j, &matrix);
}


int main()
{
    const int INT_SIZE = sizeof(int);
    task_2(INT_SIZE);
    return 0;
}