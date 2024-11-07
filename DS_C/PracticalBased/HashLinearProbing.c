#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct hashtable{
    int* arr;
    int sizeUsing;
    int size;
    int* status;        // status => 0(empty)       status => 1(present)    status=>-1 (deleted)
}HashTable;

HashTable* init(HashTable* ht, int s){
    ht->arr=(int*)malloc(sizeof(int)*s);
    ht->status=(int*)malloc(sizeof(int)*s);
    ht->size=s;
    ht->sizeUsing=0;
    return ht;
}

int hashingFunction(HashTable* ht, int num){
    return num%ht->size;
}

bool isFull(HashTable* ht){
    return ht->size == ht->sizeUsing;
}

void insert(HashTable* ht, int data){
    if (isFull(ht)){
        printf("TABLE FULL!\n");
        return;
    }
    
    int key = hashingFunction(ht, data);
    int index = key;
    
    while(ht->status[index] == 1){
        index = (index + 1) % ht->size; // Circular wrap-around
    }

    ht->arr[index] = data;
    ht->status[index] = 1;   // Mark as present
    ht->sizeUsing++;
    printf("INSERTED SUCCESSFULLY at index %d\n", index);
}

bool search(HashTable* ht, int data){
    int key = hashingFunction(ht, data);
    int index = key;

    while(ht->status[index] != 0){
        if(ht->status[index] == 1 && ht->arr[index] == data){  // Check if it's a match
            return true;
        }
        index = (index + 1) % ht->size;  // Circular wrap-around
        if(index == key) break;
    }

    return false;
}

void delete(HashTable* ht, int data){
    if (!search(ht, data)){
        printf("NO SUCH NUMBER IN HASHTABLE\n");
        return;
    }
    
    int key = hashingFunction(ht, data);
    int index = key;
    
    while(ht->arr[index] != data){
        index = (index + 1) % ht->size;  // Circular wrap-around
    }
    
    ht->status[index] = -1;  // Mark the slot as deleted
    ht->sizeUsing--;
    printf("DELETED SUCCESSFULLY\n");
}

void display(HashTable* ht){
    for (int i = 0; i < ht->size; i++){
        printf("%d: ", i);
        if(ht->status[i] == 1){
            printf("%d \n", ht->arr[i]);
        } else if(ht->status[i] == -1){
            printf("(NULL)\n");
        }
        else {
            printf("(NULL)\n");
        }
    }
}

int main(){
    HashTable ht;
    int size;
    printf("Enter Hash Table Size: ");
    scanf("%d", &size);

    init(&ht, size);
    
    while(true){
        printf("(1) INSERT\n(2) SEARCH\n(3) DELETE\n");
        scanf("%d", &size);
        if(size==1){
            printf("ENTER VALUE: ");
            scanf("%d", &size);
            insert(&ht, size);
        }
        else if(size==2){
            printf("ENTER VALUE: ");
            scanf("%d", &size);
            bool isThere=search(&ht, size);
            if(isThere) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
        else if(size==3){
            printf("ENTER VALUE: ");
            scanf("%d", &size);
            delete(&ht, size);
        }
        else break;
    }
    printf("\nTHE HASH-TABLE STATUS:- \n");
    display(&ht);
    return 1;
}