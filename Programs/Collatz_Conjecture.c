/*
Uses the collatz conjecture to print out a table of how many steps are need to for the 3n+1 algorithm to reach 1. 
Has some some limit specifications and other optional details needed to satisfy test checks.
*/

#include <stdio.h>


int howManySteps(int a);

void clearKeyboardBuffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n' && ch != '\0') {
		scanf("%c", &ch);
	}
}

int main(int argc, char *argv[]) {
   int a; // This is the first number that will be used for input
   printf("Enter a starting point:\n");
   scanf("%d", &a);
   clearKeyboardBuffer();
   while (a <= 1 || a > 99) {
      printf("Enter a valid starting point (from 2-99):");
      scanf("%d", &a);
      clearKeyboardBuffer();
      continue;
   }
   
   int b; // This is the second number that will be used for input
   printf("Enter an ending point:\n");
   scanf("%d", &b);
   clearKeyboardBuffer();
   while (b <= a || b > 999) {
      printf("Enter a valid ending point (from %d-999):", a);
      scanf("%d", &b);
      clearKeyboardBuffer();
      continue;
   }
   
   // The variables below are used for keeping tracking of incrementation and how many numbers are left to output.
   int totalPairsToPrint = (b - a) + 1;
   int totalFullLines = totalPairsToPrint / 7;
   int leftoverPairsToPrint = ((b - a) + 1) % 7;
   int lineTracker = 0;
   
   // This portion outputs full lines of 7 pairs
   while (totalFullLines > 0) { 
      for (int i = a; i <= (b - leftoverPairsToPrint); i = i + 7) {
         printf("%5d:%-5d%5d:%-5d%5d:%-5d%5d:%-5d%5d:%-5d%5d:%-5d%5d:%-5d\n", i, howManySteps(i), i+1, howManySteps(i+1),
         i+2, howManySteps(i+2), i+3, howManySteps(i+3), i+4, howManySteps(i+4), i+5, howManySteps(i+5), i+6, howManySteps(i+6));
         lineTracker++;
         totalFullLines--;
      }
   }

   // This portion outputs any left over numbers that aren't in full lines of 7 pairs.
   if (leftoverPairsToPrint > 0) {
      int x = a + (lineTracker*7);
      while (leftoverPairsToPrint != 0) {
         if (leftoverPairsToPrint == 1)
            printf("%5d:%-5d\n", x, howManySteps(x));
         else
            printf("%5d:%-5d", x, howManySteps(x));
         leftoverPairsToPrint--;
         x++;
      }
   }
   return 0;  
}


/*
This function uses the collatz math sequence along with the input variable to calculate and return the needed number
*/
int howManySteps(int a) {
   int i = 0;
   while (a != 1) {
      if (a % 2 == 0) {
         a = a / 2;
         i++;
         continue;
      }
      else {
         a = (3*a) + 1;
         i++;
         continue;
      }
   }
   return i;
}
