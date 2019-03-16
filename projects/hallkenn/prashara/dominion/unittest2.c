/*
** UNITTEST2: a test for isGameOver
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void isGameOverTest(){
    int result, errorCounter, i, tempSupply1, tempSupply2, tempSupply3, rand1, rand2, rand3;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState* G = malloc(sizeof(struct gameState));

    initializeGame(2, k, 8, G);
    printf("At initialization, game should not be over.\n");
    result = isGameOver(G);
    if( result == 0 ){
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    G->supplyCount[province] = 0;
    printf("When provinces run out, game should be over\n");
    result = isGameOver(G);
    if( result == 1 ){
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }
    G->supplyCount[province] = 6;

    printf("When three supply piles are at 0, the game ends: testing 10000 random combinations of three empty supply piles\n");
    errorCounter = 0;
    for( i=0; i<10000; ++i ){
        do{
            rand1 = rand() % 25;
        } while(rand1 == province);
        do{
            rand2 = rand() % 25;
        } while(rand1 == rand2 || province == rand2);
        do{
            rand3 = rand() % 25;
        } while(rand1 == rand3 || rand2 == rand3 || province == rand3);
        tempSupply1 = G->supplyCount[rand1];
        tempSupply2 = G->supplyCount[rand2];
        tempSupply3 = G->supplyCount[rand3];
        G->supplyCount[rand1] = 0;
        G->supplyCount[rand2] = 0;
        G->supplyCount[rand3] = 0;
        result = isGameOver(G);
        if( result == 0 ){
            errorCounter++;
        }
        G->supplyCount[rand1] = tempSupply1;
        G->supplyCount[rand2] = tempSupply2;
        G->supplyCount[rand3] = tempSupply3;
    }
    if( errorCounter == 0 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: %d cases\n", errorCounter);
    }

    printf("When two non-province supply piles are at 0 (and no other end conditions met), the game does not end: testing 10000 random combinations of two empty supply piles\n");
    errorCounter = 0;
    for( i=0; i<10000; ++i ){
        do{
            rand1 = rand() % 25;
        } while(rand1 == province);
        do{
            rand2 = rand() % 25;
        } while(rand1 == rand2 || province == rand2);
        tempSupply1 = G->supplyCount[rand1];
        tempSupply2 = G->supplyCount[rand2];
        G->supplyCount[rand1] = 0;
        G->supplyCount[rand2] = 0;
        result = isGameOver(G);
        if( result == 1 ){
            errorCounter++;
        }
        G->supplyCount[rand1] = tempSupply1;
        G->supplyCount[rand2] = tempSupply2;
    }
    if( errorCounter == 0 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: %d cases\n", errorCounter);
    }
    free(G);
}

int main(){
    srand(time(NULL));
    printf("Testing isGameOver\n");
    printf("unittest2.c\n");
    isGameOverTest();
    return 0;
}