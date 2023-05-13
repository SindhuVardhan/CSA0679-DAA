#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool isSafe(int vertex, int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int color[], int currentColor) {
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && color[i] == currentColor) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int m, int color[], int vertex) {
    if (vertex == vertices) {
        return true;
    }

    for (int currentColor = 1; currentColor <= m; currentColor++) {
        if (isSafe(vertex, graph, vertices, color, currentColor)) {
            color[vertex] = currentColor;

            if (graphColoringUtil(graph, vertices, m, color, vertex + 1)) {
                return true;
            }

            color[vertex] = 0; // backtrack
        }
    }

    return false;
}

bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int m) {
    int color[MAX_VERTICES] = {0};

    if (!graphColoringUtil(graph, vertices, m, color, 0)) {
        printf("No solution exists for the given graph and number of colors.\n");
        return false;
    }

    printf("Graph Coloring Solution:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }

    return true;
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices, edges, m;

    printf("Enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the adjacency matrix representation of the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors available: ");
    scanf("%d", &m);

    graphColoring(graph, vertices, m);

    return 0;
}
