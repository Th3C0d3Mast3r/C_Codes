#include <stdio.h>
#include <stdlib.h>

int main()
{
int inp;//for no. of loops
char symb;
printf("Welcome to the Pattern Making Code!\n");
printf("In this Code we will be making Pattern with Your
SYMBOL!\nEnter Your Symbol Below:\n\a");
scanf(" %c", &symb);
printf("Kindly Enter the Number of Lines of Pattern You Want: \n\a");
scanf("%d", &inp);
printf("\n\n\n\n");
char s=symb; //copy of the symbols
for(int i=1; i<=inp; i++) // outer loop
{
for(int j=1; j<=i; j++) // inner loop
{
printf(" %c", s);
}
printf("\n");
}
return 0;
}
