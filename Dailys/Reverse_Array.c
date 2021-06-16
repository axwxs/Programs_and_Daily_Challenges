/*
Practice working with an array of integers.

Write a program that creates an integer array with 40 elements in it. Then, call a function
fillArray that you will write that uses a for loop to assign values to each element of the array
so that each element has a value that is triple its index. For example, the element with index 0
should have a value of 0, the element with index 1 should have a value of 3, the element with index
2 should have a value of 6, and so on. Your fillArray function should work with any sized array,
so it needs to take the array size as a parameter.

Once the array is completely initialized, call another function, printArray, to output the array
to the screen with 10 elements per line where each element is right-justified in a column that is 7
characters wide. On the line after the array is printed, output a line that has 5 asterisks ('*') as a
divider (in main, not printArray).

Next, create and call a function reverseArray to reverse the array elements in the array you
created above, i.e., after reversal, the first element in the array should store 117, the second element
should store 114, . . . , and the last element in the array should store 0. Then call the printArray
function again to print the reversed array. This means that you are not asked to just output
the initial array in reversed order. You may NOT use a second array to help your reversal. If
you are not sure how to do it, please read the textbook again
*/

 
#include <stdio.h>

// Put declarations here I guess
void fillArray(int firstArray[], int arraySize);
void printArray(int firstArray[], int arraySize);
void reverseArray(int firstArray[], int arraySize);
 
int main(int argc, char *argv[]) {
   // int arraySize; # DEBUG: Testing this line removal
   int firstArray[40];
   
   // int i;
   
   // printf("Enter an array size:\n"); # DEBUG: Testing this line removal
   // scanf("%d", &arraySize); # DEBUG: Testing this line removal
   
   fillArray(firstArray, 40);
   
   
   printArray(firstArray, 40);
   printf("*****\n");
   
   reverseArray(firstArray, 40);
   printArray(firstArray, 40);
   
   return 0;
}


// Define your functions below

void fillArray(int firstArray[], int arraySize) {
   int i;
   
   for (i=0; i<arraySize; i++) {
      firstArray[i] = i*3;   
   }
   
   return;
}

void printArray(int firstArray[], int arraySize) {
   int i;
   
   for (i=0; i<arraySize; i++) {
      if (i>0 && (i%10) == 0) {
         printf("\n");
      }
      printf("%7d", firstArray[i]);
   }
   printf("\n");
   
   return;  
}

void reverseArray(int firstArray[], int arraySize) {
   int i;
   int tempVal;
   
   // Reverse array's elements
   for (i = 0; i < (arraySize / 2); ++i) {
      tempVal = firstArray[i];                        // Temp for swap
      firstArray[i] = firstArray[arraySize - 1 - i]; // First part of swap
      firstArray[arraySize - 1 - i] = tempVal;     // Second complete
   }
   
   return;   
}
