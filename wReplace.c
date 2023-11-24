//this is the code for replacement
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main()
{
	char str1[100];
    	char newString[10][30];
    	char rep[30];
    	char replacer[30];
    	
	printf("Kindly Enter a SENTENCE BELOW:\n");
	scanf("%[^\n]s", str1); //this is where we take the string input
	
	
	//this is the part for the Word Extraction
	int ctr=0, j=0;
    
    for(int i=0; i<=(strlen(str1)); i++)
    {
        //if space of null is found, then assign null into the newString[ctr]
        
        if(str1[i]==' ' || str1[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;
            j=0;
        }
        
        else
        {
            newString[ctr][j]=str1[i];
            j++;
        }
    }
    
    getchar();
    
    printf("Kindly Enter a WORD TO BE REPLACED\n");
    scanf("%[^\n]s", rep);
    
    getchar();
    
    printf("Now Enter what you want to replace %s with\n", rep);
    scanf("%[^\n]s", replacer);
    
    for(int i=0; i<ctr; i++)
    {
    	if(strcmp(newString[i],rep)==0)
    	{
    		strcpy(newString[i], replacer);
    	}
    }
    printf("\n\n\n\n\tSTRING MANIPULATION IS:-\n");
    for(int i=0; i<ctr; i++)
    {
    	printf("%s ", newString[i]);
    }
}


