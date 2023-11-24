#include <stdio.h>
#include <ctype.h>

int main()
{
    int num;
    printf("This is a code that is for Sorting the names in ascending order\n");
    printf("Enter how many names you want to enter and sort: ");
    scanf("%d", &num);

    char str[20][num];

    for(int i=0;i<num;i++)
    {
    printf("\nNow Enter name %d below:\n", (i+1));
    scanf("%[^\n]s", str[][i]);
    }

    for(int j=0;j<num;j++) //this would convert all of the names to lower case
    {
        for(int k=0;k<20;k++)
        {
            str[k][j]=tolower(str[k][j]);
        }
    }
}