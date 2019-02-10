/*
** CARDTEST1: a test for smithy
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void smithyTest(){
    int i, j, cardsInHand, money, playedCards, card, numSmithys;
    int cardsInHandErrors = 0; 
    int discardPileErrors = 0;
    int smithyPlayCount = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState* G = malloc(sizeof(struct gameState));

    printf("Playing 100 games where Smithy is the only card played\n");
    for( i=0; i<100; ++i ){
        initializeGame(2, k, 8, G);
        numSmithys = 0;
        while( !isGameOver(G) ){
            money = 0;
            // every turn, look for smithy in player's hand and play it if we can
            for( j=0; j<numHandCards(G); ++j ){
                card = handCard(j, G);
                if( card == smithy ){
                    playCard(j, -1, -1, -1, G);
                    smithyPlayCount++;
                    // after drawing 3 and discarding 1:
                    //  the player should have 2 more cards in hand (6 total)
                    //  a smithy card should be in the discard pile
                    cardsInHand = numHandCards(G);
                    if( cardsInHand != 6 ){
                        cardsInHandErrors++;
                        printf("Expected 6 cards, actually had %d\n", cardsInHand);
                    }
                    playedCards = G->playedCardCount;
                    for( j=0; j<playedCards; ++j ){
                        if( G->playedCards[j] == smithy ){
                            break;
                        }
                        if( j == playedCards - 1 ){
                            discardPileErrors++;
                        }
                    }
                    break;
                }
            }

            // player checks their money and tries to buy something 
            for( j=0; j<numHandCards(G); ++j ){
                card = handCard(j, G);
                if( card == copper ){
                    money++;
                } else if( card == silver ){
                    money += 2;
                } else if( card == gold ){
                    money += 3;
                }
            }
            if (money >= 8) {
                buyCard(province, G);
            }
            else if (money >= 6) {
                buyCard(gold, G);
            }
            else if (money >= 4 && numSmithys < 2) {
                buyCard(smithy, G);
                numSmithys++;
            }
            else if (money >= 3) {
                buyCard(silver, G);
            }
            endTurn(G);
        }
    }

    free(G);
    printf("Smithy played %d times\n", smithyPlayCount);
    printf("Cards in hand errors: %d\n", cardsInHandErrors);
    printf("Discard pile errors: %d\n", discardPileErrors);
}

int main(){
    srand(time(NULL));
    printf("Testing smithy\n");
    printf("cardtest1.c\n");
    smithyTest();
    return 0;
}