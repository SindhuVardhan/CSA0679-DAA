#include <stdio.h>

// Function to generate the list of all factors for a given value
void generateFactors(int n) {
    printf("Factors of %d: ", n);
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
}

// Main function
int main() {
    int n;
    
    // Read the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    // Generate the list of factors for n
    generateFactors(n);
    
    return 0;
}
