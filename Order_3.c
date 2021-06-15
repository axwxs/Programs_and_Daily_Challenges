/*

Required to write a function, called orderThree which rearranges three numbers in 
increasing order. The function should return nothing (void as the return type) and 
take three parameters. After calling the function in the main function, the double 
variables num1, num2, and num3 should be in ascending order with 2 decimal places. 
Should use pass by pointer (mimic pass by reference). So pointers as function 
formal parametes.

For example:
If the inputs are "23.558 12 -24.2" the output should be "-24.20 12.00 23.55"

Some constraints:
In the main function you can only call the function you wrote. Nothing else should be
added or altered. Can't use any global variables in the program.

*/

#include <stdio.h>

// Forward declartion
void orderThree(double *a, double *b, double *c);

int main(int argc, char * argv[]) {
	double num1, num2, num3;
    
	printf("Enter three numbers separated by blanks:\n");
	scanf("%lf%lf%lf", &num1, &num2, &num3);
    
	// Function call to order the 3 numbers in increasing order
	orderThree(&num1, &num2, &num3);
    
    
	// Display the Results
	printf("The numbers in ascending order are: %.2f %.2f %.2f\n", num1, num2, num3);
    
	return 0;
}


/*
Uses pointers and temporary variables to change which variable stores which value. 
Results in the input variables storing values in ascending (increasing) order appropriately.
*/
void orderThree(double *a, double *b, double *c) {
	double temp;
 
	if (*a > *c) {
		temp = *c;
		*c = *a;
		*a = temp;
	}
	
	if (*b > *c) {
		temp = *c;
		*c = *b;
		*b = temp;
	}
	
	if (*a > *b) {
		temp = *b;
		*b = *a;
		*a = temp;
	}   
   
	return;
}
