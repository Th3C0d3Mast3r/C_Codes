// NOTE:- I have not made any sort of Hash Table struct for this code. I just used some arrays and all
// To keep it basic and easy to understand!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int hashFunction(int val){
    return val%10;
}

void quadraticProbe(int table[], int key){
    int index=hashFunction(key);

    if(table[index]==-1){
        table[index]=key;
        return;
    }
    else{
        int i=1;
        while(table[(index+ (i*i)) % 10]!=-1) i++;
        table[(index + (i*i)) % 10]=key;
    } 
}

void displayHash(int table[]){
    for(int i=0; i<10; i++){
        if(table[i]==-1) printf("NULL\n");
        else printf("%d\n", table[i]);
    }
}

int main(){
    int arr[9];
    int table[10];              // the hash table
    for(int i=0; i<10; i++){
        table[i]=-1;
    }

    for(int i=0; i<9; i++){
        printf("ENTER VALUE: ");
        scanf("%d", &arr[i]);
        quadraticProbe(table, arr[i]);
    }

    displayHash(table);
}