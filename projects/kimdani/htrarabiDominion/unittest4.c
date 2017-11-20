#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    int seed = 1000;
    int numPlayers = 2;
    struct gameState g;
    int maxHandCount = 5;

    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    initializeGame(numPlayers, k, seed, &g);

    printf("TESTING updateCoins():\n");

    int coppers[5];
    int silvers[5];
    int golds[5];
    int mixed[5] = {copper, silver, gold, adventurer, smithy};
    int i, j;

    for(i = 0; i < maxHandCount; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    int player;
    for (player = 0; player < numPlayers; player++)
    {
        g.handCount[player] = 5;

        for (j = 0; j < 5; j++)
        {
            g.hand[player][j] = coppers[j];
        }
        updateCoins(player, &g, 0);
        if (g.coins == 5)
        {
            printf("updateCoins(): PASS player %d has 5 treasure\n", player);
        }
        else
        {
            printf("updateCoins(): FAIL player %d should have 5 treasure, but instead has %d treasure\n", player, g.coins);
        }

        for (j = 0; j < 5; j++)
        {
            g.hand[player][j] = silvers[j];
        }
        updateCoins(player, &g, 0);
        if (g.coins == 10)
        {
            printf("updateCoins(): PASS player %d has 10 treasure\n", player);
        }
        else
        {
            printf("updateCoins(): FAIL player %d should have 10 treasure, but instead has %d treasure\n", player, g.coins);
        }

        for (j = 0; j < 5; j++)
        {
            g.hand[player][j] = golds[j];
        }
        updateCoins(player, &g, 0);
        if (g.coins == 15)
        {
            printf("updateCoins(): PASS player %d has 15 treasure\n", player);
        }
        else
        {
            printf("updateCoins(): FAIL player %d should have 15 treasure, but instead has %d treasure\n", player, g.coins);
        }

        for (j = 0; j < 5; j++)
        {
            g.hand[player][j] = mixed[j];
        }
        updateCoins(player, &g, 0);
        if (g.coins == 6)
        {
            printf("updateCoins(): PASS player %d has 6 treasure\n", player);
        }
        else
        {
            printf("updateCoins(): FAIL player %d should have 6 treasure, but instead has %d treasure\n", player, g.coins);
        }
    }

    return 0;
}