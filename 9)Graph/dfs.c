// dfs program in C
#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int v);

struct Graph {
  int totalVertices;
  int* visited;
  struct node** adjLists;
};

void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("%d -> ", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}


struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->totalVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void displayGraph(struct Graph* graph) {
  int v;
  for (v = 1; v < graph->totalVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n%d =>  ", v);
    while (temp) {
      printf("%d, ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
  printf("\n");
}

int main() {

   printf("Enter number of vertices: ");
    int vertices;
    scanf("%d", &vertices);
 
    struct Graph *graph = createGraph(vertices);
 
    int choice;
    do
    {
        printf("\nWhat do you want to do? \n");
        printf(" 1. Add edge\n 2. Print graph\n 3. DFS\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice)
        {
            case 1:
                printf("Enter source and destination: ");
                int src, dest;
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                displayGraph(graph);
                break;
            case 3:
                printf("Enter starting vertex: ");
                int startVertex;
                scanf("%d", &startVertex);
                DFS(graph, startVertex);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice");
        }
    }
    while (choice != 4);
 
    return 0;
}