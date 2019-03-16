/*
** CARDTEST3: a test for village
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void villageTest(){
    int i, j, k, numVillages, otherPlayersHand, money, card, cardsInDeck, villagesInDiscard1, villagesInDiscard2;
    int villagePlayCount = 0; 
    int cardsInHandErrors = 0; 
    int deckErrors = 0; 
    int discardPileErrors = 0; 
    int otherPlayerStateErrors = 0;
    int supplyStateErrors = 0; 
    int actionErrors = 0;
    int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int supplyState[16];
    struct gameState* G = malloc(sizeof(struct gameState));
    
    printf("Playing 100 games where Village is the only card played\n");
    for( i=0; i<100; ++i ){
        initializeGame(2, kingdom, 8, G);
        numVillages = 0;
        while( !isGameOver(G) ){
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
            for( j=0; j<numHandCards(G); ++j ){
                card = handCard(j, G);
                if( card == village ){
                    villagesInDiscard1 = 0;
                    for( k=0; k<G->playedCardCount; ++k ){
                        if( G->playedCards[k] == village ){
                            villagesInDiscard1++;
                        }
                    }
                    cardsInDeck = G->deckCount[whoseTurn(G)];
                    playCard(j, -1, -1, -1, G);
                    villagePlayCount++;
                    if( numHandCards(G) != 5 ){
                        cardsInHandErrors++;
                    }
                    if( G->numActions != 2 ){
                        actionErrors++;
                    }
                    villagesInDiscard2 = 0;
                    for( k=0; k<G->playedCardCount; ++k ){
                        if( G->playedCards[k] == village ){
                            villagesInDiscard2++;
                        }
                    }
                    if( villagesInDiscard1 != villagesInDiscard2 - 1 ){
                        discardPileErrors++;
                    }
                    if( G->deckCount[whoseTurn(G)] != cardsInDeck - 1 ){
                        deckErrors++;
                    }
                    if( otherPlayersHand != 0 ){
                        otherPlayerStateErrors++;
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
            } else if (money >= 6) {
                buyCard(gold, G);
            } else if (money >= 3 && numVillages < 2 ){
                buyCard(village, G);
                numVillages++;
            } else if (money >= 3) {
                buyCard(silver, G);
            }
            endTurn(G);            
        }
    }
    free(G);
    printf("village played %d times\n", villagePlayCount);
    printf("Cards in hand errors: %d\n", cardsInHandErrors);
    printf("Cards in deck errors: %d\n", deckErrors);
    printf("Discard pile errors: %d\n", discardPileErrors);
    printf("Other player state errors: %d\n", otherPlayerStateErrors);
    printf("Supply state errors: %d\n", supplyStateErrors);
    printf("Action errors: %d\n", actionErrors);

}

int main(){
    printf("Testing village\n");
    printf("cardtest3.c\n");
    villageTest();
    return 0;
}