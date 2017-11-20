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

    printf("TESTING smithy card:\n");

    int oldHandCount = g.handCount[0];
    int oldDeckCount = g.deckCount[0];
    int oldPlayedCardCount = g.playedCardCount;
    cardEffect(smithy, choice1, choice2, choice3, &g, handPos, &bonus);
    int newHandCount = g.handCount[0];
    int newDeckCount = g.deckCount[0];
    int newPlayedCardCount = g.playedCardCount;

    int cardsGained = newHandCount - oldHandCount;
    if (cardsGained == 2)
    {
        printf("card smithy: PASS player gained %d cards (3 cards drawn and 1 smithy card discarded.\n", cardsGained);
    }
    else
    {
        printf("card smithy: FAIL player did not gain 2 cards as expected instead gained %d cards.\n", cardsGained);
    }

    int deckCardsDrawn = oldDeckCount - newDeckCount;
    if (deckCardsDrawn == 3)
    {
        printf("card smithy: PASS player drew %d cards from their deck.\n", deckCardsDrawn);
    }
    else
    {
        printf("card smithy: FAIL player drew %d cards from their deck. Expected 3 instead.\n", deckCardsDrawn);
    }

    int playedCards = newPlayedCardCount - oldPlayedCardCount;
    if (playedCards == 1)
    {
        printf("card smithy: PASS player played %d card from their hand.\n", playedCards);
    }
    else
    {
        printf("card smithy: FAIL player played %d cards from their hand. Expected 1 instead.\n", playedCards);
    }

    return 0;
}