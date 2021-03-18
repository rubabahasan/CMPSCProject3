#ifndef DATASTRUCTURES_H 
#define DATASTRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include "gll.h"

typedef struct PCB ProcessControlBlock;


struct PCB
{
    char* name;
    uint64_t start_time;
    char* memoryFilename;
    FILE* memoryFile;
    gll_t* memReq;
    int hitCount;
    int missCount;
    uint64_t fracLeft;

    uint64_t OS_time;
    uint64_t user_time;

} PCBNode;

struct NextMem
{
    char* type;
    char* address;
};


typedef struct Stats{
    char* processName;
    int hitCount;
    int missCount;
    uint64_t duration;
    int numberOfPgFaults;
    int numberOfTLBmiss;
    uint64_t blockedStateDuration;

    uint64_t OS_time;
    uint64_t user_time;


} stats;

typedef struct TotalStats{
    gll_t* perProcessStats;
    int numberOfContextSwitch;
    int numberOfDiskInt;
    int totalPgFaults;
    int totalTLBmiss;
    uint64_t totalBlockedStateDuration;
    uint64_t OSModetime;
    uint64_t userModeTime;
    gll_t* executionOrder;

} totalstats;

#endif