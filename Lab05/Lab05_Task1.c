#include "Lab05_Task1.h"
#include <stdlib.h>
#define ARR_SIZE_TASK_1 5

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
    task_1_print(INT_SIZE, arr, i, FourThousandNinetySix);

}

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

/* This breaks the linker if not commented out
int main()
{
    const int INT_SIZE = sizeof(int);
    task_1(INT_SIZE);
    return 0;
}
*/
