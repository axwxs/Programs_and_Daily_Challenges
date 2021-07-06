/*
Purpose: <Output negative number from input>
*/

#include <stdio.h>

void clearKeyboardBuffer(void);


int getNegInt() {
    int varInt = 1;
    printf("Please enter a negative number:\n");
    
    while(varInt >= 0) {
    scanf("%d", &varInt);
    clearKeyboardBuffer();
        if(varInt >=0) {
            printf("I'm sorry, you must enter a negative integer less than zero:\n");
        }
    }

    printf("I got the number %d!\n", varInt);
    return varInt;
   
}

int main(int argc, char *argv[]) {
    getNegInt();
    
    // int varInt = getNegInt();
    // printf("%d\n", varInt);

    return 0;   
}

void clearKeyboardBuffer(void) {
    char ch;
    scanf("%c", &ch);
    while (ch != '\n' && ch != '\0') {
	      scanf("%c", &ch);
    }
}
