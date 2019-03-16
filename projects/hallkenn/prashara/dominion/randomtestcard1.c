/*
**  randomtestcard1.c: an automated random test generator for the
**  smithy card; basic testing logic carried over from assignment 3,
**  with added randomization of dependencies
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void smithyRandomTest(){
    int i, j, cardsInHand, money, playedCards, card, numSmithys, cardsInDeck, otherPlayersHand, numPlayers;
    int cardsInHandErrors = 0; 
    int discardPileErrors = 0;
    int deckErrors = 0;
    int smithyPlayCount = 0;
    int otherPlayerStateErrors = 0;
    int supplyStateErrors = 0;
    int supplyState[16]; 
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState* G = malloc(sizeof(struct gameState));

    printf("Playing 10000 games where Smithy is the only card played\n");
    for( i=0; i<10000; ++i ){
        numPlayers = rand() % 3 + 2;
        initializeGame(numPlayers, k, rand(), G);
        numSmithys = 0;
        while( !isGameOver(G) ){
            // set up turn and establish baselines for testing
            money = 0;
            if( whoseTurn(G) == 0 ){
                otherPlayersHand = G->handCount[1];
            } else {
                otherPlayersHand = G->handCount[0];
            }
            supplyState[0] = G->supplyCount[copper];
            supplyState[1] = G->supplyCount[silver];
            supplyState[2] = G->supplyCount[gold];
            supplyState[3] = G->supplyCount[estate];
            supplyState[4] = G->supplyCount[duchy];
            supplyState[5] = G->supplyCount[province];
            supplyState[6] = G->supplyCount[adventurer];
            supplyState[7] = G->supplyCount[council_room];
            supplyState[8] = G->supplyCount[feast];
            supplyState[9] = G->supplyCount[gardens];
            supplyState[10] = G->supplyCount[mine];
            supplyState[11] = G->supplyCount[remodel];
            supplyState[12] = G->supplyCount[smithy];
            supplyState[13] = G->supplyCount[village];
            supplyState[14] = G->supplyCount[baron];
            supplyState[15] = G->supplyCount[great_hall];

            // every turn, look for smithy in player's hand and play it if we can
            for( j=0; j<numHandCards(G); ++j ){
                card = handCard(j, G);
                if( card == smithy ){
                    cardsInDeck = G->deckCount[whoseTurn(G)];
                    playCard(j, -1, -1, -1, G);
                    smithyPlayCount++;
                    // after drawing 3 and discarding 1:
                    //  the player should have 2 more cards in hand (7 total)
                    //  a smithy card should be in the discard pile
                    //  the player's deck should be 3 cards shorter
                    //  no state changes for other players
                    //  no state changes for victory card piles or kingdom card piles
                    cardsInHand = numHandCards(G);
                    if( cardsInHand != 7 ){
                        cardsInHandErrors++;
                    }
                    if( G->deckCount[whoseTurn(G)] != cardsInDeck - 3 ){
                        deckErrors++;
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
                    for( j=0; j<numPlayers; ++j ){
                        if( j == whoseTurn(G) ){
                            continue;
                        } else {
                            if( otherPlayersHand != 0 ){
                                otherPlayerStateErrors++;
                            }
                        }
                    }
                    if( supplyState[0] != G->supplyCount[copper] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[1] != G->supplyCount[silver] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[2] != G->supplyCount[gold] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[3] != G->supplyCount[estate] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[4] != G->supplyCount[duchy] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[5] != G->supplyCount[province] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[6] != G->supplyCount[adventurer] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[7] != G->supplyCount[council_room] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[8] != G->supplyCount[feast] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[9] != G->supplyCount[gardens] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[10] != G->supplyCount[mine] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[11] != G->supplyCount[remodel] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[12] != G->supplyCount[smithy] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[13] != G->supplyCount[village] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[14] != G->supplyCount[baron] ){
                        supplyStateErrors++;
                    }
                    if( supplyState[15] != G->supplyCount[great_hall] ){
                        supplyStateErrors++;
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
    printf("Cards in deck errors: %d\n", deckErrors);
    printf("Discard pile errors: %d\n", discardPileErrors);
    printf("Other player state errors: %d\n", otherPlayerStateErrors);
    printf("Supply state errors: %d\n", supplyStateErrors);
}

int main(){
    srand(time(NULL));
    printf("Testing smithy\n");
    printf("randomtestcard1.c\n");
    smithyRandomTest();
    return 0;
}