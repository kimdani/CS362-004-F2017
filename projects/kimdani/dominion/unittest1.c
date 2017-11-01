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

    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    initializeGame(numPlayers, k, seed, &g);

    if(g.supplyCount[province] == 8)
    {
        printf("Game for 2 players started with 8 province cards.\n");
    }

    printf("TESTING isGameOver():\n");

    if (isGameOver(&g) == 0)
    {
        printf("isGameOver(): PASS game just started and is not over.\n");
    }
    else
    {
        printf("isGameOver(): FAIL game just started and is already over.\n");
    }

    g.supplyCount[province] = 0;
    if (isGameOver(&g) == 1)
    {
        printf("isGameOver(): PASS no province cards left and game is over.\n");
    }
    else
    {
        printf("isGameOver(): FAIL no province cards left, but game is not over.\n");
    }

    // Reset # of provinces to 8 and remove 3 stacks of kingdom cards
    g.supplyCount[province] = 8;
    g.supplyCount[adventurer] = 0;
    g.supplyCount[council_room] = 0;
    g.supplyCount[feast] = 0;

    if (isGameOver(&g) == 1)
    {
        printf("isGameOver(): PASS three kingdom card stacks are empty and game is over.\n");
    }
    else
    {
        printf("isGameOver(): FAIL three kingdom cards stacks are empty and game is not over.\n");
    }

    return 0;
}