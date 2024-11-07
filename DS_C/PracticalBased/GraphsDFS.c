#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODES 7

typedef struct stack {
    int* arr;
    int top;
} Stack;

void init(Stack* stack) {
    stack->arr = (int*)malloc(sizeof(int) * 100);  // max stack size 100
    stack->top = -1;
}

void push(Stack* stack, int data) {
    if (stack->top == 100) {
        return;
    }
    stack->arr[++(stack->top)] = data;
}

int pop(Stack* stack) {
    if (stack->top == -1) return -1;
    return stack->arr[(stack->top)--];
}

char* locations[7] = {"everett", "seattle", "north bend", "spokane", "olympia", "centralia", "portland"};
int visitStatus[7];
char* adjList[7][7];

void fillAdjList(int adjMatrix[7][7]) {
    for (int i = 0; i < NODES; i++) {
        int index = 0;
        for (int j = 0; j < NODES; j++) {
            if (adjMatrix[i][j] == 1) {
                adjList[i][index++] = locations[j];
            }
        }
        adjList[i][index] = NULL;  // Null-terminate the list
    }
}

void DFSAlgo(int startPoint) {
    visitStatus[startPoint] = 1;
    printf("%s => ", locations[startPoint]);

    for (int i = 0; adjList[startPoint][i] != NULL; i++) {
        int adjIndex = -1;

        for (int j = 0; j < NODES; j++) {
            if (strcmp(adjList[startPoint][i], locations[j]) == 0) {
                adjIndex = j;
                break;
            }
        }
        if (visitStatus[adjIndex] == 0) {
            DFSAlgo(adjIndex);
        }
    }

    visitStatus[startPoint] = 2;  // Mark as fully processed
}

void displayAdjList() {
    for (int i = 0; i < 7; i++) {
        printf("%s -> ", locations[i]);
        for (int j = 0; adjList[i][j] != NULL; j++) {
            printf("%s -> ", adjList[i][j]);
        }
        printf("NULL\n");
    }
}


int main() {
    int adjMatrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0}
    };

    fillAdjList(adjMatrix);  // Convert adjMatrix to adjList
    displayAdjList();
    printf("\n");
    char input[50];
    printf("Entry Location: ");
    scanf("%[^\n]s", input);

    int entryPoint = -1;
    for (int i = 0; i < NODES; i++) {
        if (strcmp(input, locations[i]) == 0) {
            entryPoint = i;
            break;
        }
    }

    if (entryPoint == -1) {
        printf("Wrong Entry Point Detected!\n");
        return -1;
    }

    DFSAlgo(entryPoint);
    printf("\n");

    return 0;
}
