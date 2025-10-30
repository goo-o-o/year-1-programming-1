//
// Created by bryan on 30/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
int num = 10;

int modifyByValue(int input) {
    return input << 1;
}

void modifyByReference(int *input) {
    *input = *input << 1;
}

void doubleArrayElements(int arr[], int size) {
    if (arr == NULL) return;
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
}

int main() {
    int *ptr = malloc(5 * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated");
    } else {
        for (int i = 0; i < 5; i++) {
            ptr[i] = i;
        }
    }

    modifyByValue(num);
    printf("modifyByValue() = %d\n", num);
    modifyByReference(&num);
    printf("modifyByReference() = %d\n", num);

    doubleArrayElements(ptr, 5);
    if (ptr == NULL) return 0;
    for (int i = 0; i < 5; i++) {
        printf("%d\n", ptr[i]);
    }

    free(ptr);
    ptr = NULL;
}
