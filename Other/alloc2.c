#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name {
    char *str;
};

int main() {
    struct name user_name;
    char temp_name[50]; // Temporary buffer to store user input

    printf("Enter Your Name: ");
    fgets(temp_name, sizeof(temp_name), stdin);

    // Allocate memory for the name string in the struct
    user_name.str = (char*)malloc(strlen(temp_name) + 1); // +1 for null terminator
    if (user_name.str == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1; // Return with error
    }

    // Copy the input string to the allocated memory
    strcpy(user_name.str, temp_name);

    printf("Your name is: %s", user_name.str);

    // Free the allocated memory
    free(user_name.str);

    return 0;
}