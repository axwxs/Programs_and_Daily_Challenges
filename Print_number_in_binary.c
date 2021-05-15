
#include <stdio.h>

void printBinary(int decimalNum);
void clearKeyboardBuffer(void);

int main(int argc, char *argv[]) {
   
   int decimalNum;
   printf("Enter an integer:\n");
   scanf("%d", &decimalNum);
   clearKeyboardBuffer();
   
   if (decimalNum == 0) {
      printf("%d", decimalNum);
   }
   
   else {
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
