//this is the code for MULTIPLICATION

#include <stdio.h>


int main()
{
    int r1,c1,r2,c2;
    printf("This is an array based problem of multidimensional arrays\n");
    printf("Kindly Enter the number of rows for MATRIX 1:\n");
    scanf("%d", &r1);
    printf("Enter the Number of Columns of MATRIX 1:\n");
    scanf("%d", &c1);
    printf("\n\n\n\n");
    
    printf("Kindly Enter the number of rows for MATRIX 2:\n");
    scanf("%d", &r2);
    printf("Enter the Number of Columns of MATRIX 2:\n");
    scanf("%d", &c2);
    if(c1==r2) //condition check
    {
    int mat1[r1][c1];
    int mat2[r2][c2];
    
    
    //for matrix 1
    printf("Enter terms in MATRIX 1 BELOW:");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    
    //now for matrix 2
    printf("\n\n\n\nEnter terms in MATRIX 2 BELOW:");
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    int result[r1][c2];//dimesions of the resultant array
    
        //for array multiplication
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c2;j++)
            {
                for(int k=0;k<c1;k++)
                {
                    *(*(result+i)+j)+= *(*(mat1+i)+k) *  *(*(mat2+k)+j);
                }
            }
        }
        
        printf("\n\n\n\nThe Resultant MATRIX is:- \n");
        for(int i=0;i<r1;i++)// for printing the final answer
        {
            for(int j=0;j<c2;j++)
            {
                printf("%d", result[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\n\n\n\n\n\t\tMATRIX MULTIPLICATION NOT POSSIBLE");
    }
}