#include <stdio.h>
#include <stdlib.h>
#define EDGE_WEIGHT 6
typedef struct {
    int items[10005];
    int front, rear;
} Queue;
void enqueue(Queue *q, int value) {
    q->items[++q->rear] = value;
}
int dequeue(Queue *q) {
    return q->items[++q->front];
}
int isEmpty(Queue *q) {
    return q->front == q->rear;
}
int* bfs(int n, int m, int edges[m][2], int s, int* result_size) {
    int **graph = (int **)malloc((n + 1) * sizeof(int *));
    int *sizes = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; i++)
        graph[i] = (int *)malloc(1005 * sizeof(int));  
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][sizes[u]++] = v;
        graph[v][sizes[v]++] = u;
    }
    int *dist = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
        dist[i] = -1;
    Queue q = {.front = -1, .rear = -1};
    dist[s] = 0;
    enqueue(&q, s);
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        for (int i = 0; i < sizes[node]; i++) {
            int neighbor = graph[node][i];
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + EDGE_WEIGHT;
                enqueue(&q, neighbor);
            }
        }
    }
    *result_size = n - 1;
    int *result = (int *)malloc((n - 1) * sizeof(int));
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (i != s)
            result[idx++] = dist[i];
    }
    return result;
}
