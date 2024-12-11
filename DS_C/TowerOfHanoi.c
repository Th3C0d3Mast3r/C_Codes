#include <stdio.h>
int counter=0;
void TowerOfHanoi(int n, char f, char t, char aux){
    counter++;
    if(n==1){
        printf("MOVE DISK 1 FROM ROD %c TO ROD %c\n", f, t);
        return;
    }

    TowerOfHanoi(n-1, f, t, aux);
    printf("MOVE DISK %d FROM ROD %c TO ROD %c\n",n, f, t);
    TowerOfHanoi(n-1, f, t, aux);
}

void main(){
    int num;
    printf("Enter the Number of Discs: ");
    scanf("%d", &num);

    TowerOfHanoi(num, 'A', 'B', 'C');
    printf("\nNumber of Steps:- %d", counter);

}