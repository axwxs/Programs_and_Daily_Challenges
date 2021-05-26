/*
Takes two positive integers as input and outputs the greatest common denominator for them.
*/

#include <stdio.h>

void clearKeyboardBuffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n' && ch != '\0') {
		scanf("%c", &ch);
	}
}

int getPosInt() {
   int posInt = 0;
   while (2>1) {

      scanf("%d", &posInt);
      clearKeyboardBuffer();
      if (posInt > 0) {
         break;
      }
      else if (posInt <= 0) {
         printf("I'm sorry, that number is unrecognized or not positive.\nPlease enter a positive integer:\n");
         continue;
      }
   }
   
   return posInt;   
}

int getGCD(int a, int b) {
   
   if (a == 0) {
      return b;
   }
   return getGCD((b%a), a);
   
}

int main(int argc, char *argv[]) {
	int a, b;
   
	printf("Please enter a positive integer:\n");
	a = getPosInt();
   
	printf("Please enter a second positive integer:\n");
	b = getPosInt();
   
	printf("The largest integer that divides both %d and %d is: %d\n", a, b, getGCD(a, b));
 
	return 0;  
}
