#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void buffer() {
    int n = 0;
    printf("Wait For Approval");
    fflush(stdout); // Flush the output buffer to ensure "Wait For Approval" is printed immediately
    while (n < 5) {
        sleep(1);
        printf("\r   "); // Clear previous three dots
        fflush(stdout); // Flush the output buffer to clear the dots
        sleep(1);
        printf("\r..."); // Add three dots
        fflush(stdout); // Flush the output buffer to print the dots
        n++;
    }
    printf("\n"); // Add a newline after finishing the loop
}

int main() {
    buffer();
    return 0;
}