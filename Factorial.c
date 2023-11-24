#include <stdio.h>

int fact(int f)
{
    if (f == 0 || f == 1)
    {
        return 1; // The factorial of 0 and 1 is 1.
    }
    else
    {
        return f * fact(f - 1); // Recursively calculate the factorial.
    }
}

int main()
{
    int num;
    printf("ENTER THE NUMBER HERE: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        printf("Factorial of %d is %d\n", num, fact(num));
    }

    return 0;
}
