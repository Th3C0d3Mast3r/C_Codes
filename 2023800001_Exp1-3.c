// to convert feet into metre
#include <stdio.h>
int main()
{
float lengthF, lengthM;
printf("This is a code for conversion of the Foot into metre \n");
printf("Kindly enter the length in foot below:\n");
scanf("%f", &lengthF);
if(lengthF<0)
{
printf("The Input Length is NEGATIVE\n");
printf("And the Fact that Length can't be negative-so please retry\n\n\n\n");
main();
}
else
{
lengthM= (lengthF/3.281);
printf("The FInal length in Metre: %.3f", lengthM);
return 0;
}
}