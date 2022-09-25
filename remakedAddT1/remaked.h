//
// Created by mrbab on 25.09.2022.
//
#pragma once
#include <cstdio>
#include <cstring>

#ifndef REMAKEDADDT1_REMAKED_H
#define REMAKEDADDT1_REMAKED_H

#define numbersOfAvailableSymbols 15
#define dataSymbols 10
#define timeSymbols 8
#define numberOfTrains 14
struct Ticket{
    int     train;
    char    station1[numbersOfAvailableSymbols];
    char    station2[numbersOfAvailableSymbols];
    char    depDay[dataSymbols];
    char    depTime[timeSymbols];
    int     coach;
    int     seat;
    int     price;
    bool    theSame = false;

    Ticket& operator=(Ticket& ticket1){
        this->train = ticket1.train;
        strncpy(this->station1, ticket1.station1, numbersOfAvailableSymbols);
        strncpy(this->station2, ticket1.station2, numbersOfAvailableSymbols);
        strncpy(this->depDay, ticket1.depDay, dataSymbols);
        strncpy(this->depTime, ticket1.depTime, timeSymbols);
        this->coach = ticket1.coach;
        this->seat = ticket1.seat;
        this->price = ticket1.price;

        return *this;
    };
};




void extractInfo(FILE* inToFile, FILE* outOfFile, Ticket* ticketInfo);
void sortInfo(Ticket* ticketInfo, FILE* inToFile);

void inputTicketStructureToFiles(int i, Ticket* ticketInfo, FILE* inToFile);


void ticketsOutput(Ticket* ticketInfo, int i);

void showFlight(Ticket* ticketInfo, Ticket* personalTicket);

bool isCorrect(Ticket* ticketInfo, Ticket* personalTicket, int low, int high);

int numberOfEmptySeats(Ticket* ticketInfo, Ticket* personalTicket, int low, int high);

int theMostExpensiveTicket(Ticket *ticketInfo);
#endif //REMAKEDADDT1_REMAKED_H
