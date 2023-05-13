#include <stdio.h>

int binomialCoeff(int n, int k) {
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void printPascalTriangle(int n) {
    for (int line = 0; line < n; line++) {
        // Print spaces to align the triangle
        for (int i = 0; i < n - line - 1; i++)
            printf(" ");
            
        for (int i = 0; i <= line; i++)
            printf("%d ", binomialCoeff(line, i));
        
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &n);

    printPascalTriangle(n);
    
    return 0;
}
