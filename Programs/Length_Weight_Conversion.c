/*
Purpose: Metric/US conversion for length and weight units
*/


#include <stdio.h>
#include <math.h>

// These are all the functions that are called by menu options
void convertLengths();
void convertWeights();
void lengthToMetric();
void lengthToUS();
void weightToMetric();
void weightToUS();

// Convert Length to Metric
void readLengthUs(int *ft, double *in);
void convertLengthToMetric(int feet, double inches, int *meters, double *centimeters);
void outputLengthMetric(int feet, int meters, double inches, double centimeters);

// Convert Length to US
void readLengthMetric(int *m, double *cm);
void convertLengthToUS(int meters, double centimeters, int *feet, double *inches);
void outputLengthUS(int feet, int meters, double inches, double centimeters);

// Convert Weight to Metric
void readWeightUS(int *lb, double *oz);
void convertWeightToMetric(int pounds, double ounces, int *kg, double *g);
void outputWeightToMetric(int pounds, int kilograms, double ounces, double grams);

// Convert Weight to US
void readWeightMetric(int *kg, double *g);
void convertWeightToUS(int kilograms, double grams, int *lb, double *oz);
void outputWeightUS(int pounds, int kilograms, double ounces, double grams);

int main(int argc, char *argv[]) {
   int userInput;
   
   // This loop is used so that the break statement for option 0 exits the program
   while(2>1) {
      printf("\n1. convert lengths\n2. convert weights\n0. Exit\n");
      printf("Please choose from (1, 2, 0):\n");
      scanf("%d", &userInput);
      
      if (userInput == 1) {
         convertLengths();
      }
      else if (userInput == 2) {
         convertWeights();
      }
      else if (userInput == 0) {
         printf("User chose to exit.\n");      
         break;
      }
   }
   return 0;   
}

/* 
This is the menu after user selects they want to convert lengths (option 1).
It works very similarly to the main function structure.
*/
void convertLengths() {
   int usrInpt;
   printf("The user wants to convert lengths.\n");
   
   while(2>1) {
      printf("\n1. convert lengths to metric\n2. convert lengths to US\n0. Return to Main Menu\n");
      printf("Please choose from (1, 2, 0):\n");
      scanf("%d", &usrInpt);
      
      if (usrInpt == 1) {
         lengthToMetric();
      }
      else if (usrInpt == 2) {
         lengthToUS();
      }
      else if (usrInpt == 0) {
         printf("User chose to go main menu.\n");      
         break;
      }
   }
   
   return;  
}

/* 
This is the menu after user selects they want to convert weights (option 2).
It works very similarly to the main function structure.
*/
void convertWeights() {
   int usrInpt;
   printf("The user wants to convert weights.\n");
   
   while(2>1) {
      printf("\n1. convert weights from pounds/ounces to kilograms/grams\n2. convert weights from kilograms/grams to pounds/ounces\n0. Return to Main Menu\n");
      printf("Please choose from (1, 2, 0):\n");
      scanf("%d", &usrInpt);
      
      if (usrInpt == 1) {
         weightToMetric();
      }
      else if (usrInpt == 2) {
         weightToUS();
      }
      else if (usrInpt == 0) {
         printf("User chose to go main menu.\n");      
         break;
      }
   }
   
   return;  
}

/*
Below are the functions that are actually used to do the conversion for lengths to metric.
It calls three functions defined below it which read input, convert the data, and output it.
*/
void lengthToMetric(){
   /*
   Below are the variables used for input and storing data. Pointers are used to convert
   the data without having a return type for the functions. At the end the top variables will
   be changed according the input by the user. The same variable setup is used in both lengthToMetric
   and lengthToUS.
   */
   
   int feet = 0;
   int meters = 0;
   double inches = 0;
   double centimeters = 0;
   
   int *ft, *m;
   double *in, *cm;
   
   ft = &feet;
   in = &inches;
   m = &meters;
   cm = &centimeters;
   
   printf("The user wants to convert length to metric.\n");
   
   readLengthUs(ft, in);
   convertLengthToMetric(feet, inches, m, cm);
   outputLengthMetric(feet, meters, inches, centimeters);
   
   return;
}

void readLengthUs(int *ft, double *in){
   
   printf("Enter feet and inches (separated by a space):\n");
   scanf("%d %lf", ft, in);
   
   return;
}

void convertLengthToMetric(int feet, double inches, int *meters, double *centimeters){
   double inchesTotal = 0, centimetersTotal = 0;
   
   inchesTotal = (feet * 12.0) + inches;
   centimetersTotal = (inchesTotal / 12.0) * .3048 * 100;
   // 0.3048 meters in a foot, 12 inches in a foor, 100 cm in a meter (duh)
   
   // This loop adds to the meters in increments and leaves the leftover for centimeters
   while (centimetersTotal >= 100){
      *meters = *meters + 1;
      centimetersTotal = centimetersTotal - 100;
   }
   
   *centimeters = centimetersTotal;
   
   
   return;
}

void outputLengthMetric(int feet, int meters, double inches, double centimeters){
   printf("%d feet and %.4lf inches converted to %d meters and %.4lf centimeters.\n", feet, inches, meters, centimeters);
}

/*
Below are the functions that are actually used to do the conversion for lengths to US.
It calls three functions defined below it which read input, convert the data, and output it.
*/
void lengthToUS(){
   /*
   Below are the variables used for input and storing data. Pointers are used to convert
   the data without having a return type for the functions. At the end the top variables will
   be changed according the input by the user. The same variable setup is used in both lengthToMetric
   and lengthToUS.
   */
   int feet = 0;
   int meters = 0;
   double inches = 0;
   double centimeters = 0;
   
   int *ft, *m;
   double *in, *cm;
   
   ft = &feet;
   in = &inches;
   m = &meters;
   cm = &centimeters;
   
   printf("The user wants to convert length to US.\n");
   
   readLengthMetric(m, cm);
   convertLengthToUS(meters, centimeters, ft, in);
   outputLengthUS(feet, meters, inches, centimeters);
   
   return;
}

void readLengthMetric(int *m, double *cm){
   
   printf("Enter meter and centimeters (separated by a space):\n");
   scanf("%d %lf", m, cm);
   
   return;
}

void convertLengthToUS(int meters, double centimeters, int *feet, double *inches){
   double inchesTotal = 0, centimetersTotal = 0;
   
   centimetersTotal = (meters * 100.0) + centimeters;
   inchesTotal = ((centimetersTotal / 100.0) / .3048) * 12.0;
   // 0.3048 meters in a foot, 12 inches in a foor, 100 cm in a meter (duh)

   // This loop adds to the feet in increments and leaves the leftover for inches
   while (inchesTotal >= 12) {
      *feet = *feet + 1;
      inchesTotal = inchesTotal - 12;
   }
   
   *inches = inchesTotal;
   
   return;  
}

void outputLengthUS(int feet, int meters, double inches, double centimeters){
   printf("%d meters and %.4lf centimeters converted to %d feet and %.4lf inches.\n", meters, centimeters, feet, inches);
   
   return;  
}

/*
Below are the functions that are actually used to do the conversion for weight to metric.
It calls three functions defined below it which read input, convert the data, and output it.
*/
void weightToMetric(){
   /*
   Below are the variables used for input and storing data. Pointers are used to convert
   the data without having a return type for the functions. At the end the top variables will
   be changed according the input by the user. The same variable setup is used in both weightToMetric
   and weightToUS.
   */
   int kilograms = 0;
   int pounds = 0;
   double grams = 0;
   double ounces = 0;
   
   int *kg, *lb;
   double *g, *oz;
   
   kg = &kilograms;
   lb = &pounds;
   g = &grams;
   oz = &ounces;
   
   printf("The user wants to convert weight to metric.\n");
   
   readWeightUS(lb, oz);
   convertWeightToMetric(pounds, ounces, kg, g);
   outputWeightToMetric(pounds, kilograms, ounces, grams);
   
   return;
}

void readWeightUS(int *lb, double *oz){
   printf("Enter pound and ounces (separated by a space).\n");
   scanf("%d %lf", lb, oz);
   
   return;   
}

void convertWeightToMetric(int pounds, double ounces, int *kg, double *g) {
   double ouncesTotal = 0, gramsTotal = 0;
   
   ouncesTotal = (pounds * 16.0) + ounces;
   gramsTotal = ((ouncesTotal / 16.0) / 2.2046) * 1000;
   // 2.2046 are pounds in a kilogram, 16 is the ounces in a pound, 1000 grams in a kilogram (duh)
   
   // This loop adds to the kilograms in increments and leaves the leftover for grams
   while (gramsTotal >= 1000) {
      *kg = *kg + 1;
      gramsTotal = gramsTotal - 1000;
   }
   
   *g = gramsTotal;
   
   return;   
}

void outputWeightToMetric(int pounds, int kilograms, double ounces, double grams) {
   printf("%d pounds and %.4lf ounces converted to %d kilograms and %.4lf grams.", pounds, ounces, kilograms, grams);
   
   return;
}

/*
Below are the functions that are actually used to do the conversion for weight to US.
It calls three functions defined below it which read input, convert the data, and output it.
*/
void weightToUS(){
   /*
   Below are the variables used for input and storing data. Pointers are used to convert
   the data without having a return type for the functions. At the end the top variables will
   be changed according the input by the user. The same variable setup is used in both weightToMetric
   and weightToUS.
   */
   int kilograms = 0;
   int pounds = 0;
   double grams = 0;
   double ounces = 0;
   
   int *kg, *lb;
   double *g, *oz;
   
   kg = &kilograms;
   lb = &pounds;
   g = &grams;
   oz = &ounces;
   
   printf("The user wants to convert weight to US.\n");
   
   readWeightMetric(kg, g);
   convertWeightToUS(kilograms, grams, lb, oz);
   outputWeightUS(pounds, kilograms, ounces, grams);
   
   return;
}

void readWeightMetric(int *kg, double *g){
   printf("Enter the kilograms and grams (separared by a space).\n");
   scanf("%d %lf", kg, g);
   
   return;
}

void convertWeightToUS(int kilograms, double grams, int *lb, double *oz){
   double ouncesTotal = 0, gramsTotal = 0;
   
   gramsTotal = (kilograms * 1000.0) + grams;
   ouncesTotal = ((gramsTotal / 1000.0) * 2.2046) * 16;
   // 2.2046 are pounds in a kilogram, 16 is the ounces in a pound, 1000 grams in a kilogram (duh)
   
   // This loop adds to the pounds in increments and leaves the leftover for ounces
   while (ouncesTotal > 16) {
      *lb = *lb + 1;
      ouncesTotal = ouncesTotal - 16;
   }
   
   *oz = ouncesTotal;
   
   return;
}
void outputWeightUS(int pounds, int kilograms, double ounces, double grams){
   printf("%d kilograms and %.4lf grams converted to %d pounds and %.4lf ounces.", kilograms, grams, pounds, ounces);
   
   return;  
}
