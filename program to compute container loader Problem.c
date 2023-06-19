#include <stdio.h>
#include <stdbool.h>

#define MAX_CONTAINERS 100 // Maximum number of containers
#define MAX_CAPACITY 100 // Maximum capacity of each container

// Function to perform First Fit Decreasing (FFD) algorithm for container loading
void containerLoader(int containers[], int numContainers, int capacity) {
    int bins[MAX_CONTAINERS]; // Stores the current load of each bin
    int numBins = 0; // Number of bins used

    // Sort the containers in non-increasing order
    for (int i = 0; i < numContainers - 1; i++) {
        for (int j = 0; j < numContainers - i - 1; j++) {
            if (containers[j] < containers[j + 1]) {
                int temp = containers[j];
                containers[j] = containers[j + 1];
                containers[j + 1] = temp;
            }
        }
    }

    // Initialize the first bin
    bins[numBins++] = capacity;

    // Place each container into a bin using First Fit Decreasing algorithm
    for (int i = 0; i < numContainers; i++) {
        bool placed = false;

        // Try to place the container in each bin
        for (int j = 0; j < numBins; j++) {
            if (containers[i] <= bins[j]) {
                bins[j] -= containers[i];
                placed = true;
                break;
            }
        }

        // If the container cannot be placed in any existing bin, create a new bin
        if (!placed) {
            bins[numBins++] = capacity - containers[i];
        }
    }

    // Print the number of bins used and the load of each bin
    printf("Number of bins required: %d\n", numBins);
    for (int i = 0; i < numBins; i++) {
        printf("Bin %d: Load = %d\n", i + 1, capacity - bins[i]);
    }
}

// Main function
int main() {
    int containers[MAX_CONTAINERS]; // Stores the sizes of containers
    int numContainers; // Number of containers
    int capacity; // Capacity of each container

    // Read the number of containers and the capacity of each container
    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);
    printf("Enter the capacity of each container: ");
    scanf("%d", &capacity);

    // Read the sizes of the containers
    printf("Enter the sizes of the containers:\n");
    for (int i = 0; i < numContainers; i++) {
        printf("Container %d: ", i + 1);
        scanf("%d", &containers[i]);
    }

    // Perform the container loading
    containerLoader(containers, numContainers, capacity);

    return 0;
}
