#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void printMinMaxSequence(int arr[], int size) {
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
        printf("Minimum value up to index %d: %d\n", i, min);
        printf("Maximum value up to index %d: %d\n", i, max);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the list (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the numbers in the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nMinimum and Maximum value sequence:\n");
    printMinMaxSequence(arr, size);

    return 0;
}
