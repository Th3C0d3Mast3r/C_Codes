//this is the first code for the Filehandling in C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void file_operations(FILE *fptr); //this is a function declaration

void file1()
{
    FILE *fptr = fopen("textfile1.txt", "a+"); //fptr is a pointer to the file1

    rewind(fptr);  // Move the file pointer to the beginning
    fputs("P\n\n", fptr);

    file_operations(fptr);

    fclose(fptr); //close the file
}

void file2() 
{
    FILE *fptr = fopen("textfile2.txt", "a+"); //this is a pointer to the second file

    rewind(fptr);  // Move the file pointer to the beginning
    fputs("H\n\n", fptr);

    file_operations(fptr);

    fclose(fptr);
}

void file_operations(FILE *fptr) {
    int n1;
    char data[2000];
    char input[100];

    while (1)
    {
        printf("\n\n\nWHAT DO YOU WANT TO DO?\n(1) READ FILE\t(2) MAKE CHANGES\t(3) EXIT\n");
        scanf("%d", &n1);

        if (n1 == 1) 
        {
            rewind(fptr);  // Move the file pointer to the beginning
            while (fgets(data, 2000, fptr)) {
                printf("%s", data);
            }
            printf("\n\n\nTHE ABOVE WAS THE DATA IN THE FILE!\n");
        } 
        
        else if (n1 == 2) 
        {
            printf("\n\nType the changes You Want to Edit below (we can make entry in a single line only):- ");
            scanf(" %[^\n]s", input); // Note the space before %[^\n]s
            fputs(input, fptr);
            printf("\n\n\tENTERED SUCCESSFULLY IN THE FILE");
        } 
        
        else 
        {
            printf("\nEXITED THE CODE SUCCESSFULLY!");
            break;
        }
    }
}

int main() {
    int num, count = 0;
    printf("\t\t\tWELCOME BACK TO THE BOOK DIRECTORY\n");

    while (count <= 3)
    {
        printf("What Type of Book do You Wish to See?\n(1) PAPERBACKS\t(2) HARDBACKS: ");
        scanf("%d", &num);

        if (num == 1) 
        {
            printf("\nPaperBack Opening. . . . . ");
            file1();
        } 
        
        else if (num == 2) 
        {
            printf("\nHardback Opening. . . . . ");
            file2();
        } 
        
        else
        {
            printf("\n\n\nOops! Wrong Choice");
            printf("Try Again!");
        }

        count++;
    }

    return 0;
}