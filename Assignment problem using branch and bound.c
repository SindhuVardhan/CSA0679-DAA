#include <stdio.h>
#include <stdbool.h>

#define N 4 // Number of workers and tasks

// Function to find the minimum element in a row that is not assigned
int findMin(int cost[N][N], int row, bool assigned[]) {
    int minVal = 9999; // Initialize with a large value
    for (int col = 0; col < N; col++) {
        if (cost[row][col] < minVal && !assigned[col])
            minVal = cost[row][col];
    }
    return minVal;
}

// Function to find the minimum element in a column that is not assigned
int findMinInColumn(int cost[N][N], int col, bool assigned[]) {
    int minVal = 9999; // Initialize with a large value
    for (int row = 0; row < N; row++) {
        if (cost[row][col] < minVal && !assigned[row])
            minVal = cost[row][col];
    }
    return minVal;
}

// Function to calculate the lower bound cost of the assignment
int calculateCost(int cost[N][N], bool assigned[], int worker, int task) {
    int lb = 0; // Initialize lower bound cost to 0

    // Calculate the cost of assigning remaining workers to the remaining tasks
    for (int i = worker + 1; i < N; i++)
        lb += findMin(cost, i, assigned);

    // Add the cost of assigning remaining tasks to the current worker
    for (int i = task + 1; i < N; i++)
        lb += findMinInColumn(cost, i, assigned);

    return lb;
}

// Function to assign tasks to workers using Branch and Bound
void assignTasks(int cost[N][N]) {
    bool assigned[N] = { false }; // Initialize all workers as not assigned
    int assignment[N]; // Stores the assigned task for each worker
    int minCost = 0; // Initialize minimum cost to 0

    // Initialize assignment array
    for (int i = 0; i < N; i++)
        assignment[i] = -1;

    // Start with worker 0 and task 0
    int worker = 0;
    int task = 0;
    assigned[task] = true; // Assign the first task to the first worker
    assignment[worker] = task;

    while (worker < N - 1) {
        int minCostTask = -1;
        int minCostVal = 9999; // Initialize with a large value

        // Find the minimum cost task for the current worker
        for (int i = 0; i < N; i++) {
            if (!assigned[i]) {
                int costVal = cost[worker][i] + calculateCost(cost, assigned, worker, i);
                if (costVal < minCostVal) {
                    minCostVal = costVal;
                    minCostTask = i;
                }
            }
        }

        // Assign the minimum cost task to the current worker
        assigned[minCostTask] = true;
        assignment[worker + 1] = minCostTask;

        // Move to the next worker
        worker++;
        minCost += minCostVal;
    }

    // Print the assignments and the minimum cost
    printf("Assignments:\n");
    for (int i = 0; i < N; i++)
        printf("Worker %d -> Task %d\n", i, assignment[i]);
    printf("Minimum Cost: %d\n", minCost);
}

// Main function
int main() {
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    assignTasks(cost);

    return 0;
}
