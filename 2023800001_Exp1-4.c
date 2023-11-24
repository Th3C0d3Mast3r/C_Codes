// to convert No. of Days into Year+Months+Days
#include <stdio.h>
int main()
{
int days1;
int years, months, day;
printf("This is a code for conversion of No. of DAys into Years \n");
printf("Kindly enter the NUmber of Days: \n");
scanf("%d", &days1);
if(days1<0)
{
printf("Days do No Exist in NEGATIVE NUMBERS\n");
printf("Retry if You Wish!\n\n\n\n\n");
main();
}
else
{
years=(days1/365); //to get the number of years
months=(days1-(years*365))/30; //to get the number of months
day=(days1-(years*365)-(months*30)); //to get the number of days
printf("So, as per data we see that %d days are equal to :\n", days1);
printf("YEARS: %d\n", years);
printf("MONTHS: %d\n", months);
printf("DAYS: %d", day);
printf("\n\n\nTHANK YOU FOR THE CODE ATTEMPT!");
return 0;
}
}