/*
Calculates the total and average of an unknown number of values until the user
enters "stop" to quit.
*/


#include <stdio.h>


int main(int argc, const char *argv[]) {
   double inputNum = 0;
   double sum = 0;
   double totalNums = 0;
   
   printf("Enter a number (or stop to quit):\n");
   int scanned = scanf("%lf", &inputNum); 
   // This stops at any character
   while (scanned == 1) {
      sum += inputNum;
      totalNums ++;
      
      printf("Enter a number (or stop to quit):\n");
      scanned = scanf("%lf", &inputNum);
   } 
   
   if (totalNums != 0) {
      printf("The sum is: %.2lf, average is: %.2lf\n", sum, (sum / totalNums));
   } else {
      printf("No sum and average calculated!\n");
   }
   
   return 0;
}
