#include <stdio.h>

void sieveOfEratosthenes(int n) {
    int primes[n + 1];
    for (int i = 2; i <= n; i++) {
        primes[i] = 1; // Assume all numbers are prime
    }

    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = 0; // Mark multiples of i as composite numbers
            }
        }
    }

    printf("All prime numbers up to %d are: ", n);
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    sieveOfEratosthenes(n);
    return 0;
}
