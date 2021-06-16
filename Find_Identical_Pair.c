/*

Author: <Ali Rashid>
Date: <04/14/21>
Purpose: <Find identical pair>

Find the first identical pair in an array (if there is one) and output the 
index where it was found. Only finds the first identical pair after which 
the program stops running. Make sure it avoids illegal out of bounds
accessing.

*/

#include <stdio.h>

int findIdenticalPair(double arr[], int a);
/*
Please see comment on function definition for how it avoids illegal
out of bounds accessing.
*/


int main(int argc, char * argv[]) {
    double arr[10] = { 1.2, 6.1, 3.3, 3.3, 4.5, 7.9, 5.4, 5.4, 9.9, 1.0};
    
    // the array below is for testing/debugging
    // double arr2[6] = {1.2, 6.1, 3.3, 3.3, 4.5};
    
    int index = 0;
    
    // for some reason sizeof function doesn't work?
    // int length = sizeof(arr)/sizeof(arr[0]);
    
    // the below line only works in the main function for some reason
    // int length = *(&arr + 1) - arr;
    
    // all the function to get the index
    
    index = findIdenticalPair(arr, 10);
    
    
    printf("index is: %d\n", index);
    
    // below line is for debugging the second test array
    // printf("index is: %d\n", findIdenticalPair(arr2, 5));
   
    return 0;
}

/*
This function does a comparison and returns the first index of when values are equivalent
Normally I believe we are not supposed to use '==' for comparing doubles because
of rounding or something like that but for this particular function it worked fine. 

It avoids illegal out of bounds accessing by having an integer passed into the function 
which then serves as a limit for incrementation during the comparison process.
*/
int findIdenticalPair(double arr[], int a) {
    int i = 0;
    int indexValue;
   
    while (i < a) {
        if (arr[i] == arr[i+1]) {
            indexValue = i;
            return indexValue;
        }
        i++;
    }
    
    // if there's no other return value this is the default.
    return -1;   
}
