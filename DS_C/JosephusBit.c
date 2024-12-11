// Josephus problem, for the jump of 2, can be done via bit manipulation
#include <stdio.h>

int JosephusProblem(int n){
    int powerOf2=1;
    while(powerOf2 < n){
        powerOf2<<=1;
    }
    powerOf2>>=1;
    return (n-powerOf2)*2+1;
}

int main(){
    int num;
    printf("Enter the Total Number of People: ");
    scanf("%d",&num);

    int ans=JosephusProblem(num);
    printf("SAFE PLACE:- %d", ans);
}

