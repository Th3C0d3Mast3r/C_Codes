// this is the code for Open Hashing
// IMO, this is the best form of hashing.
// as the linking and all that it forms makes it easy
// although, access time is increased-in worst case, goes O(n*m)
// But yes, this is really good imo
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int key;
	int data;
	struct node* next;
}Node;

typedef struct hashmap{
	Node* table[10];			// my table is of 10 values, and their linking will be there as mod 10 ka logic
}HashMap;

int hashFunction(int key)
{
	return key%10;				// this will give us the value where the key should go in the thing
}

Node* createNode(int key, int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->key=key;
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

HashMap* createHashMap(){
	HashMap* hm=(HashMap*)(malloc(sizeof(HashMap)));
	for(int i=0; i<10; i++){
		hm->table[i]=NULL;		// initially sab kuch null hai
	}
	return hm;
}

bool search(HashMap* hm, int key, int data){
	int index=hashFunction(key);
	Node* temp=hm->table[index];
	while(temp!=NULL){
		if(temp->data==data){
			return true;
		}
		temp=temp->next;
	}
	return false;
}

void insert(HashMap* hm, int key, int data){
    bool numExists=search(hm, key, data);
    if(numExists){
        printf("ALREADY THERE\n");                      // agar linked list mein it exists, then no need to enter
        return;
    }
	int index=hashFunction(key);
	Node* newNode=createNode(key, data);
	newNode->next=hm->table[index];						// aage wale value pe insert
	hm->table[index]=newNode;
	printf("INSERTED %d\n", data);
}

void delete(HashMap* hm, int key, int data){
	int index = hashFunction(key);
	Node* temp = hm->table[index];
	Node* prev = NULL;

	// Traverse the linked list to find the node
	while(temp != NULL){
		if(temp->data == data){
            
			if(prev == NULL){
				hm->table[index] = temp->next;
			}
            else {
				prev->next = temp->next;
			}
			free(temp);
			printf("DELETED %d\n", data);
			return;
		}
        
		prev = temp;
		temp = temp->next;
	}
	printf("NO SUCH ELEMENT EXISTS!\n");
}

void display(HashMap* hm){
	for(int i=0; i<10; i++){
		Node* temp=hm->table[i];
		while(temp!=NULL){
			printf("%d -> ", temp->data);
			temp=temp->next;
		}
		printf("NULL");
		printf("\n");
	}
}

int main(){
	HashMap* hm=createHashMap();
    int num, key;
	while(true){
        printf("(1) INSERT VALUE\n(2) DELETE VALUE\n(3) SEARCH A NUMBER\n(4) EXIT\n");
        scanf("%d", &num);

        if(num==1){
            printf("Enter Value: ");
            scanf("%d", &num);
            insert(hm, num, num);
        }
        else if(num==2){
            printf("Enter Value: ");
            scanf("%d", &num);
            delete(hm, num, num);
        }
        else if(num==3){
            printf("Enter Value: ");
            scanf("%d", &num);
            bool isPresent=search(hm, num, num);
            if(isPresent) printf("FOUND\n");
            else printf("NOT FOUND\n");
            continue;
        }
        else break;
        display(hm);
    }

    return 0;
}