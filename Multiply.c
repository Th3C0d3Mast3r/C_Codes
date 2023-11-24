// this is the first code of the day 19th October, 2023
//this is a program for Recursions
//multiply code
#include <stdio.h>
#include <stdlib.h>

int multiply(int x, int y) //this is my recursion function
{
	int mul;
	
	if(y==1)
	{
		mul=x;
	}
	else{
	mul=x+multiply(x,y-1);
	}
	
	printf("%d\n", mul);
	
	return mul;
}

int main()
{
	//this is the main function
	int a=15;
	int b=9;
	
	printf("\n\n\tFINAL ANSWER:- "multiply(a, b));


}


