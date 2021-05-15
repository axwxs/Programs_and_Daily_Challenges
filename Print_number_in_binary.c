/*

Takes an integer input and outputs the number in binary form.
Only meant to convert positive integers.

*/


#include <stdio.h>

void printBinary(int decimalNum);
void clearKeyboardBuffer(void);

int main(int argc, char *argv[]) {
   
   int decimalNum;
   printf("Enter an integer: ");
   scanf("%d", &decimalNum);
   clearKeyboardBuffer();
   
   printf("\n");
   if (decimalNum == 0) {
      printf("%d", decimalNum);
   }
   
   else {
      printf("%d In binary: ", decimalNum);
      printBinary(decimalNum);
   }
   printf("\n");
   return 0;
}

void clearKeyboardBuffer(void) {
	char ch;
	scanf("%c", &ch);
	while (ch != '\n' && ch != '\0') {
		scanf("%c", &ch);
	}
}

void printBinary(int decimalNum) {
   
   if (decimalNum > 0) {
      printBinary(decimalNum / 2);
      printf("%d", decimalNum % 2);
      return;
   }
}
