#include <stdio.h>
#include <stdlib.h>

int main()
{
    int player_1, player_2, playerTurns = 0;
    char playerOpt;

    printf("Player 1: Choose Your Number: ");
    scanf("%d", &player_1);

    printf("Player 2: Choose Your Number: ");
    scanf("%d", &player_2);

    while (playerTurns <= 10)
    {
        printf("\nPlayer 1 turn, Score = %d\nPress + to increase or - to decrease your choosen number: ", player_1);
        scanf("%c", &playerOpt);
        if (playerOpt == '+')
        {
            player_1 = player_1 + 1;
        }
        else
        {
            player_1 = player_1 - 1;
        }

        if (player_1 % 3 == 0)
        {
            printf("Cogratulations! Player one won");
            exit(0);
        }

        printf("\nPlayer 2 turn, Score = %d\nPress + to increase or - to decrease your choosen number: ", player_2);
        scanf("%d", playerOpt);
        if (playerOpt == '+')
        {
            player_2 = player_2 + 1;
        }
        else
        {
            player_2 = player_2 - 1;
        }

        if (player_2 % 3 == 0)
        {
            printf("Cogratulations! Player one won");
            exit(0);
        }

        playerTurns = playerTurns + 1;
    }

    return 0;
}