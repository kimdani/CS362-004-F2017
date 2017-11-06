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

    int i, j, l;
    int numPlayers;
    int currentPlayer;
    int handCountDiff;
    int deckCountDiff;

    printf("TESTING smithy card:\n");

    for (i = 0; i < MAXTESTS; i++)
    {
        printf("iteration #: %d\n", i + 1);
        numPlayers = rand() % (MAX_PLAYERS - 1) + 2;
        initializeGame(numPlayers, k, seed, &g);

        currentPlayer = rand() % numPlayers;
        g.whoseTurn = currentPlayer;

        // Put smithy card in current player's hand
        g.hand[currentPlayer][0] = smithy;
        g.handCount[currentPlayer] = rand() % MAX_HAND;
        g.deckCount[currentPlayer] = rand() % MAX_DECK;
        
        // Start at j = 1 because smithy is already the first card
        for (j = 1; j < g.handCount[currentPlayer]; j++)
        {
            g.hand[currentPlayer][j] = rand() % treasure_map;
        }

        for (l = 0; l < g.deckCount[currentPlayer]; l++)
        {
            g.deck[currentPlayer][l] = rand() % treasure_map;
        }

        // Save state of g in gBefore for comparison
        memcpy(&gBefore, &g, sizeof(struct gameState));

        cardEffect(smithy, choice1, choice2, choice3, &g, handPos, &bonus);

        handCountDiff = g.handCount[currentPlayer] - gBefore.handCount[currentPlayer];
        if (handCountDiff == 3)
        {
            printf("card smithy: PASS player gained 3 cards.\n");
        }
        else
        {
            printf("card smithy: FAIL player did not gain 3 cards.\n");
        }

        deckCountDiff = gBefore.deckCount[currentPlayer] - g.deckCount[currentPlayer];
        printf("deckCountDiff = %d\n", deckCountDiff);
        if (deckCountDiff == 3)
        {
            printf("card smithy: PASS player drew 3 cards from their deck.\n");
        }
        else
        {
            printf("card smithy: FAIL player did not draw 3 cards from their deck.\n");
        }
    }

    return 0;
}