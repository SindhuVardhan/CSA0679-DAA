#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Function to check if the vertex v can be added at index 'pos' in the path
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Function to print the Hamiltonian circuit
void printPath(int path[]) {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d", path[0]); // Print the first vertex again to complete the cycle
    printf("\n");
}

// Function to find the Hamiltonian circuit
bool hamiltonianCircuitUtil(bool graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
        // And if there is an edge from the last vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as the next candidate in Hamiltonian circuit
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recursive call to check the next vertex
            if (hamiltonianCircuitUtil(graph, path, pos + 1) == true)
                return true;

            // If adding the vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }

    return false;
}

// Function to find and print the Hamiltonian circuit, if exists
void hamiltonianCircuit(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from vertex 0 as the first vertex in the path
    path[0] = 0;

    if (hamiltonianCircuitUtil(graph, path, 1) == false)
        printf("No Hamiltonian Circuit exists\n");
    else
        printPath(path);
}

// Main function
int main() {
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCircuit(graph);

    return 0;
}
