#include "Lab05_Task4.h"
#include <stdio.h>
#include <stdlib.h>

// A struct defined for the whole module, just as our Founding Fathers intended
struct Data {
    char a[3];
    int b;
    short c;
    double d;
};

void task_4_part_1_manual_calculation(const int INT_SIZE, const int CHAR_SIZE, const int SHORT_SIZE, const int DOUBLE_SIZE, const int A_SIZE)
{
    struct Data data;
    printf("Manual address calculation:\n");
    printf("&data = \t0x%p\n", &data);
    for(size_t i=0;i<A_SIZE;i++)
        printf("&Data.a[%d] = \t0x%p\n", i, 
                &data.a+i);
    printf("&Data.b = \t0x%p\n", 
            &data.b);
    printf("&Data.c = \t0x%p\n", 
            &data.c);
    printf("&Data.d = \t0x%p\n", 
            &data.d);
    printf("\n"); // paragraph break;
    printf("\n"); // break between parts of the same task;
}

void task_4_part_1_automatic_c_math(const int INT_SIZE, const int CHAR_SIZE, const int SHORT_SIZE, const int DOUBLE_SIZE, const int A_SIZE)
{
    // Part 1: Given Data starts at 0x4000, compute
        // the addresses of:
            // data.a[0], data.a[1], data.a[2]
            // data.b
            // data.c
            // data.d
        // the size of the structure data
    struct Data data;
    printf("Automatic C math:\n");
    for(size_t i=0;i<A_SIZE;i++)
        printf("&Data.a[%d] = \t0x%p\n", i, 
                &data.a[i]);
    printf("Char size = \t0x%p\n", CHAR_SIZE);
    printf("Space wasted = \t0x%p\n", (INT_SIZE > CHAR_SIZE)? INT_SIZE - CHAR_SIZE : 0);
    printf("\n"); // The repetition in these print statements is begging for paragraph breaks

    printf("&Data.b = \t0x%p\n", 
            &data.b);
    printf("Int size = \t0x%p\n", INT_SIZE);
    printf("Space wasted = \t0x%p\n", (SHORT_SIZE > INT_SIZE)? SHORT_SIZE - INT_SIZE : 0);
    printf("\n"); // paragraph break
    
    printf("&Data.c = \t0x%p\n", 
            &data.c);
    printf("Difference = \t0x%p\n", SHORT_SIZE);
    printf("Space wasted = \t0x%p\n", (DOUBLE_SIZE > SHORT_SIZE)? DOUBLE_SIZE - SHORT_SIZE : 0);
    printf("&Data.d = \t0x%p\n", 
            &data.d);
    printf("Difference = \t0x%p\n", DOUBLE_SIZE);
    printf("\n"); // paragraph break
    printf("\n"); // break between parts of the same task;
}

void task_4(const int INT_SIZE, const int CHAR_SIZE, const int SHORT_SIZE, const int DOUBLE_SIZE)
{
    int target_addr = 4 * 16 * 16 * 16; // = 0x4000 = 4*16^3
    const size_t A_SIZE = 3;
    task_4_part_1_automatic_c_math(INT_SIZE, CHAR_SIZE, SHORT_SIZE, DOUBLE_SIZE, A_SIZE);
    task_4_part_1_manual_calculation(INT_SIZE, CHAR_SIZE, SHORT_SIZE, DOUBLE_SIZE, A_SIZE);
    
}