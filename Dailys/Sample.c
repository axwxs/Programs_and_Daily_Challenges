
#include <stdio.h>

void clearKeyboardBuffer(void);

int main(int argc, char *argv[]) {
    printf("Hello Folder!");

    return 0;   
}

void clearKeyboardBuffer(void) {
    char ch;
	  scanf("%c", &ch);
    while (ch != '\n' && ch != '\0') {
	      scanf("%c", &ch);
    }
}
