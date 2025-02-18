#include <stdio.h>

// Standard control structures
void std_ex_if_else(int x)
{
    if (x > 0)
        printf("x is positive\n");
    else
        printf("x is not positive\n");
}

void std_ex_conditional(int x)
{
    printf("x is %s\n", (x > 0) ? "positive" : "not positive");
}

void std_ex_switch(int x)
{
    switch (x)
    {
    case 1:
        printf("x is 1\n");
        break;
    case 2:
        printf("x is 2\n");
        break;
    default:
        printf("x is something else\n");
    }
}

void std_ex_do_while(int x)
{
    int i = 0;
    do
    {
        printf("i = %d\n", i);
        i++;
    } while (i < x);
}

void std_ex_while(int x)
{
    int i = 0;
    while (i < x)
    {
        printf("i = %d\n", i);
        i++;
    }
}

void std_ex_for(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("i = %d\n", i);
    }
}


int main()
{
    printf("=== C/C++ control structures ===\n");
    printf("--- 1. if...else ---\n");
    std_ex_if_else(1);

    printf("\n--- 2. conditional ---\n");
    std_ex_conditional(-1);

    printf("\n--- 3. switch ---\n");
    std_ex_switch(2);

    printf("\n--- 4. do...while  ---\n");
    std_ex_do_while(3);

    printf("\n--- 5. while ---\n");
    std_ex_while(3);

    printf("\n--- 6. for ---\n");
    std_ex_for(3);

    return 0;
}

