#include <stdio.h>

// Function to find the maximum and minimum values in a list
void findMinMax(int arr[], int low, int high, int *min, int *max) {
    int mid, min1, max1, min2, max2;

    // Base case: If the list contains only one element
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    // If the list contains two elements, compare them and assign min and max
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    // Divide the list into two halves
    mid = (low + high) / 2;
    findMinMax(arr, low, mid, &min1, &max1);
    findMinMax(arr, mid+1, high, &min2, &max2);

    // Compare the maximum values from both halves
    if (max1 > max2) {
        *max = max1;
    } else {
        *max = max2;
    }

    // Compare the minimum values from both halves
    if (min1 < min2) {
        *min = min1;
    } else {
        *min = min2;
    }
}

// Driver program to test the findMinMax function
int main() {
    int n, i;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the list:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min, max;
    findMinMax(arr, 0, n-1, &min, &max);

    printf("Minimum element is %d\n", min);
    printf("Maximum element is %d\n", max);

    return 0;
}
