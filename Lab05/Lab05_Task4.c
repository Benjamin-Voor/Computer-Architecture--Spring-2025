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

struct AscendingData {
    char a[3]; // 1 == sizeof(char)
    short c; // 2 == sizeof(short)
    int b; // 4 == sizeof(int)
    double d; // 8 = sizeof(double)
};

int calculate_offset(int a_offset, int b_offset, const int TYPE_SIZE, int debugg)
{
    // if(debugg) 
    // {
    //     printf("Before transformation:\n"
    //             "a_offset = %d\n"
    //             "b_offset = %d\n", a_offset, b_offset);
    // }
    while(b_offset < a_offset)
    {
        // if(debugg) printf("%d\n", b_offset); // for debugging purposes only
        b_offset += TYPE_SIZE;
    }

    return b_offset;
    /*
    Bad code underneath. Just ignore it.
    const int MAX_TYPE_SIZE = DOUBLE_SIZE
    if(b_offset < MAX_TYPE_SIZE)
        return b_offset;
    else // "else" is redundant but readable
    {
    int wasted_space = a_offset + b_offset % MAX_TYPE_SIZE;
    if(wasted_space != 0)
        b_offset += wasted_space;
    }
    return b_offset;
    */
}

void task_4_part_1_manual_calculation(const int INT_SIZE, const int CHAR_SIZE, const int SHORT_SIZE, const int DOUBLE_SIZE, const int A_SIZE, const int TARGET_ADDR, int debugg)
{
    /* struct */
    struct Data data;
    printf("Manual address calculation, given `struct Data data;` starts at `0x%x`:\n", TARGET_ADDR);
    printf("&data = \t0x%x\n", TARGET_ADDR);
    
    /* a */
    // int a_offset = calculate_offset(TARGET_ADDR,0,CHAR_SIZE); // This results in integer overflow, but it's what I'm doing in principle
    int a_offset = 0;
    for(size_t i=0;i<A_SIZE;i++)
    {
        a_offset = calculate_offset(a_offset, i*CHAR_SIZE, CHAR_SIZE, debugg);
        printf("&Data.a[%d] = \t0x%x\n", i,
                TARGET_ADDR+a_offset);
    }
    a_offset += CHAR_SIZE; // postincrement by occupied address space

    /* b */
    int b_offset = 0;
    b_offset = calculate_offset(a_offset, b_offset, INT_SIZE, debugg);
    printf("&Data.b = \t0x%x\n",
            TARGET_ADDR+b_offset);
    b_offset += INT_SIZE; // postincrement by occupied address space

    int c_offset = 0;
    c_offset = calculate_offset(b_offset, c_offset, SHORT_SIZE, 1);
    printf("&Data.c = \t0x%x\n", 
            TARGET_ADDR+c_offset);
    c_offset += SHORT_SIZE; // postincrement by occupied address space

    /* d */
    int d_offset = 0;
    // if(debugg) printf("%d%d", d_offset, DOUBLE_SIZE); // ensure declaration is correct
    d_offset = calculate_offset(c_offset, d_offset, DOUBLE_SIZE, debugg);
    printf("&Data.d = \t0x%x\n", 
            TARGET_ADDR+d_offset);
    d_offset += DOUBLE_SIZE; // postincrement by occupied address space
    // printf("\n"); // paragraph break;

    /* size of struct */
    printf("Size of the structure data: 0x%x\n", d_offset);
    // printf("\n"); // paragraph break;

    printf("\n\n"); // two newlines between parts of the same task;
}

void task_4_part_1_automatic_c_math(const int INT_SIZE, const int CHAR_SIZE, const int SHORT_SIZE, const int DOUBLE_SIZE, const int A_SIZE)
{
    /* data */
    struct Data data;
    printf("Automatic C math:\n");
    printf("&Data = \t0x%p\n", &data);
    printf("\n"); // The repetition in these print statements is begging for paragraph breaks

    /* a */
    for(size_t i=0;i<A_SIZE;i++)
        printf("&Data.a[%d] = \t0x%p\n", i, 
                &data.a[i]);
    printf("Char size = \t0x%p\n", CHAR_SIZE);
    printf("Space wasted = \t0x%p\n", (INT_SIZE > CHAR_SIZE)? INT_SIZE - 3*CHAR_SIZE : 0); // (NEXT_SIZE > CUR_SIZE)? NEXT_SIZE - CUR_SIZE : 0
    printf("\n"); // paragraph break

    /* b */
    printf("&Data.b = \t0x%p\n", 
            &data.b);
    printf("Int size = \t0x%p\n", INT_SIZE);
    printf("Space wasted = "
            "\t0x%p\n", (SHORT_SIZE > INT_SIZE)? SHORT_SIZE - INT_SIZE : 0);
    printf("\n"); // paragraph break
    
    /* c */
    printf("&Data.c = \t0x%p\n", 
            &data.c);
    printf("Short size = \t0x%p\n", SHORT_SIZE);
    printf("Space wasted = \t0x%p\n", (DOUBLE_SIZE > SHORT_SIZE)? DOUBLE_SIZE - SHORT_SIZE : 0);
    printf("\n"); // paragraph break

    /* d */
    printf("&Data.d = \t0x%p\n", 
            &data.d);
    printf("Double size = \t0x%p\n", DOUBLE_SIZE);
    printf("Space wasted = \t" 
            "N/A\n");
    printf("\n"); // paragraph break

    printf("\n"); // break between parts of the same task;
}

void task_4_part_2_automatic_c_math(const int INT_SIZE, const int CHAR_SIZE, const int SHORT_SIZE, const int DOUBLE_SIZE, const int A_SIZE)
{
    struct AscendingData data;
    printf("Automatic C math of a structure with ascending order of primitive data type sizes::\n");
    printf("&Data = \t0x%p\n", &data);
    printf("\n"); // The repetition in these print statements is begging for paragraph breaks

    /* a */
    for(size_t i=0;i<A_SIZE;i++)
        printf("&Data.a[%d] = \t0x%p\n", i, 
                &data.a[i]);
    printf("Char size = \t0x%p\n",
            CHAR_SIZE);
    printf("Space wasted = \t0x%p\n",
            // (SHORT_SIZE > 3*CHAR_SIZE)? SHORT_SIZE - 3*CHAR_SIZE : 0); // modulo is actually more accurate
            (3*CHAR_SIZE) % SHORT_SIZE);
    printf("\n"); // paragraph break

    /* c */
    printf("&Data.c = \t0x%p\n",
            &data.c);
    printf("Short size = \t0x%p\n",
            SHORT_SIZE);
    printf("Space wasted = \t0x%p\n",
        (INT_SIZE > SHORT_SIZE)? INT_SIZE - SHORT_SIZE : 0);
    printf("\n"); // paragraph break

    /* b */
    printf("&Data.b = \t0x%p\n",
            &data.b);
    printf("Int size = \t0x%p\n",
            INT_SIZE);
    printf("Space wasted = \t0x%p\n",
            // (DOUBLE_SIZE > INT_SIZE)? DOUBLE_SIZE - INT_SIZE : 0); // modulo is actually more accurate
            INT_SIZE % DOUBLE_SIZE);

    printf("\n"); // paragraph break
    
    /* d */
    printf("&Data.d = \t0x%p\n",
            &data.d);
    printf("Double size = \t0x%p\n",
            DOUBLE_SIZE);
    printf("Space wasted = \tN/A");
    printf("\n"); // paragraph break

    printf("\n"); // break between parts of the same task;
}

void task_4_part_2_manual_calculation(const int INT_SIZE, const int CHAR_SIZE, const int SHORT_SIZE, const int DOUBLE_SIZE, const int A_SIZE, const int TARGET_ADDR, int debugg)
{
    struct AscendingData data;
    printf("Manual calculation of a structure with ascending order of primitive data type sizes:\n");
    
    /* a */
    int a_offset = 0;
    for(size_t i=0;i<A_SIZE;i++)
    {
        a_offset = calculate_offset(a_offset,i*CHAR_SIZE,CHAR_SIZE, debugg);
        printf("&Data.a[%d] = \t0x%x\n", i,
                TARGET_ADDR+a_offset);
    }
    a_offset += CHAR_SIZE; // postincrement by occupied address space

    /* c */
    int c_offset = 0;
    c_offset = calculate_offset(a_offset, c_offset, SHORT_SIZE, debugg);
    printf("&Data.c = \t0x%x\n", 
            TARGET_ADDR+c_offset);
    c_offset += SHORT_SIZE; // postincrement by occupied address space

    /* b */
    int b_offset = 0;
    b_offset = calculate_offset(c_offset, b_offset, INT_SIZE, debugg);
    printf("&Data.b = \t0x%x\n",
            TARGET_ADDR+b_offset);
    b_offset += INT_SIZE; // postincrement by occupied address space

    /* d */
    int d_offset = 0;
    // if(debugg) printf("%d%d", d_offset, DOUBLE_SIZE); // ensure declaration is correct
    d_offset = calculate_offset(b_offset, d_offset, DOUBLE_SIZE, debugg);
    printf("&Data.d = \t0x%x\n", 
            TARGET_ADDR+d_offset);
    d_offset += DOUBLE_SIZE; // postincrement by occupied address space
    printf("\n"); // paragraph break

    printf("\n"); // break between parts of the same task;
}

void task_4(const int INT_SIZE, const int CHAR_SIZE, const int SHORT_SIZE, const int DOUBLE_SIZE)
{
    int TARGET_ADDR = 4 * 16 * 16 * 16; // = 0x4000 = 4*16^3
    const size_t A_SIZE = 3;

    
    printf("Part 1:\n", TARGET_ADDR);
        // Part 1: Given Data starts at 0x4000, compute
        // the addresses of:
            // data.a[0], data.a[1], data.a[2]
            // data.b
            // data.c
            // data.d
        // the size of the structure data
    task_4_part_1_automatic_c_math(INT_SIZE, CHAR_SIZE, SHORT_SIZE, DOUBLE_SIZE, A_SIZE);
    task_4_part_1_manual_calculation(INT_SIZE, CHAR_SIZE, SHORT_SIZE, DOUBLE_SIZE, A_SIZE, TARGET_ADDR, 0);


    printf("Part 2. Field Reordering Experiment:\n");
    task_4_part_2_automatic_c_math(INT_SIZE, CHAR_SIZE, SHORT_SIZE, DOUBLE_SIZE, A_SIZE);
    task_4_part_2_manual_calculation(INT_SIZE, CHAR_SIZE, SHORT_SIZE, DOUBLE_SIZE, A_SIZE, TARGET_ADDR, 0);
}