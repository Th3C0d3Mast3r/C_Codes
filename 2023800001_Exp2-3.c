//this is E2 P3
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num, temp, temp2;
    int arm = 0; // Initialize arm to 0 for the Armstrong Number
    int i = 0;   // for counter

    printf("This is the Code for ARMSTRONG NUMBERS!\n");
    printf("Kindly Enter a Number below, and we will check for ARMSTRONG!\n\a");
    scanf("%d", &num);
    
    if(num>=0)
    {
    temp = num;
    while (temp != 0)
    {
        temp = temp / 10;
        i++; // this would give us the number of digits in input!
    }

    temp = num; // reassign temp its value so as to keep the og input as num only!
    
    while (temp != 0)
    {
        temp2 = temp % 10;
        arm += pow(temp2, i);
        temp /= 10; //this is the while construct condition checker
    }

    if (arm == num) //the reason we did not touch num is because we want to compare here
    {
        printf("\n\n\n\n\t\tARMSTRONG NUMBER!\a");
    }
    else
    {
        printf("\n\n\n\n\n\t\tNOT ARMSTRONG!\a");
    }
}
    
    else
    {
        printf("Oops! Something Went Wrong!\n\a");
        printf("Retry with a POSITIVE WHOLE NUMBER\n\n\n\n\n");
        main();
    }
    return 0;
}