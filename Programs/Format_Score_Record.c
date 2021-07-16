/*

Purpose: Using input ".txt" files to read and parse for relevant data which will be output to 
a file with the relevant names, quiz scores, and averages in specific formatting that had to 
pass some automated test checks.

*/

#include <stdio.h>
#include <ctype.h>

// Declarations for the two functions taking file pointers and the string appending function
void copyName(FILE *fp, FILE *fp2);
void copyScores(FILE *fp, FILE *fp2);
void appendString(char str1[], char str2[], char str3[], int size3);





int main(int argc, char *argv[1]){ // For gradebook test formatting
	// Uses argv[1] instead of actual filename because that's the only way to get input for it
	
	// int main(int argc, char *argv[]){ // For practice/debugging/general

    FILE *fp;
    FILE *fp2;
	char rScanF;
    int readChar;

    // fp = fopen(argv[1], "r"); // For gradebook test formatting
    // fp = fopen("quiz_test.txt", "r"); // For practice/debugging/general
	
	char quizFilePath[50] = /* WRITE PATH HERE */;
    fp = fopen(quizFilePath, "r"); // For practice/debugging/general


    // Checks if file opened successfully
    if(NULL == fp){
        printf("Can't open first file\n");
    }
    else {
        printf("Opened first file successfully\n");
    }

    // Checks if second file opened successfully
    fp2 = fopen("average.txt", "w");
	if(NULL == fp2){
    	printf("Can't open second file\n");
	} else {
    	printf("Opened second file successfully\n");
    }

    rScanF = fscanf(fp, "%d", &readChar);

    // Continuously calls functions to copy names and scores until reaching the end of file
    while(rScanF != EOF) {
    	copyName(fp, fp2);
        copyScores(fp, fp2);
        rScanF = fscanf(fp, "%d", &readChar);
    }

    // Closes the files for good practice
    fclose(fp);
    fclose(fp2);
    return 0;
}


/*
Takes in two file pointers. Reads the first and last name, one at a time, from the
first file which is being copied and formatted to the output file one character at a
time and then returns to the main function for the next function to be called from
where this one left off.
*/
void copyName(FILE *fp, FILE *fp2){
    /*
    Variables that are gonna be used to copy to initial strings and then put into
    string appending function.
    */
    char firstName[10];
    char lastName[10];
    char finalName[20];
    char tempCopyChar;

    int i = 0;
    int j = 0;


    fscanf(fp, "%c", &tempCopyChar);

    // firstName writing
    while(isalpha(tempCopyChar)){
        firstName[i] = tempCopyChar;
        fscanf(fp, "%c", &tempCopyChar);
        i++;
    }

	firstName[i] = '\0';

    fscanf(fp, "%c", &tempCopyChar);

    // lastName writing
    while(isalpha(tempCopyChar)){
        lastName[j] = tempCopyChar;
        fscanf(fp, "%c", &tempCopyChar);
        j++;
    }

    lastName[j] = '\0';

    // printf("Before the function: %s, %s\n", lastName, firstName); // For practice/debugging
    appendString(lastName, firstName, finalName, 20);
    // printf("After the function: %s %s %s \n", lastName, firstName, finalName); // For practice/debugging
    // printf("After the function: %s \n", finalName); // For practice/debugging

    printf("%-20s", finalName);
    fprintf(fp2, "%-20s", finalName);
    return;
}


/*
Takes in two file pointers. Reads the rest of the data, the numbers for quiz scores
in the first file being opened, and outputs it with the specified formatting to the
second output file being written to. Also uses variables which keep track of incrementation,
any possible missing quiz scores, that become zeros in the output file, and the desired average value.
*/
void copyScores(FILE *fp, FILE *fp2){
    /*
    Variables used to copy score to new file and perform necessary calculations for the averages.
    Also works to add scores of 0 when there are missing scores for a person.
    */
    int i = 0;
    double avg;
    double sum = 0.00;
    int copyScore = 0;
    int rScanf;
    int numScores = 0;
    int nullScore = 0;

    rScanf = fscanf(fp, "%d", &copyScore);


    while(rScanf == 1){
        printf("%4d", copyScore);
        fprintf(fp2, "%4d", copyScore);
        sum = sum + copyScore;
        numScores = numScores + 1;
        rScanf = fscanf(fp, "%d", &copyScore);
    }

    if(numScores < 10){
    	for(i = 0; i < (10 - numScores); ++i){
            printf("%4d", nullScore);
            fprintf(fp2, "%4d", nullScore);
        }
    }

    avg = sum / 10;
    printf("%10.2lf\n", avg);
    fprintf(fp2, "%10.2lf\n", avg);

    return;
}


/*
This is the string appneding function taken almost verbatim from the class exercise we handed in previously.
The only real difference is that it adds and comma and space to meet the formatting requirements. Works by
using the given size and to copy strings into new string and then terminate with a null character.
*/
void appendString(char str1[], char str2[], char str3[], int size3) {
    if (NULL ==  str1 || NULL == str2)
        return;
    int i = 0, j = 0;
    while (str1[i] != '\0' && i < size3 - 1) {
        str3[i] = str1[i];
        i++;
    }

    str3[i] = ',';
    i++;
    str3[i] = ' ';
    i++;

    while (str2[j] != '\0' && j < size3 - 1) {
        str3[i] = str2[j];
        i++;
        j++;
    }
    // Insert the first string in the new string
    while (str1[i] != '\0') {
        str3[i] = str2[j];
        i++;
        j++;
    }

    str3[i] = '\0';
}


