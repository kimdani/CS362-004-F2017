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

    printf("TESTING council_room card:\n");

    int oldHandCount = g.handCount[0];
    int oldDeckCount = g.deckCount[0];
    int oldBuyCount = g.numBuys;
    int oldPlayer2HandCount = g.handCount[1];
    int oldPlayedCardCount = g.playedCardCount;
    cardEffect(council_room, choice1, choice2, choice3, &g, handPos, &bonus);
    int newHandCount = g.handCount[0];
    int newDeckCount = g.deckCount[0];
    int newBuyCount = g.numBuys;
    int newPlayer2HandCount = g.handCount[1];
    int newPlayedCardCount = g.playedCardCount;

    int cardsGained = newHandCount - oldHandCount;
    if (cardsGained == 3)
    {
        printf("card council_room: PASS player gained %d cards (4 cards drawn and 1 council_room card discarded).\n", cardsGained);
    }
    else
    {
        printf("card council_room: FAIL player did not gain 3 cards as expected instead gained %d cards.\n", cardsGained);
    }

    int deckCardsDrawn = oldDeckCount - newDeckCount;
    if (deckCardsDrawn == 4)
    {
        printf("card council_room: PASS player drew %d card from their deck.\n", deckCardsDrawn);
    }
    else
    {
        printf("card council_room: FAIL player drew %d cards from their deck. Expected 4 instead.\n", deckCardsDrawn);
    }

    int buyCount = newBuyCount - oldBuyCount;
    if (buyCount == 1)
    {
        printf("card council_room: PASS player gained %d buys.\n", buyCount);
    }
    else
    {
        printf("card council_room: FAIL player gained %d buys. Expected 1 instead.\n", buyCount);
    }

    int player2CardsGained = newPlayer2HandCount - oldPlayer2HandCount;
    if (player2CardsGained == 1)
    {
        printf("card council_room: PASS other player gained %d card.", player2CardsGained);
    }
    else
    {
        printf("card council_room: FAIL other player gained %d cards. Expected 1 instead.\n", player2CardsGained);
    }

    int playedCards = newPlayedCardCount - oldPlayedCardCount;
    if (playedCards == 1)
    {
        printf("card council_room: PASS player played %d card from their hand.\n", playedCards);
    }
    else
    {
        printf("card council_room: FAIL player played %d cards from their hand. Expected 1 instead.\n", playedCards);
    }

    return 0;
}