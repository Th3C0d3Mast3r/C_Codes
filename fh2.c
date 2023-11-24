#include <stdio.h>
#include <string.h>
#include <ctype.h>

void adminstrator()
{
    int n1, c = 0;
    char regNo[10];
    char name[20];
    char address[80];
    char data[1000];

    FILE *fptr = fopen("vehicles.txt", "a+");

    while (c == 0) {
        printf("\n\nWHAT WOULD YOU LIKE TO DO?\n(1) MAKE ENTRY\n(2) READ DATA\n");
        scanf("%d", &n1);
        
        if (n1 == 1)
        {
        printf("\n\n(MAKING ENTRY)\n");
        
        getchar();
        printf("Enter the 8 Digit Registration Number:- ");
        scanf("%[^\n]s", regNo);
        getchar();
        
        printf("\nEnter the Name:- ");
        scanf("%[^\n]s", name);
        getchar();
        
        printf("\nEnter the ADDRESS below:- ");
        scanf("%[^\n]s", address);
        getchar();
        
        fputs("\n", fptr);    
        fputs(regNo, fptr);
        fputs(" ... ", fptr);
        fputs(name, fptr);
        fputs(" ... ", fptr);
        fputs(address, fptr);
        fputs("\n", fptr);
        
        
        printf("\n\n(ENTERED IN THE FILE!)\n");
        c+=0;
        }
        
        else if (n1 == 2) 
        {
            rewind(fptr); // Move the file pointer to the beginning
            printf("\n\n\n(READING DATA)\n");
                
            while (fgets(data, 1000, fptr)) 
            {
                printf("%s", data);
            }
            printf("\n(DATA PRINTED SUCCESSFULLY)");
            c += 0;
        } 
        
        else {
            printf("\n\n\nEXITING!");
            c++;
        }
    }

    fclose(fptr); // Close the file when done
}

void user()
{
    char data[1000];

    FILE *fptr = fopen("vehicles.txt", "r");

    printf("\n\n\n(READING DATA)\n");

    while (fgets(data, 1000, fptr)) {
        printf("%s", data);
    }

    printf("(\nDATA PRINTED SUCCESSFULLY)");

    fclose(fptr); // Close the file when done
}

int main()
{
    
    int num;
    printf("\t\t\tThis is Second Code for File-Handling!\n");
    printf("\t\t\tWELCOME TO VEHICLE REGISTRAR!\n");
    printf("Choose the Following:-\n(1) ADMINSTRATOR\n(2) USER\n");
    scanf("%d", &num);

    if (num == 1) {
        printf("\f\nWelcome Administrator!");
        adminstrator();
    } else if (num == 2) {
        printf("\nWelcome User!");
        user();
    } else {
        printf("OOPS! Something Went Wrong!\n");
        printf("SYSTEM TIMED OUT!");
    }


    return 0;
}