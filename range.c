#include <stdio.h>

int prime(int x)
{
	int count=0;

	for(int i=2; i<=x; i++)
	{
		if(i%x==0)
		{
			count++;
		}
	}

	if(count==2)
	{
		return x;
	}
}

int main()
{
	int num1, num2;
	
	printf("Enter the lower Number below: ");
	scanf("%d", &num1);
	printf("Enter the Upper Limit");
	scanf("%d", &num2);

	for(int i=num1; i<=num2; i++)
	{
		prime(i);
	}
}