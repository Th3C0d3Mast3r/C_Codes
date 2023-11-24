//this is the room and tiles statement

#include <stdio.h>

int minTiles(int x, int y)
{
	if(x==0 && y==0)
	{
		return 0;
	}
	
	else if(x%2==0 && y%2==0) //this is the even even case
	{
		return minTiles(x/2, y/2);
	}
	
	else if(x%2!=0 && y%2==0) //this is the odd even case
	{
		return y + minTiles(x/2, y/2);
	}
	
	else if(x%2==0 && y%2!=0) //this is the even odd case
	{
		return x + minTiles(x/2, y/2);
	}
	
	else //this is the odd odd case 
	{
		return x + (y-1) + minTiles(x/2, y/2);
	}

}



int main()
{
	int l, b;
	printf("Length: ");
	scanf("%d", &l);
	printf("\nBreadth: ");
	scanf("%d", &b);
	
	printf("THe NO. of Required Tiles(MINIMUM) is: %d", minTiles(l,b));
}
