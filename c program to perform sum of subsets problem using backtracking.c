#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isSubsetSum(int set[], int n, int targetSum) {
    if (targetSum == 0)
        return true;

    if (n == 0)
        return false;

    if (set[n - 1] > targetSum)
        return isSubsetSum(set, n - 1, targetSum);

    return isSubsetSum(set, n - 1, targetSum) || isSubsetSum(set, n - 1, targetSum - set[n - 1]);
}

void printSubset(int set[], bool subset[], int size) {
    printf("Subset: ");
    for (int i = 0; i < size; i++) {
        if (subset[i]) {
            printf("%d ", set[i]);
        }
    }
    printf("\n");
}

void subsetSum(int set[], int n, int targetSum) {
    bool subset[MAX_SIZE] = {false};

    if (isSubsetSum(set, n, targetSum)) {
        printSubset(set, subset, n);
    } else {
        printf("No subset with the given sum exists.\n");
    }
}

int main() {
    int set[MAX_SIZE];
    int n, targetSum;

    printf("Enter the size of the set (maximum %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    subsetSum(set, n, targetSum);

    return 0;
}
