//fibonacci series
#include <stdio.h>

int fibonacci(int f)
{
	
	if(f==1 || f==2)
	{
		return 1;
	}
	else
	{
		return ( fibonacci(f-2) + fibonacci(f-1) );
		
	}
}

int main()
{
	int num;
	printf("this is a code for fibonacci series\n");
	printf("We will find the nth Number of the fibonacci series here\n");
	printf("\n\nENTER THE nth NUMBER HERE:");
	scanf("%d", &num); //takin the nth no. from the user
	
	printf("The %dth Term of series is: ", num);
	printf("  %d\n", fibonacci(num));
	
	printf("And the fibonacci Series is: \n\n\n");
	for(int i=1; i<=num; i++)
	{
	    printf("  %d |", fibonacci(i));
	}
}
