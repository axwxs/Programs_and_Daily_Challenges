/*
Purpose: Return yesterday's date using struct data type. 
I believe it only works for the year 2021. However you 
can just update today.year if need be.
*/

#include <stdio.h>

// Used the leap year by default apparently which had to be changed to for test 4's function
const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*

typedef struct date {
   int month;
   int day;
   int year;
} Date;

*/

struct date {
    int month;
    int day;
    int year;
};
typedef struct date Date;

// Seems like this has to below the date structure definition or it will give many errors
Date getYesterdayDate(Date today);

int main(int argc, char *argv[]){
    Date today;
    Date yesterday;
    today.year = 2021;
   
    printf("Please enter a month (1~12):\n");
    scanf("%d", &today.month);
    printf("Please enter a valid day in the month:\n");
    scanf("%d", &today.day);
   
    printf("Today is: %d/%d/%d\n", today.month, today.day, today.year);
    yesterday = getYesterdayDate(today);
    printf("Yesterday is: %d/%d/%d\n", yesterday.month, yesterday.day, yesterday.year);

    return 0;  
}



/*
Initializes yesterday Date variable and first checks if the input date was close 
enough to push back a year (and month), just a month, or only the day. Then 
performs incremental substractions as appropriate. 
*/
Date getYesterdayDate(Date today){
	Date yesterday;
   
    // yesterday.year = today.year;
   
    if (today.day == 1 && today.month == 1) {
        yesterday.month = 12;
        yesterday.day = daysInMonth[11];
        yesterday.year = today.year - 1;
    }
   
    else if (today.day == 1){
        yesterday.month = today.month - 1;
        yesterday.day = daysInMonth[yesterday.month - 1];
        yesterday.year = today.year;
    }  
   
    else {
        yesterday.month = today.month;
        yesterday.day = today.day - 1;
        yesterday.year = today.year;
    }
      
    // printf("Yesterday is: %d/%d/%d\n", yesterday.month, yesterday.day, yesterday.year);
   
    return yesterday;  
}
