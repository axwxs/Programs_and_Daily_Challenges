/*
Purpose: Program that uses fibonacci sequence for calculating
amount of Green Crud after the inputed number of days given an
initial starting amount
*/

#include <stdio.h>

void clearKeyboardBuffer(void);
int fib(int initialCrud,int inputNum);

int main(int argc, char *argv[])  {
/* 
The first two variables are used to input into the fibonacci function. 
They are set to -1 (rather than a standard 0) because we need to allow 
for the option of 0 initial lbs of crud and 0 days of time. The exit character
is used at the end to see if the user wants to run the program again or not.
*/
int initialCrud = -1;
int inputNum = -1;
char exitCharacter;

/*
I used the initial while loop (that is always true) so the exit character has the option
of breaking or continuing. The other ones are used to ensure we get valid input.
*/
while (2 > 1) {
    while (initialCrud <= -1) {
        printf("Please enter the initial size of the green crud:\n");
        scanf("%d", &initialCrud);
        clearKeyboardBuffer();
        if (initialCrud <= -1) {
        printf("I'm sorry that value is unrecognized or is negative.\n");
        }
    }
  
    while (inputNum <= -1) {
        printf("Please enter the number of days:\n");
        scanf("%d", &inputNum);
        clearKeyboardBuffer();
        if (inputNum <= -1) {
        printf("I'm sorry that value is unrecognized or is negative.\n");  
        }
    }
  
		printf("The final population would be %d pounds.\n", fib(initialCrud, inputNum));
  
/* 
This loop is simply used to check if the input is valid (either x or y).
The other ones after act according whether the input means to continue 
or not.
*/
    while (exitCharacter != 'n' || exitCharacter != 'y') {
        printf("Would you like to continue? (y/n)");
        scanf("%c", &exitCharacter);
        clearKeyboardBuffer();
        if (exitCharacter == 'n') {
            break;
        }
        else if (exitCharacter == 'y') {
            break;
        }
        else {
            printf("I am sorry that answer is not recognized.\n");
            continue;
        }
    }
  
    if (exitCharacter == 'n') {
        break;
    }
  
    else if (exitCharacter == 'y') {
        initialCrud = -1;
        inputNum = -1;
        continue;
    }
  
}

return 0;  
}


/* 
This is the function that takes the input and performs the necessary 
calculations for a fibonacci sequence. I have written a fibonacci sequence
in other programming languages before so I knew the generic structure.
I made adjustments to the initial function until my sample input in 
development mode was matching what was shown in the sample output table. 
So that meant multiplying the return value variabe by the initialCrud 
variable, dividing the inputNum varibale by five, and starting it at 1 
instead of 0. Then it was giving correct output.
*/
int fib(int initialCrud, int inputNum){
   
    int inputNumByFive = (inputNum / 5) + 1;
    int a = 0, b = 1, c, i;
    if( inputNumByFive == 0 || inputNumByFive == 1)
        return initialCrud;
    for (i = 2; i <= inputNumByFive; i++) {
        c = a + b;
        a = b;
        b = c;
    }
return b*initialCrud;
}


// Clears the buffer as is obvious
void clearKeyboardBuffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n' && ch != '\0') {
		scanf("%c", &ch);
	}
}
