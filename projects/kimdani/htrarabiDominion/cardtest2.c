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

    printf("TESTING adventurer card:\n");

    int oldTreasureCount = 0;
    int newTreasureCount = 0;
    int oldHandCount = g.handCount[0];
    int oldPlayedCardCount = g.playedCardCount;
    int i, j;

    for (i = 0; i < oldHandCount; i++)
    {
        if (g.hand[0][i] == copper || g.hand[0][i] == silver || g.hand[0][i] == gold)
        {
            oldTreasureCount++;
        }
    }
    
    cardEffect(adventurer, choice1, choice2, choice3, &g, handPos, &bonus);
    
    int newHandCount = g.handCount[0];
    int newPlayedCardCount = g.playedCardCount;

    int cardsGained = newHandCount - oldHandCount;
    if (cardsGained == 1)
    {
        printf("card adventurer: PASS player gained %d cards (2 treasure cards drawn and 1 adventurer card discarded.\n", cardsGained);
    }
    else
    {
        printf("card adventurer: FAIL player did not gain 1 card as expected instead gained %d cards.\n", cardsGained);
    }

    for (j = 0; j < newHandCount; j++)
    {
        if (g.hand[0][i] == copper || g.hand[0][i] == silver || g.hand[0][i] == gold)
        {
            newTreasureCount++;
        }
    }

    int treasureGained = newTreasureCount - oldTreasureCount;
    if (treasureGained == 2)
    {
        printf("card adventurer: PASS player gained %d treasure cards.\n", treasureGained);
    }
    else
    {
        printf("card adventurer: FAIL player did not gain 2 treasure cards as expected instead gained %d treasure cards.\n", treasureGained);
    }

    int playedCards = newPlayedCardCount - oldPlayedCardCount;
    if (playedCards == 1)
    {
        printf("card adventurer: PASS player played %d card from their hand.\n", playedCards);
    }
    else
    {
        printf("card adventurer: FAIL player played %d cards from their hand. Expected 1 instead.\n", playedCards);
    }

    return 0;
}