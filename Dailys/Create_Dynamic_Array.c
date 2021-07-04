/*
Purpose: Dynamically create array with specified number of elements filled 
with odd numbers then print them with and without pointer arithmetic.
*/

#include <stdio.h>
#include <stdlib.h>

void printDown(int arr[], int number);
void printUp(int *arr, int number);
void fillArray(int arr[], int number);


int main(int argc, char *argv[]){
    int number;
    printf("Please enter the number of elements of your dyanmic array:\n");
    scanf("%d", &number);
   
    // Verifies the number is greater than 0
    while (number <= 0) {
        printf("Invalid number. Must be greater than 0.\n");
        printf("Please enter the number of elements of your dyanmic array:\n");
        scanf("%d", &number);
    }
   
    // Memory allocation
    int* arr = (int*) malloc(sizeof(int)*number);
   
    // Exits the program if memory allocation fails
    if (NULL == arr){
        printf("Memory failed to allocate. You suck.\n");
        exit(0);
    }
   
    fillArray(arr, number);
    printDown(arr, number);
    printUp(arr, number);
   
    // To prevent memory leaks!
    free(arr);
   
    return 0;
}

// Fills array with odd numbers upto specified number size
void fillArray(int arr[], int number){
    for (int i = 0; i < number; i++) {
        arr[i] = 2 * i + 1;
    }
}

// Standard non-pointer printing down of array
void printDown(int arr[], int number){
    for (int i = number - 1; i >= 0; i--) {
        printf("Element at index %d : %d\n", i, arr[i]);
    }
    printf("***\n");
}

// Prints array in reverse using pointer arithmetic
void printUp(int *arr, int number){
    int* pointer = arr;
    for (int i = 0; i < number; i++) {
        printf("Element at index %d : %d\n", i, *pointer);
        pointer++;
    }
}
