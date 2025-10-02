#include <stdio.h>

int num2 = 40;

void function1() {
    int num1 = 30;
    printf("Local: %d\n", num1);
}

void function2() {
    printf("Global: %d\n", num2);
}

int main() {
    function1();
    function2();
    return 0;
}