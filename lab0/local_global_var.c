#include <stdio.h>

int num2 = 40;
void function1() {
    int num1 = 30;
    printf("Local: %d\n", num1);
}

void function2() {
    printf("Global: %d\n", num2);
}

void function3() {
    // printf("Local2: %d\n", num1); Commented out as the code will not compile into an exe
}

int main() {
    function1();
    function2();
    function3();
    return 0;
    // Can't run because num1 is a local variable and the scope is limited to that method only
}