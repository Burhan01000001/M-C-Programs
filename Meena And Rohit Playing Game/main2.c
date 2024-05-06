#include <stdio.h>
#include <stdlib.h>

int main() {
    int player_1, player_2, playerTurns = 0;
    char playerOpt;

    printf("Player 1: Choose Your Number: ");
    scanf("%d", &player_1);

    printf("Player 2: Choose Your Number: ");
    scanf("%d", &player_2);

    while (1) { // Loop indefinitely
        printf("\nPlayer 1 turn, Score = %d\nPress + to increase or - to decrease your chosen number: ", player_1);
        scanf(" %c", &playerOpt);
        if (playerOpt == '+') {
            player_1 = player_1 + 1;
        } else {
            player_1 = player_1 - 1;
        }

        if (player_1 % 3 == 0) {
            printf("Congratulations! Player one won");
            break; // Exit the loop if player one wins
        }

        printf("\nPlayer 2 turn, Score = %d\nPress + to increase or - to decrease your chosen number: ", player_2);
        scanf(" %c", &playerOpt);
        if (playerOpt == '+') {
            player_2 = player_2 + 1;
        } else {
            player_2 = player_2 - 1;
        }

        if (player_2 % 3 == 0) {
            printf("Congratulations! Player two won");
            break; // Exit the loop if player two wins
        }

        playerTurns = playerTurns + 1;

        if (playerTurns >= 10) { // Maximum of 10 turns reached
            printf("No one wins after 10 turns!");
            break; // Exit the loop
        }
    }

    return 0;
}
