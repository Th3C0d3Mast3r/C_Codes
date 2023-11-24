#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>

int main()
{
    int a[]={1,2,3};
    printf("%d %d", a[-1], a[4]);
    //we get some garbage value
}