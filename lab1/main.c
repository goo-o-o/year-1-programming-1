//
// Created by bryan on 09/10/2025.
//

#include <stdio.h>
#include <string.h>


void printBiodata(void) {
    // Initialize fields
    const int age = 28;
    const float height = 1.7F;
    const double weight = 72;
    const char grade = 'A';
    const char name[] = "John";
    // char buffer[100];

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);

    // sprintf(buffer, "Height: %.2f", height);
    // printf("%s Metre\n", buffer);

    printf("Height: %.2f Metre\n", height);
    printf("Weight: %.1f KG\n", weight);

    // sprintf(buffer, "Weight: %.1f", weight);
    // printf("%s KG\n", buffer);

    printf("Grade: %c\n", grade);
}

void typeCasting(void) {
    const int marks = 85;
    const int total = 100;
    char buffer[50];
    const float percentage = (float) marks / (float) total * 100;

    printf("Marks: %d / %d\n", marks, total);
    sprintf(buffer, "%.2f", percentage);

    printf("Percentage: %s%%", buffer);
}

int main() {
    printf("Welcome to C programming!\nMy second lab exercise");
    printBiodata();
    typeCasting();
}
