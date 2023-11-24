#include <stdio.h>

int main() {
    int n, wSpace;
    
    printf("Enter the number of iterations that you want: \n");
    scanf("%d", &n);
    
    wSpace = n; //another variable for keeping track of whitespaces
    
    printf("THE PATTERN LOOKS LIKE:- \n\n");
    
    for (int i = 1; i <= n; i++) // Number of rows in the pattern
    {
        
        for (int j = 1; j < wSpace; j++) // For the number of leading spaces
        {
            printf("  ");
        }
        
        for (int k = 1; k <= i; k++) // Print incrementing numbers
        {
            printf("%d ", k);
        }
        
        
        for (int l=(i-1); l>=1; l--)
        {
            printf("%d ", l); // Print decrementing numbers,
        }
        
        wSpace--; // as the whitespace, down the rows, goes on decreasing
        printf("\n");
    }
}


