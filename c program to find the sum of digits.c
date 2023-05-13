#include <stdio.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10; // Get the rightmost digit
        sum += digit; // Add the digit to the sum
        num /= 10; // Remove the rightmost digit
    }
    return sum;
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    int sum = sumOfDigits(num);

    printf("The sum of digits of %d is: %d\n", num, sum);

    return 0;
}
