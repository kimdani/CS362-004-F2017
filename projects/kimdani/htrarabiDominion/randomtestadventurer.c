#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXTESTS 1000

int main()
{
    int seed = time(NULL);
    srand(seed);
    struct gameState g;
    struct gameState gBefore;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    int i, j;
    int numPlayers;
    int currentPlayer;
    int handCountDiff;

    printf("TESTING adventurer card:\n");

    for (i = 0; i < MAXTESTS; i++)
    {
        printf("iteration #: %d\n", i + 1);
        numPlayers = rand() % (MAX_PLAYERS - 1) + 2;
        initializeGame(numPlayers, k, seed, &g);

        currentPlayer = rand() % numPlayers;
        g.whoseTurn = currentPlayer;

        // Put adventurer card in current player's hand
        g.hand[currentPlayer][0] = adventurer;
        g.handCount[currentPlayer] = rand() % MAX_HAND;
        
        // Start at j = 1 because adventurer is already the first card
        for (j = 1; j < g.handCount[currentPlayer]; j++)
        {
            g.hand[currentPlayer][j] = rand() % treasure_map;
        }

        // Save state of g in gBefore for comparison
        memcpy(&gBefore, &g, sizeof(struct gameState));

        cardEffect(adventurer, choice1, choice2, choice3, &g, handPos, &bonus);

        handCountDiff = g.handCount[currentPlayer] - gBefore.handCount[currentPlayer];
        if (handCountDiff == 2)
        {
            printf("card adventurer: PASS player gained 2 cards.\n");
        }
        else
        {
            printf("card adventurer: FAIL player did not gain 2 cards, instead gained %d cards.\n", handCountDiff);
        }

        // The 2 treasure cards from playing adventurer should be at the end/back of the player's hand
        int lastCard = g.hand[currentPlayer][g.handCount[currentPlayer] - 1];
        int secondToLastCard = g.hand[currentPlayer][g.handCount[currentPlayer] - 2];

        if (lastCard == copper || lastCard == silver || lastCard == gold)
        {
            if (secondToLastCard == copper || secondToLastCard == silver || secondToLastCard == gold)
            {
                printf("card adventurer: PASS player gained 2 treasure cards.\n");
            }
        }
        else
        {
            printf("card adventurer: FAIL player did not gain 2 treasure cards.\n");
        }
    }

    return 0;
}