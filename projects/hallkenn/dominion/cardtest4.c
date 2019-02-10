/*
** CARDTEST4: a test for council room
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void councilRoomTest(){
    int i, j, k, numcouncilRooms, otherPlayersHand, money, card, cardsInDeck, councilRoomsInDiscard1, councilRoomsInDiscard2;
    int councilRoomPlayCount = 0; 
    int cardsInHandErrors = 0; 
    int deckErrors = 0; 
    int discardPileErrors = 0; 
    int otherPlayerStateErrors = 0;
    int supplyStateErrors = 0; 
    int buyErrors = 0;
    int kingdom[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int supplyState[16];
    struct gameState* G = malloc(sizeof(struct gameState));
    
    printf("Playing 100 games where councilRoom is the only card played\n");
    for( i=0; i<100; ++i ){
        initializeGame(2, kingdom, 8, G);
        numcouncilRooms = 0;
        while( !isGameOver(G) ){
            money = 0;
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
                if( card == council_room ){
                    councilRoomsInDiscard1 = 0;
                    for( k=0; k<G->playedCardCount; ++k ){
                        if( G->playedCards[k] == council_room ){
                            councilRoomsInDiscard1++;
                        }
                    }
                    cardsInDeck = G->deckCount[whoseTurn(G)];
                    playCard(j, -1, -1, -1, G);
                    councilRoomPlayCount++;
                    if( whoseTurn(G) == 0 ){
                        otherPlayersHand = G->handCount[1];
                    } else {
                        otherPlayersHand = G->handCount[0];
                    }
                    if( numHandCards(G) != 8 ){
                        cardsInHandErrors++;
                    }
                    if( G->numBuys != 2 ){
                        buyErrors++;
                    }
                    councilRoomsInDiscard2 = 0;
                    for( k=0; k<G->playedCardCount; ++k ){
                        if( G->playedCards[k] == council_room ){
                            councilRoomsInDiscard2++;
                        }
                    }
                    if( councilRoomsInDiscard1 != councilRoomsInDiscard2 - 1 ){
                        discardPileErrors++;
                    }
                    if( G->deckCount[whoseTurn(G)] != cardsInDeck - 4 ){
                        deckErrors++;
                    }
                    if( otherPlayersHand != 1 ){
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
            } else if(money >= 5 && numcouncilRooms < 2 ){
                buyCard(council_room, G);
                numcouncilRooms++;
            } else if (money >= 3) {
                buyCard(silver, G);
            }
            endTurn(G);            
        }
    }
    free(G);
    printf("councilRoom played %d times\n", councilRoomPlayCount);
    printf("Cards in hand errors: %d\n", cardsInHandErrors);
    printf("Cards in deck errors: %d\n", deckErrors);
    printf("Discard pile errors: %d\n", discardPileErrors);
    printf("Other player state errors: %d\n", otherPlayerStateErrors);
    printf("Supply state errors: %d\n", supplyStateErrors);
    printf("Buy errors: %d\n", buyErrors);

}

int main(){
    printf("Testing council_room\n");
    printf("cardtest4.c\n");
    councilRoomTest();
    return 0;
}