#include <stdio.h>

void addMatrices(int *mat1, int *mat2, int *result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
        {
            *(result + i * cols + j) = *(mat1 + i * cols + j) + *(mat2 + i * cols + j);
        }
    }
}

int main() {
    int r, c;
    
    printf("Enter the number of rows for the matrices: ");
    scanf("%d", &r);
    printf("Enter the number of columns for the matrices: ");
    scanf("%d", &c);
    
    int mat1[r][c], mat2[r][c], result[r][c];
    
    printf("Enter elements for the first matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    
    printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    addMatrices(&mat1[0][0], &mat2[0][0], &result[0][0], r, c);
    
    printf("Resultant matrix after addition:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
