#include <stdio.h>

#include "external_var.h"

void function1() {
    static int total = 20;
    total += num1;
    printf("Static = %d\n", total);
}

int main() {
    function1();
    function1();
    return 0;
}