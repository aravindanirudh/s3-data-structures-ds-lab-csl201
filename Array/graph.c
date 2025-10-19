#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void BF_Traversal();
void BFS(int v);
void DF_Traversal();
void DFS(int v);
int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
int stack[MAX], top = -1;
void push(int v);
int pop();
int isEmpty_stack();
int main() {
    create_graph();
    printf("BFS Traversal:\n");
    BF_Traversal();
    printf("\nDFS Traversal:\n");
    DF_Traversal();
    return 0;
}
void create_graph() {
    int count, max_edges, origin, destin;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    max_edges = n * (n - 1);
    for (count = 1; count <= max_edges; count++) {
        printf("Enter edge %d (-1 -1 to quit): ", count);
        scanf("%d%d", &origin, &destin);
        if (origin == -1 && destin == -1)
            break;
        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid edge!\n");
            count--;
        } else {
            adj[origin][destin] = 1;
        }
    }
}
void BF_Traversal() {
    int v;
    for (v = 0; v < n; v++)
        state[v] = initial;
    printf("Enter starting vertex of BFS: ");
    scanf("%d", &v);
    BFS(v);
    printf("\n");
    }
void BFS(int v) {
    int i;
    insert_queue(v);
    state[v] = waiting;
    while (!isEmpty_queue()) {
        v = delete_queue();
        printf("%d ", v);
        state[v] = visited;
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && state[i] == initial) {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
}
void insert_queue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue overflow\n");
    else {
        if (front == -1)
            front = 0;
            rear++;
            queue[rear] = vertex;
        }
    }
int delete_queue() {
    int delete_item;
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        exit(1);
    }
    delete_item = queue[front];
    front++;
    return delete_item;
}
int isEmpty_queue() {
    return (front == -1 || front > rear);
}
void DF_Traversal() {
    int v;
    for (v = 0; v < n; v++)
        state[v] = initial;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &v);
    DFS(v);
    printf("\n");
}
void DFS(int v) {
    int i;
    push(v);
    while (!isEmpty_stack()) {
        v = pop();
        if (state[v] == initial) {
            printf("%d ", v);
            state[v] = visited;
        }
        for (i = n - 1; i >= 0; i--) {
            if (adj[v][i] == 1 && state[i] == initial) {
                push(i);
            }
        }
    }
}
void push(int v) {
    if (top == MAX - 1)
        printf("Stack overflow\n");
    else {
        top++;
        stack[top] = v;
    }
}
int pop() {
    int v;
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        v = stack[top];
        top--;
    }
    return v;
}
int isEmpty_stack() {
    return (top == -1);
}