#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    Edge* edges;
    int size;
} Vertex;

typedef struct {
    Vertex* vertices;
    int size;
} Graph;

void initGraph(Graph* graph, int n) {
    graph->vertices = (Vertex*)malloc(n * sizeof(Vertex));
    graph->size = n;

    int i;
    for (i = 0; i < n; i++) {
        graph->vertices[i].edges = NULL;
        graph->vertices[i].size = 0;
    }
}

void addEdge(Graph* graph, int u, int v, int w) {
    Edge edge;
    edge.vertex = v;
    edge.weight = w;

    graph->vertices[u].size++;
    graph->vertices[u].edges = (Edge*)realloc(graph->vertices[u].edges, graph->vertices[u].size * sizeof(Edge));
    graph->vertices[u].edges[graph->vertices[u].size - 1] = edge;
}

void dijkstra(Graph* graph, int n, int m, int s) {
    int* dist = (int*)malloc(n * sizeof(int));
    int* visited = (int*)malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[s - 1] = 0;

    int count, u, minDist, v, weight, newDist;
    for (count = 0; count < n - 1; count++) {
        u = -1;
        minDist = INF;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (i = 0; i < graph->vertices[u].size; i++) {
            v = graph->vertices[u].edges[i].vertex;
            weight = graph->vertices[u].edges[i].weight;

            newDist = dist[u] + weight;
            if (newDist < dist[v]) {
                dist[v] = newDist;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }

    free(dist);
    free(visited);
}

int main() {
    int n, m, s;
    Graph graph;
    scanf("%d %d %d", &n, &m, &s);
    initGraph(&graph, n);

    int i;
    for (i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(&graph, u - 1, v - 1, w);
        addEdge(&graph, v - 1, u - 1, w);
    }

    dijkstra(&graph, n, m, s);

    for (i = 0; i < n; i++) {
        free(graph.vertices[i].edges);
    }
    free(graph.vertices);

    return 0;
}