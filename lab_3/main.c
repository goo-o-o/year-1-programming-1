//
// Created by bryan on 22/10/2025.
//


#include <stdio.h>
#include <stdlib.h>

int *sort(int n, int *ptr) {
    int i, j, t;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (*(ptr + j) < *(ptr + i)) {
                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }

    return ptr;
}

int *mergeSorted(int *arr1, int n1, int *arr2, int n2) {
    int *ret = malloc((n1 + n2) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j])
            ret[k++] = arr1[i++];
        else // Set first then only increment index
            ret[k++] = arr2[j++];
    }

    // Now we need to copy remaining elements
    while (i < n1) ret[k++] = arr1[i++];
    while (j < n2) ret[k++] = arr2[j++];

    for (i = 0; i < n1; ++i)
        arr1[i] = ret[i];

    for (j = 0; j < n2; ++j)
        arr2[j] = ret[n1 + j];

    return ret;
}


int main() {
    int a[10], b[10];

    int sizeA = sizeof(a) / sizeof(a[0]);
    int sizeB = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < sizeA; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }


    printf("Unsorted:\n");
    for (int i = 0; i < sizeA; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeB; i++) {
        printf("%d ", b[i]);
    }
    printf("\n==================================================================\nSorted:\n");

    int *sortedA = sort(sizeA, a);

    for (int i = 0; i < sizeA; i++) {
        printf("%d ", sortedA[i]);
    }
    printf("\n");


    int *sortedB = sort(sizeB, b);

    for (int i = 0; i < sizeB; i++) {
        printf("%d ", sortedB[i]);
    }
    printf("\n==================================================================\nSMerged:\n");

    int *merged = mergeSorted(sortedA, sizeA, sortedB, sizeB);

    for (int i = 0; i < sizeB + sizeA; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    free(merged);
}
