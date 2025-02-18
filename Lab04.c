#include <stdio.h>


// Standard control structures
void ex_if_else(int x)
{
    int ntest = x <= 0;
    if (ntest) goto Else;
    goto Done;
Else:
    printf("x is not positive\n");
Done:
    printf("x is positive\n");

    // if (x > 0)
    //     printf("x is positive\n");
    // else
    //     printf("x is not positive\n");
}

void ex_conditional(int x)
{
    // printf("x is %s\n", (x > 0) ? "positive" : "not positive");

    int ntest = !(x > 0);
    char* out = "";
    if (ntest) goto Else;
    out = "positive";
    goto Done;
Else:
    out = "not positive";
    goto Finally;
Done:
    out = "positive";
    goto Finally;
Finally:
    printf("x is %s\n", out);
}

void case1()
{
    printf("x is 1\n");
}

void case2()
{
    printf("x is 2\n");
}

void defaultLabel()
{
    printf("x is something else\n");
}

void ex_switch(int x)
{
    // Jump table: Array of function pointers
    static void (*jumpTable[])() = { case1, case2 };
validate:
    // Validate input and jump to the respective case
    int nTest = !(x == 1 || x == 2);
    if (nTest) goto defaultLabel;
    // if (x >= 1 && x <= 2)
switchLabel:
    jumpTable[x - 1](); // Equivalent to calling function from the table
    goto done;
// case1:
//     printf("going to case 1...");
//     case1();
//     goto done;
// case2:
//     printf("going to case 2...");
//     case2();
//     goto done;
defaultLabel:
    printf("going to default label...");
    defaultLabel();
    // goto done; // Redundant, in a falling case.
done:
    // printf("done"); // the only debugging message that actually prints! So I commented it out
    return;
    /*
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
    */
}

void ex_do_while(int x)
{
    int i = 0;
loop:
    printf("i = %d\n", i);
    i++;
    int test = (i < x);
    if (test) goto loop;

  // int i = 0;
  // do
  // {
  //   printf("i = %d\n", i);
  //   i++;
  // } while (i < x);
}

void ex_while(int x)
{
    int i = 0;
    goto test;
loop:
    printf("i = %d\n", i);
    i++;
test:
    if (i < x) { goto loop; }
done:
    return;
     
    /*
    int i = 0;
    while (i < x)
    {
        printf("i = %d\n", i);
        i++;
    }
    */
}


void ex_for(int x)
{
  // for (int i = 0; i < x; i++)
  // {
  //   printf("i = %d\n", i);
  // }

  size_t i = 0;
  goto test;
loop:
  printf("i = %zd\n", i); // %zd because it's size_t
  i++;
test:
  if (i < x) { goto loop; }
}

int main()
{
  printf("=== C/C++ control structures ===\n");
  printf("--- 1. if...else ---\n");
  ex_if_else(1);

  printf("\n--- 2. conditional ---\n");
  ex_conditional(-1);

  printf("\n--- 3. switch ---\n");
  ex_switch(2);

  printf("\n--- 4. do...while  ---\n");
  ex_do_while(3);

  printf("\n--- 5. while ---\n");
  ex_while(3);

  printf("\n--- 6. for ---\n");
  ex_for(3);

  return 0;
}
