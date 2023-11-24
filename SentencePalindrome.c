#include <stdio.h>
#include <ctype.h>
#include <string.h>

void palin(char str[30]) {
    int x, count = 1;  // Initialize count to 1
    int length = strlen(str);

    for (int i = 0; i < length / 2; i++)
    {
        x = length;
        if (str[i] != str[x - i - 1]) {
            count = 0;
            break;
        }
    }

    if (count != 0) {
        printf("%s is a PALINDROME\n", str);
    }
}

int main() {
    char str1[100];
    char newString[10][30]; // Maximum alphabets that can be taken is 30

    printf("Kindly Enter a SENTENCE BELOW:-\n");
    scanf(" %[^\n]", str1); // Corrected the scanf format

    int nos = 0, j = 0;

    for (int i = 0; i <= strlen(str1); i++) {
        if (str1[i] == ' ' || str1[i] == '\0') {
            newString[nos][j] = '\0';
            nos++;
            j = 0;
        } else {
            newString[nos][j] = str1[i];
            j++;
        }
    }

    for (int i = 0; i < nos; i++) {
        palin(newString[i]);
    }
}
