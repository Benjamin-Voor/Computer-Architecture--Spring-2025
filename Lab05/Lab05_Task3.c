#include <stdio.h>

void task_3(const int INT_SIZE)
{
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
}
