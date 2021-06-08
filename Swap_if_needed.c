/*
This function should return nothing (i.e., void as the return type) to complete the program fragment provided
below. After calling your function in the main function, variable num1 stores the larger value and
variable num2 stores the smaller value. Using pass by pointer. Supposed to work for two different values.
Not meant for the case that two integers are equal or invalid inputs, such as non-integer inputs, are entered. 
*/

#include <stdio.h>

void swapIfNeeded(int *a, int *b);



int main(int argc, char * argv[]) {
	int num1, num2;
    
    printf("Please enter two integers (separated by ,):\n");
    scanf("%d,%d", &num1, &num2);  //enter two integers separated by a comma (,)
    
    printf("num1 stores: %d\n", num1);
    printf("num2 stores: %d\n", num2);
    
    swapIfNeeded(&num1, &num2);
    
    printf("\nAfter calling the function\n");
    printf("num1 stores the bigger one: %d\n", num1);
    printf("num2 stores the smaller one: %d\n", num2);
    
    return 0;
}


// This function uses pass by pointer to swap if the condtition is met otherwise the variables remain the same.
void swapIfNeeded(int *a, int *b) {
   
   int temp;
   
   if (*a < *b) {
      temp = *a;
      *a = *b;
      *b = temp;
   }
   
   return;   
}
