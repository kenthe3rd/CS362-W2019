/*
** UNITTEST1: a test for numHandCards
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void numHandCardsTest(){
    int cardsInHand;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState* G = malloc(sizeof(struct gameState));
    
    initializeGame(2, k, 9, G);
    printf("At initializeGame, numHandCards should be 5.\n");
    cardsInHand = numHandCards(G);
    if( cardsInHand == 5 ){
        printf("PASSED\n");
    } else {
        printf("FAILED, with a value of %d\n", cardsInHand);
    }

    drawCard(G->whoseTurn, G);
    printf("After drawing, numHandCards should be 6.\n");
    cardsInHand = numHandCards(G);
    if( cardsInHand == 6 ){
        printf("PASSED\n");
    } else {
        printf("FAILED, with a value of %d\n", cardsInHand);
    }

    discardCard(0, G->whoseTurn, G, 1);
    discardCard(0, G->whoseTurn, G, 1);
    printf("After discarding two cards, numHandCards should be 4.\n");
    cardsInHand = numHandCards(G);
    if( cardsInHand == 4 ){
        printf("PASSED\n");
    } else {
        printf("FAILED, with a value of %d\n", cardsInHand);
    }

    endTurn(G);
    printf("After ending the player's turn, numHandCards should be 5 for next player's start of turn\n");
    cardsInHand = numHandCards(G);
    if( cardsInHand == 5 ){
        printf("PASSED\n");
    } else {
        printf("FAIELD, with a value of %d\n", cardsInHand);
    }
}

int main(){
    printf("Testing numHandCards\n");
    printf("unittest1.c\n");
    numHandCardsTest();
    return 0;
}