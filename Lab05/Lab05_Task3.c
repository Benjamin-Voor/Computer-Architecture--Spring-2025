#include <stdio.h>
#include <stdbool.h>
#include "Lab05_Task3.h"
// Hard-code row widths 2, 3, and 4
// Hard-code column height 3

task_3_view(const int INT_SIZE, int* jagged[], int i, int j, int option, int target_addr)
{
    switch(option)
    {
        case 0:
            printf("%d ", jagged[i][j]);
            break;
        case 1:
            printf("0x%p ", &jagged[i][j]);
            break;
        case 2:
            printf("0x%p ", j*INT_SIZE+target_addr);
            break;
        default:
            printf("Invalid input! Default case");
            break;
    }        
}

task_3_controller(const int INT_SIZE, int* jagged[])
{
    int target_addr = 3 * 16 * 16 * 16; // = 0x3000 = 3*16^3

    // Select one of three possible ways to print this array and its addresses
    int options = 3; 
    for(int option=0; option<options; option++)
    {
        switch(option)
        {
            case 0:
                printf("jagged's values\n");
                break;
            case 1:
                printf("jagged's addresses\n");
                break;
            case 2:
                printf("jagged's addresses if any given row started at 0x%x\n", target_addr);
                break;
            default:
                printf("Invalid input! Default case\n");
                break;
        }

        for(int j=0; j<2; j++) // row1
        {
            task_3_view(INT_SIZE, jagged, 0, j, option, target_addr);
        }
        printf("\n"); // line break

        for(int j=0; j<3; j++) //row2
        {
            task_3_view(INT_SIZE, jagged, 1, j, option, target_addr);
        }
        printf("\n"); // line break

        for(int j=0; j<4; j++) //row3
        {
            task_3_view(INT_SIZE, jagged, 2, j, option, target_addr);
        }
        printf("\n\n"); // Paragraph break
    }
}

void task_3_actual_answer(const int INT_SIZE)
{
    printf("Assuming row2 starts at 0x3000, the address of jagged[1][2] is ");
    printf("0x%p", 2*INT_SIZE+(3*16*16*16));
    printf("\n\n"); //double line break, for the end of the task_3 function
}

void task_3(const int INT_SIZE) // controller
{
    /* Assuming row2 starts at 0x3000, compute the address of jagged[1][2]. */
    int* jagged[3];
    
    // int*** jagged = task_3_model(INT_SIZE); // It would've been MVC, but it didn't work.
    int row1[2] = {1, 2};        jagged[0] = row1;
    int row2[3] = {3, 4, 5};     jagged[1] = row2;
    int row3[4] = {6, 7, 8, 9};  jagged[2] = row3;

    task_3_controller(INT_SIZE, &jagged);
    task_3_actual_answer(INT_SIZE);
}
