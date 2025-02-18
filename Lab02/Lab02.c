#include <iostream>

void print_binary(short n) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}
