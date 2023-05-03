#include <stdio.h>

int main()
{
    int i, n, factorial = 1;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);

    for(i = 1; i <= n; ++i)
    {
        factorial *= i;
    }

    printf("The factorial of %d is %d.", n, factorial);

    return 0;
}
