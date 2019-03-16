/*
** UNITTEST4: a test for getCost
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void getCostTest(){
    int result;

    printf("testing curse; expecting value of 0\n");
    result = getCost(curse);
    if( result == 0){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing estate; expecting value of 2\n");
    result = getCost(estate);
    if( result == 2 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing duchy; expecting value of 5\n");
    result = getCost(duchy);
    if( result == 5 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing province; expecting value of 8\n");
    result = getCost(province);
    if( result == 8 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing copper; expecting value of 0\n");
    result = getCost(copper);
    if( result == 0 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing silver; expecting value of 3\n");
    result = getCost(silver);
    if( result == 3 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing gold; expecting value of 6\n");
    result = getCost(gold);
    if( result == 6 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing adventurer; expecting value of 6\n");
    result = getCost(adventurer);
    if( result == 6 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing council_room; expecting value of 5\n");
    result = getCost(council_room);
    if( result == 5 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing feast; expecting value of 4\n");
    result = getCost(feast);
    if( result == 4 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing gardens; expecting value of 4\n");
    result = getCost(gardens);
    if( result == 4 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing mine; expecting value of 5\n");
    result = getCost(mine);
    if( result == 5 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing remodel; expecting value of 4\n");
    result = getCost(remodel);
    if( result == 4 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing smithy; expecting value of 4\n");
    result = getCost(smithy);
    if( result == 4 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing village; expecting value of 3\n");
    result = getCost(village);
    if( result == 3 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing baron; expecting value of 4\n");
    result = getCost(baron);
    if( result == 4 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing great_hall; expecting value of 3\n");
    result = getCost(great_hall);
    if( result == 3 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing minion; expecting value of 5\n");
    result = getCost(minion);
    if( result == 5 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing steward; expecting value of 3\n");
    result = getCost(steward);
    if( result == 3){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing tribute; expecting value of 5\n");
    result = getCost(tribute);
    if( result == 5 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing ambassador; expecting value of 3\n");
    result = getCost(ambassador);
    if( result == 3){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing cutpurse; expecting value of 4\n");
    result = getCost(cutpurse);
    if( result == 4){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing embargo; expecting value of 2\n");
    result = getCost(embargo);
    if( result == 2){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing outpost; expecting value of 5\n");
    result = getCost(outpost);
    if( result == 5 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing salvager; expecting value of 4\n");
    result = getCost(salvager);
    if( result == 4 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing sea_hag; expecting value of 4\n");
    result = getCost(sea_hag);
    if( result == 4 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }

    printf("testing treasure_map; expecting value of 4\n");
    result = getCost(treasure_map);
    if( result == 4 ){
        printf("PASSED\n");
    } else {
        printf("FAILED: with a value %d\n", result);
    }
}

int main(){
    printf("Testing getCost\n");
    printf("unittest4.c\n");
    getCostTest();
    return 0;
}