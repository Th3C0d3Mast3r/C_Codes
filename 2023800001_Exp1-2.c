//This is a Code for C to F conversion, up to 2-Decimal Places
#include <stdio.h>
int main()
{
printf("Hello People, welcome to the world of C\n");
printf("This is a Program for Celcius to Farenheit conversion!\n\n");
float temp;
printf("Kindly enter the Temperature in degree Celsius(only the number): ");
scanf("%f", &temp);
float tempF= (1.8*temp)+32;
printf("Voila- the temperature in fahrenheit is: %.2f", tempF);
return 0;
}