#include <stdio.h>

int main() {
    int i, j, isPrime;

    printf("Prime numbers between 1 to 100:\n");

    // Loop through numbers from 1 to 100
    for (i = 2; i <= 100; i++) {
        // Assume the number is prime
        isPrime = 1;

        // Check if the number is divisible by any number other than 1 and itself
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        // If the number is prime, print it
        if (isPrime == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}
