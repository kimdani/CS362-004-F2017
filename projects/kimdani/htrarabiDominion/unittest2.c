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
    
    printf("TESTING whoseTurn():\n");

    if (whoseTurn(&g) == 0)
    {
        printf("whoseTurn(): PASS game begins with player 0 with the first turn.\n");
    }
    else
    {
        printf("whoseTurn(): FAIL game beings with player 1 with the first turn.\n");
    }

    g.whoseTurn = 1;

    if (whoseTurn(&g) == 1)
    {
        printf("whoseTurn(): PASS it is now player 1's turn.\n");
    }
    else
    {
        printf("whoseTurn(): FAIL it is not player 1's turn.\n");
    }

    return 0;
}