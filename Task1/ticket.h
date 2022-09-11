//
// Created by mrbab on 11.09.2022.
//
#include <cstdio>
#ifndef TASK1_TICKET_H
#define TASK1_TICKET_H
#define numbersOfAvailableSymbols 15
#define dataSymbols 10
#define timeSymbols 8
struct ticket{
    int     train;
    char    station1[numbersOfAvailableSymbols];
    char    station2[numbersOfAvailableSymbols];
    char    depDay[dataSymbols];
    char    depTime[timeSymbols];
    int     coach;
    int     seat;
    int     price;
    bool    theSame = false;
};

typedef struct ticket ticket;

void inputTicketStructure(ticket* ticketInfo, FILE* iFile, FILE* iBinFile);

void inputTicketStructureToFiles(int i, ticket* ticketInfo, FILE* iFile, FILE* iBinFile);

void inputNumberOfTickets(int* number);

#endif //TASK1_TICKET_H
