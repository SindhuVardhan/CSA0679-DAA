#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of frequencies between i and j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

// Function to calculate the optimal cost of the binary search tree
int optimalBST(int keys[], int freq[], int n) {
    int cost[n][n]; // cost[i][j] will store the optimal cost of binary search tree from keys[i] to keys[j]
    
    // Initialize the cost matrix with INT_MAX
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = INT_MAX;
    
    // Set the diagonal elements of cost matrix as the frequency of the keys
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Calculate the optimal cost for lengths 2 to n
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in the range keys[i..j] as root
            for (int k = i; k <= j; k++) {
                int leftCost = (k > i) ? cost[i][k - 1] : 0;
                int rightCost = (k < j) ? cost[k + 1][j] : 0;
                int tempCost = leftCost + rightCost + sum(freq, i, j);

                // Update the minimum cost if needed
                if (tempCost < cost[i][j])
                    cost[i][j] = tempCost;
            }
        }
    }
    
    // Return the optimal cost of the binary search tree from keys[0] to keys[n-1]
    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 12, 20, 35};
    int freq[] = {34, 8, 50, 10};
    int n = sizeof(keys) / sizeof(keys[0]);

    int optimalCost = optimalBST(keys, freq, n);
    
    printf("Optimal Cost of Binary Search Tree: %d\n", optimalCost);
    
    return 0;
}
