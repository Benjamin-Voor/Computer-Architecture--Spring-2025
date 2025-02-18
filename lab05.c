#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE_TASK_1 5

void task_1_just_for_fun(const int INT_SIZE) {
    /*If arr starts at 0x1000, compute the address of arr[2], arr[4]. */
    int arr[ARR_SIZE_TASK_1] = {10, 20, 30, 40, 50};
    int *a = arr;
    printf("arr = %d", *arr);
    printf(" = a = %d\n", *a);
    printf("Array is {");
    for(int i=0; i<ARR_SIZE_TASK_1; i++)
    {
        printf("%d", arr[i]);
        if(ARR_SIZE_TASK_1 - 1 != i)
            printf(", ");
    }
    printf("}\n");
    for(int i=0; i<ARR_SIZE_TASK_1; i++)
    {
        printf("Address of %d ", arr[i]); 
        printf("is %d\n", arr[i]);
        printf("\tWhich in automatic C math yields %d\n", *(arr+i));
        printf("\tAnd in manual math yields %d\n", *(a+(i*INT_SIZE)));
    }
}

void task_1_print(const int INT_SIZE, int* arr, int i, int target_addr) {

    printf("arr = %d\n", arr);
    printf("&arr[%d] = %d\n", i, &arr[i]);
    printf("Difference of %d\n\n", i*INT_SIZE);
}

void task_1(const int INT_SIZE) {
    /*If arr starts at 0x1000, compute the address of arr[2], arr[4]. */
    int arr[ARR_SIZE_TASK_1] = {10, 20, 30, 40, 50};
    int *a = arr;
    printf("arr = %d", *arr);
    printf(" = a = %d\n", *a);

    int i=2;
    int FourThousandNinetySix = 16*16*16; // 16 ** 3, but without including math.h
    printf("(0x%x+%d)?\n", FourThousandNinetySix, i);
    task_1_print(INT_SIZE, &arr, i, FourThousandNinetySix);

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
    /*
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
    */
}

int main() {
    printf("Task 1: One-Dimensional Fixed-Size Array\n");
    const int INT_SIZE = sizeof(int);
    task_1(INT_SIZE);

    printf("\nTask 2: Two-Dimensional Fixed-Size  Array\n");
    task_2(INT_SIZE);

    printf("\nTask 3: ");

    int* jagged[3];
    int row1[] = {1, 2};        jagged[0] = row1;
    int row2[] = {3, 4, 5};     jagged[1] = row2;
    int row3[] = {6, 7, 8, 9};  jagged[2] = row3;
        // Assuming row2 starts at 0x3000, compute the address of jagged[1][2].
    struct Data {
        char a[3];
        int b;
        short c;
        double d;
    };
        // Given struct Data data; starts at 0x4000, compute
            // the addresses of:
            // data.a[0], data.a[1], data.a[2]
            // data.b
            // data.c
            // data.d
            // the size of the structure data
    return 0;
}