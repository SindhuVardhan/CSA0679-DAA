#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the optimal binary search tree
int optimal_bst(int *keys, int *freq, int n)
{
    // Create a 2D table to store the solutions to subproblems
    int dp[n + 1][n + 1];

    // Initialize the diagonal elements of the table
    for (int i = 0; i < n; i++)
        dp[i][i] = freq[i];

    // Fill the table in a bottom-up manner
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j; k++) {
                int cost = ((k > i) ? dp[i][k - 1] : 0) +
                           ((k < j) ? dp[k + 1][j] : 0) +
                           freq[k];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    // Return the cost of the optimal binary search tree
    return dp[0][n - 1];
}

int main()
{
    int keys[] = {10, 12, 20, 25, 30};
    int freq[] = {34, 8, 50, 5, 10};
    int n = sizeof(keys) / sizeof(keys[0]);
    int cost = optimal_bst(keys, freq, n);
    printf("Cost of Optimal BST: %d\n", cost);
    return 0;
}
