#include <stdio.h>
int main()
{
int num1, num2;
printf("This is a Code that will be used to execute ADDITION,SUBTRACTION, MULTIPLICATION, DIVISION and MODULO\n");
printf("So yes, kindly enter the First Number: ");
scanf("%d", &num1);
printf("\nKindly Enter the Second Number: ");
scanf("%d", &num2);
printf("\nThe ADDITION IS: %d", (num1+num2));
printf("\nThe SUBTRACTION IS: %d", (num1-num2));
printf("\nThe MULTIPLICATION IS: %d", num1*num2);
printf("\nThe DIVISION IS: %d", num1/num2);
printf("\nThe MODULO IS: %d", num1%num2);
return 0;
}