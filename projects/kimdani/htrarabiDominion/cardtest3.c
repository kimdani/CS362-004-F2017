#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int seed = 1000;
    int numPlayers = 2;
    struct gameState g;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    initializeGame(numPlayers, k, seed, &g);

    printf("TESTING village card:\n");

    int oldHandCount = g.handCount[0];
    int oldDeckCount = g.deckCount[0];
    int oldActionCount = g.numActions;
    int oldPlayedCardCount = g.playedCardCount;
    cardEffect(village, choice1, choice2, choice3, &g, handPos, &bonus);
    int newHandCount = g.handCount[0];
    int newDeckCount = g.deckCount[0];
    int newActionCount = g.numActions;
    int newPlayedCardCount = g.playedCardCount;

    int cardsGained = newHandCount - oldHandCount;
    if (cardsGained == 0)
    {
        printf("card village: PASS player gained %d cards (1 card drawn and 1 village card discarded).\n", cardsGained);
    }
    else
    {
        printf("card village: FAIL player did not gain 0 cards as expected instead gained %d cards.\n", cardsGained);
    }

    int deckCardsDrawn = oldDeckCount - newDeckCount;
    if (deckCardsDrawn == 1)
    {
        printf("card village: PASS player drew %d card from their deck.\n", deckCardsDrawn);
    }
    else
    {
        printf("card village: FAIL player drew %d cards from their deck. Expected 1 instead.\n", deckCardsDrawn);
    }

    int actionCount = newActionCount - oldActionCount;
    if (actionCount == 2)
    {
        printf("card village: PASS player gained %d actions.\n", actionCount);
    }
    else
    {
        printf("card village: FAIL player gained %d actions. Expected 2 gained actions.\n", actionCount);
    }

    int playedCards = newPlayedCardCount - oldPlayedCardCount;
    if (playedCards == 1)
    {
        printf("card village: PASS player played %d card from their hand.\n", playedCards);
    }
    else
    {
        printf("card village: FAIL player played %d cards from their hand. Expected 1 instead.\n", playedCards);
    }

    return 0;
}