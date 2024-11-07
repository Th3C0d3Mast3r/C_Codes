#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
    int* arr;
    int front;
    int back;
} Queue;

void init(Queue* q) {
    q->arr = (int*)malloc(sizeof(int)*7);           // Allocate memory for queue
    q->front = -1;
    q->back = -1;
}

void enQ(Queue* q, int x) {
    q->arr[++(q->back)] = x;
    if (q->front == -1) q->front = 0;
}

int deQ(Queue* q) {
    if (q->front == -1) {
        return -1;  // the queue is empty
    }
    int item = q->arr[q->front];
    if (q->front == q->back) {
        q->front = q->back = -1; // Reset if last item is dequeued
    } else {
        ++(q->front);
    }
    return item;
}

int nodes = 7;
int distance[7];          // Stores distance from start node
char* parent[7];          // Stores parent for each node
int visitStatus[7];       // 0 => not visited, 1 => visited, 2 => fully processed
char* locations[] = {"everett", "seattle", "north bend", "spokane", "olympia", "centralia", "portland"};
char* adjList[7][7];      // Adjacency list for graph
Queue q;                  // Queue for BFS

// Function to initialize the graph, distances, and visit statuses
void initializeGraph() {
    for (int i = 0; i < nodes; i++) {
        distance[i] = -1;  // Initialize distances to -1 (infinity)
        parent[i] = NULL;   // No parent initially
        visitStatus[i] = 0; // Mark all nodes as not visited
    }
}

// Function to fill the adjacency list (adjList)
void fillAdjList(int adjMatrix[7][7]) {
    for (int i = 0; i < nodes; i++) {
        int index = 0;
        for (int j = 0; j < nodes; j++) {
            if (adjMatrix[i][j] == 1) {
                adjList[i][index++] = locations[j];
            }
        }
        adjList[i][index] = NULL;  // Null-terminate the adjacency list
    }

    // Print adjacency list representation
    for (int i = 0; i < nodes; i++) {
        printf("%s -> ", locations[i]);
        for (int j = 0; adjList[i][j] != NULL; j++) {
            printf("%s -> ", adjList[i][j]);
        }
        printf("NULL\n");
    }
}

// Function to get the index of a location in the locations array
int indexOfLocation(char* location) {
    for (int i = 0; i < nodes; i++) {
        if (strcasecmp(locations[i], location) == 0)
            return i;
    }
    return -1;
}

// BFS algorithm implementation
void BFSalgo(int startIndex) {
    enQ(&q, startIndex);  // Enqueue the starting node
    visitStatus[startIndex] = 1;  // Mark it as visited (gray)
    distance[startIndex] = 0;     // Set distance of start node to 0

    while (q.front != -1) {
        int current = deQ(&q);  // Dequeue a node
        printf("\nCurrently processing: %s\n", locations[current]);

        // Traverse all adjacent nodes of the current node
        for (int i = 0; adjList[current][i] != NULL; i++) {
            int adjIndex = indexOfLocation(adjList[current][i]);
            if (visitStatus[adjIndex] == 0) {
                enQ(&q, adjIndex);  // Enqueue the adjacent node
                visitStatus[adjIndex] = 1;  // Mark it as visited (gray)
                distance[adjIndex] = distance[current] + 1;  // Update distance
                parent[adjIndex] = locations[current];  // Set the parent node
            }
        }
        visitStatus[current] = 2;  // Mark as fully processed (black)
    }
}

// Function to display BFS traversal results
void displayResults() {
    printf("\nFinal Results:\n");
    printf("Node            | Distance        | Parent\n");
    for (int i = 0; i < nodes; i++) {
        if(distance[i]>=0){
            printf("%-15s | %-15d | %-15s\n", locations[i], distance[i], parent[i] ? parent[i] : "NULL");
        }
        
    }
}

// Function to show unvisited nodes
void showUnvisitedNodes() {
    printf("\nUnvisited Nodes: ");
    int found = 0;
    for (int i = 0; i < nodes; i++) {
        if (visitStatus[i] == 0) {
            printf("%s | ", locations[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    // Initialize the queue
    init(&q);

    // Initialize graph and adjacency list
    initializeGraph();

    int adjMatrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0}
    };

    fillAdjList(adjMatrix);

    // Get the entry point from the user
    char entryPoint[50];
    printf("Entry Point: ");
    fgets(entryPoint, 50, stdin);
    entryPoint[strcspn(entryPoint, "\n")] = 0;  // Remove newline character

    // Find the entry point index and run BFS
    int startIndex = indexOfLocation(entryPoint);
    if (startIndex == -1) {
        printf("Invalid entry point.\n");
        return -1;
    }

    // Run BFS from the entry point
    BFSalgo(startIndex);

    // Display the BFS results
    displayResults();

    // Show any unvisited nodes
    showUnvisitedNodes();

    return 0;
}