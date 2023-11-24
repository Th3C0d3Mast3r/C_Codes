#include <stdio.h>

int is_prime(int x)
{
    int count = 0;

    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            count++;
        }
    }

    if (count == 2)
    {
        return 1; // x is prime
    }
    else
    {
        return 0; // x is not prime
    }
}

int main()
{
    int num1, num2;

    printf("Enter the lower Number below: ");
    scanf("%d", &num1);
    printf("Enter the Upper Limit: ");
    scanf("%d", &num2);

    printf("Prime numbers between %d and %d are:\n", num1, num2);

    for (int i = num1; i <= num2; i++)
    {
        if (is_prime(i))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
