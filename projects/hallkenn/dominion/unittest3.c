/*
** UNITTEST3: a test for whoseTurn
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void whoseTurnTest(){
    int i, result, errorCounter;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState* G = malloc(sizeof(struct gameState));

    initializeGame(4, k, 12, G);
    printf("Initializing 4 player game; on first turn whoseTurn should return 0\n");
    result = whoseTurn(G);
    if( result == 0 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: result of %d\n", result);
    }

    endTurn(G);
    endTurn(G);
    printf("After 2 turn ends, whoseTurn should return 2\n");
    result = whoseTurn(G);
    if( result == 2 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: result of %d\n", result);
    }

    endTurn(G);
    endTurn(G);
    printf("After 2 more turn ends, whoseTurn should return 0 again\n");
    result = whoseTurn(G);
    if( result == 0 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: value of %d\n", result);
    }

    errorCounter = 0;
    printf("Testing 10000 turns\n");
    for( i=0; i<10000; ++i ){
        endTurn(G);
        result = whoseTurn(G);
        if( result != (i + 1) % 4 ){
            errorCounter++;
        }
    }
    if( errorCounter == 0 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: %d failures\n", errorCounter);
    }
}

int main(){
    printf("Testing whoseTurn\n");
    printf("unittest3.c\n");
    whoseTurnTest();
    return 0;
}