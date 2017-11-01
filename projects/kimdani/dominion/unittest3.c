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

    printf("TESTING getCost():\n");

    int copperCost = getCost(copper);
    int silverCost = getCost(silver);
    int goldCost = getCost(gold);
    int provinceCost = getCost(province);
    int mineCost = getCost(mine);
    int salvagerCost = getCost(salvager);

    if(copperCost == 0)
    {
        printf("getCost(): PASS copper costs 0 treasure\n");
    }
    else
    {
        printf("getCost(): FAIL copper should cost 0 treasure. Instead costs %d treasure\n", copperCost);
    }

    if(silverCost == 3)
    {
        printf("getCost(): PASS silver costs 3 treasure\n");
    }
    else
    {
        printf("getCost(): FAIL silver should cost 3 treasure. Instead costs %d treasure\n", silverCost);
    }

    if(goldCost == 6)
    {
        printf("getCost(): PASS gold costs 6 treasure\n");
    }
    else
    {
        printf("getCost(): FAIL gold should cost 6 treasure. Instead costs %d treasure\n", goldCost);
    }

    if(provinceCost == 8)
    {
        printf("getCost(): PASS province costs 8 treasure\n");
    }
    else
    {
        printf("getCost(): FAIL province should cost 8 treasure. Instead costs %d treasure\n", provinceCost);
    }

    if(mineCost == 5)
    {
        printf("getCost(): PASS mine costs 5 treasure\n");
    }
    else
    {
        printf("getCost(): FAIL mine should cost 5 treasure. Instead costs %d treasure\n", mineCost);
    }

    if(salvagerCost == 4)
    {
        printf("getCost(): PASS salvager costs 4 treasure\n");
    }
    else
    {
        printf("getCost(): FAIL salvager should cost 4 treasure. Instead costs %d treasure\n", salvagerCost);
    }

    return 0;
}