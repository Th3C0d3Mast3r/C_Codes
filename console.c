//this is a code for console input-output
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>

int main()
{
    char fname[]="Raju";
    char sname[]="Devesh Acharya";
    char tname[]="Lol Sike";
    char foname[]="Dhichik-Dhichik";

    //to algin from the left side
    printf("%-20s %-20s\n", fname, sname);
    printf("%-20s %-20s\n", tname, foname);
    
    //to align from right end of each string
    printf("%20s %20s\n", fname, sname);
    printf("%20s %20s\n", tname, foname);
}