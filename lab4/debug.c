#include <stdio.h>
#include <stdlib.h>

void initializeArray(int *arr, int size) {
    if (arr == NULL) return;
    for (int i = 0; i <= size; i++) {
        // arr[i] = i * 1; // Pointer may be null, when calling from main (3), also should be multiplied by 2 (8);.
        arr[i] = i * 2;
    }
}

int *resizeArray(int *arr, int newSize) {
    // arr = realloc(arr, newSize * sizeof(int)); // Should not modify the original buffer (9), may fail and cause arr = null which results in memory leak
    int *temp_arr = realloc(arr, newSize * sizeof(int));
    if (temp_arr == NULL) {
        printf("Reallocation failed!");
        free(arr); // Free inherently handles null values, no need for check
        // free(arr); // Double free (2)
        exit(1); // Missing Semicolon (1)
    }
    arr = temp_arr;
    return arr;
}

int main() {
    int size = 5;
    int *arr = malloc(size * sizeof(int)); // IDE says that this could leak but free() is always called on arr no matter where the code goes
    initializeArray(arr, size);
    printf("Before Resizing\n");
    for (int i = 0; i < size; i++) // IndexOutOfBoundsException, will loop 6 times but array size is 5 (4)
    {
        printf("Index: %d | Value: %d\n", i, arr[i]); // Not enough arguments for printf (5);
    }
    int newSize = size + 3; // newSize should be size + 3, based on the instruction
    arr = resizeArray(arr, newSize);
    printf("\nNewly added Elements\n");
    for (int i = size; i < newSize; i++) // IndexOutOfBoundsException, will loop 6 times but array size is 5 (6)
        // int i should equal size because we only print from Index 5 onwards (10)
    {
        arr[i] = i * 2;
        printf("Index: %d | Value: %d\n", i, arr[i]); // Not enough arguments for printf (7)
    }

    free(arr);

    arr = NULL; //REMEMBER to always set pointer to NULL after free()
    return 0;
}
