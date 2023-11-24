//this is a code for File Handling-the PSIPL thingy

/*
Before I go ahead, this is the basics that opening in
1) "r" is for ONLY READING the contents in the file
2) "w" is for ONLY OVER-WRITING the file from the start
3) "a" is for ONLY FOR APPENDING the file 
4) "a+" is for READING and APPENDING the file. If file not there, it creates one!

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void file1()
{
    int n1;
    char data[2000];  //this is the string that would help me read the file
    char input[100]; //for appending in the file

    FILE* fptr; //this is file handling variable
    fopen("textfile1.txt", "a+"); //this is what will enable to be created in any PC that is running this code

    //now since textfile1 is a pre-existing file, the first should be Paperback or Hardback thing

    fputs("P\n\n"); //this is as per the condition of the question

    while(value==0)
    {
        printf("\n\n\nWHAT DO YOU WANT TO DO?\n(1) READ FILE\t(2) MAKE CHANGES\t(3) EXIT\n");
        scanf("%d", &n1);

        if(n1==1)
        {
            while(fgets(data, 2000, fptr))
            {
                printf("%s", data);
            }
            printf("\n\n\nTHE ABOVE WAS THE DATA IN THE FILE!\n");
            value+=0;
        }

        else if(n1==2)
        {
            printf("\n\nType the changes You Want to Edit below (we can make entry in single line only):- ");
            scanf("%[^\n]s", input); //taking the user input

            fputs(input, fptr); //entering the user input in the file
            printf("\n\n\tENTERED SUCCESSFULLY IN THE FILE");
            value+=0;
        }

        else
        {
            printf("\nEXITED THE CODE SUCCESSFULLY!");
            value+=100;
        }
    }

    return 0;
}

void file2()
{
    int n1;
    char data[2000];  //this is the string that would help me read the file
    char input[100]; //for appending in the file

    FILE* fptr; //this is file handling variable
    fopen("textfile2.txt", "a+"); //this is what will enable to be created in any PC that is running this code

    //now since textfile1 is a pre-existing file, the first should be Paperback or Hardback thing

    fputs("H\n\n");


    while(value==0)
    {
        printf("\n\n\nWHAT DO YOU WANT TO DO?\n(1) READ FILE\t(2) MAKE CHANGES\t(3) EXIT\n");
        scanf("%d", &n1);

        if(n1==1)
        {
            while(fgets(data, 2000, fptr))
            {
                printf("%s", data);
            }
            printf("\n\n\nTHE ABOVE WAS THE DATA IN THE FILE!\n");
            value+=0;
        }

        else if(n1==2)
        {
            printf("\n\nType the changes You Want to Edit below (we can make entry in single line only):- ");
            scanf("%[^\n]s", input); //taking the user input

            fputs(input, fptr); //entering the user input in the file
            printf("\n\n\tENTERED SUCCESSFULLY IN THE FILE");
            value+=0;
        }

        else
        {
            printf("\nEXITED THE CODE SUCCESSFULLY!");
            value+=100;
        }
    }

    return 0;
}

int main()
{
    int num, count=0; //for the option and loop
    printf("\t\t\tWELCOME BACK TO THE BOOK DIRECTORY\n");
    while(count<=3){
    printf("What Type of Book do You Wish to See?\n(1) PAPERBACKS\t(2) HARDBACKS: ");
    scanf("%d", &num);

    if(num==1)
    {
        printf("\nPaperBack Opening. . . . . ");
        file1();
    }

    else if(num==2)
    {
        printf("\nHardback Opening. . . . . ");
        file2();
    }

    else
    {
        printf("\n\n\nOops! Wrong Choice");
        printf("Try Again!");
    }
    }


}*/
