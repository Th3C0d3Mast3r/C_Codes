//this is the first code of Exp2
#include <stdio.h>
int main()
{
int marks;
printf("Kindly Enter your MARKS below, and we shall greade you based on that\a\n");
scanf("%d", &marks);
if(marks<=100)
{
if(marks>=80)
{
printf("GRADE: O");
}
else if(marks>=70 && marks<80)
{
printf("GRADE: A");
}
else if(marks>=60 && marks<70)
{
printf("GRADE: B");
}
else if(marks>=50 && marks<60)
{
printf("GRADE: C");
}
else if(marks>=40 && marks<50)
{
printf("GRADE: D");
}
else
{
printf("GRADE: F");
}
}
else

{
printf("ERROR! Marks are graded till and below 100");
}
}
