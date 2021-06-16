/*
You have purchased an expensive electronic device on the following credit plan: no down payment,
an interest rate of 18% per year (and hence 1.5% per month), and monthly payments of $50. The
monthly payment of $50 is used to pay the interest, and any remainder is applied to the principal.
Hence, if the price of the device is $1000, the first month you pay 1.5% of $1000 in interest ($15).
Then, the remaining $35 is deducted from the principal, which leaves a balance of $965. The next
month, you pay interest of 1.5% of $965.00, which is $14.48, and $35.52 (which is $50 - $14.48) is
deducted from the principal.

Write a program that will first ask the cost of the electronic device (double type, greater than
$500.00), then tell you how many months it will take to repay the load as well as the total amount
of interest paid over the life of the loan. The program should also display the exact amount of your
final payment. All money amounts should be displayed in 2 decimal places.

Be sure to use constants where appropriate. There should be no unnamed numbers in your code.
Use the const modifier to declare constants for values that do not change. The interest rate is a
good example.
*/

#include <stdio.h>

void clearKeyboardBuffer(void) {
    char ch;
	scanf("%c", &ch);
	while (ch != '\n' && ch != '\0') {
		scanf("%c", &ch);
	}
}

int main(int argc, char *argv[]) {
    double inputCost = 0.00;
    const double monthlyDeduction = 50.00;
    const double monthlyInterestRate = 0.015;
    double totalInterest = 0.00;
    double finalPayment = 0.00;
    int monthsToPayOff = 1;
    const double minThreshold = 500.00;
   
    while(inputCost <= minThreshold) {
       printf("Enter the cost (>%.2lf):\n", minThreshold);
       scanf("%lf", &inputCost);
       clearKeyboardBuffer();
    }
   
    while((inputCost + (inputCost * monthlyInterestRate)) > monthlyDeduction) {
       totalInterest = totalInterest + (inputCost * monthlyInterestRate); 
       inputCost = inputCost + (inputCost * monthlyInterestRate);
      
       inputCost = inputCost - monthlyDeduction;
       monthsToPayOff++;
      
      
     
    }
       
    totalInterest = totalInterest + (inputCost * monthlyInterestRate);
    finalPayment = inputCost + (inputCost * monthlyInterestRate) ;
   
    printf("It takes %d months to pay off the loan\n", monthsToPayOff);
    printf("The total amount of interest paid is: %.2lf.\n" , totalInterest);
    printf("The amount of final payment is: %.2lf.\n", finalPayment);
   
   
    // printf("Now you're at the next step!\n");
   
   
    return 0;  
}
