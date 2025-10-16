//
// Created by bryan on 16/10/2025.
//


#include <stdio.h>
#include <stdlib.h>

float* inputTemperatures(int dayCount) {
    float* temps = malloc(dayCount * sizeof(float));

    if (temps == NULL) {
        // Handle memory allocation error
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter the Temperature for %d days:\n", dayCount);

    for (int i = 0; i < dayCount; i++) {
        printf("Day %d:", i + 1);
        scanf("%f", &temps[i]);
    }

    return temps;
}

float calculateWeeklyAverage(const float arr[], int dayCount) {
    float sum = 0;
    for (int i = 0; i < dayCount; i++) {
        sum += arr[i];
    }

    return sum / (float) dayCount;
}

float findMax(const float arr[], int dayCount) {
    float currentMax = 0;

    for (int i = 0; i < dayCount; i++) {
        if (currentMax < arr[i])
            currentMax = arr[i];
    }

    return currentMax;
}

float findMin(const float arr[], int dayCount) {
    float currentMin = (float) INT_MAX;

    for (int i = 0; i < dayCount; i++) {
        if (currentMin > arr[i])
            currentMin = arr[i];
    }

    return currentMin;
}

int countDaysAboveAverage(const float arr[], int dayCount, float average) {
    int daysAboveAverage = 0;
    for (int i = 0; i < dayCount; i++) {
        if (arr[i] > average) ++daysAboveAverage;
    }
    return daysAboveAverage;
}


int countDaysBelowAverage(float arr[], int dayCount, float average) {
    return dayCount - countDaysAboveAverage(arr, dayCount, average);
}


int main() {
    float *temps = inputTemperatures(7);

    float weeklyAverage = calculateWeeklyAverage(temps, 7);

    printf("Weekly Average Temperature: %f\n", weeklyAverage);
    printf("Highest Temperature: %f\u00B0C\n", findMax(temps, 7));
    printf("Lowest Temperature: %f\u00B0C\n", findMin(temps, 7));

    printf("Days above average: %d\n", countDaysAboveAverage(temps, 7, weeklyAverage));
    printf("Days below average: %d\n", countDaysBelowAverage(temps, 7, weeklyAverage));

    free(temps);
}
