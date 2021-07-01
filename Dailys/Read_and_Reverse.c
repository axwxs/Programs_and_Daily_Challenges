/*
Purpose: Read and reverse string with character 
limit and return for reversed string
*/

#include <stdio.h>

char* reverseString(char storageString[]);

int main(int argc, char *argv[]){
    char storageString[81]; // 80 possible characters + 1 for '\0'
    char readCharacter;
   
   
    printf("Please enter a string:\n");
    int i = 0;
    while (storageString[i] != '\n' || storageString[i] != '\0'){
        readCharacter = getchar();
      
        if (readCharacter == '\n' || readCharacter == '\0' || i >= 80){
            storageString[i] = '\0';
            break;
        }
      
        storageString[i] = readCharacter;
        i++;
    }
   
    // scanf(" %c", &storageString);
    // scanf("%c", &charVariable);
   
    printf("%s\n", storageString);   // First print of string
    reverseString(storageString);    // Function call
    printf("%s\n", storageString);   // Second print of string (after reversal)
   
    return 0;   
}


/* 
Takes in the character array obtained from input as only parameter and
return a pointer the reversed array. This functions first calculates 
the array/string length and then uses that value in a for loop that 
reverse the elements in the character array by reversing the assignment 
of the indeces incrementally up to 1/2 the array/string length value.
*/
char* reverseString(char storageString[]){
    int stringCount = 0;
    int i = 0;
    char temp;
   
    // For getting the number count right for the next for loop
    while (storageString[i] != '\0'){
        i++;
    }
   
    stringCount = i;
    // printf("The length is %d\n", stringCount);
   
    /* 
    This does the actual string reversal. A temp char is needed for storage
    and it's completed halfway through the length of the string which is set 
    as the increment limit. We actually don't even need to return a data type
    for this to allow the main function to print the reversed string but
    it was specified in the instructions so there you go.
    */
    for (i=0; i<(stringCount/2); i++){
        temp = storageString[i];
        storageString[i] = storageString[stringCount-i-1];
        storageString[stringCount-i-1] = temp;
    }
   
    // printf("%s\n", storageString);
   
    return storageString; // pointer back to the reversed string  
}
