//
// Created by mrbab on 16.10.2022.
//
#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ios>
#include <iomanip>

#ifndef TASK3_TICKET_H
#define TASK3_TICKET_H

#define numbersOfAvailableSymbols 15
#define dataSymbols 10
#define timeSymbols 8
#define numberOfTrains 14

class Ticket{
private:
    int             train   = 0;
    std::string     station1;
    std::string     station2;
    std::string     depDay;
    std::string     depTime;
    int             coach   = 0;
    int             seat    = 0;
    int             price   = 0;
//    bool            theSame = false;

public:
    Ticket& operator=(Ticket& ticket1);

    void inputTicket();
    void inputInfoToFile(std::ofstream& oFile);
    void showTicket();

//              part2: execute
    void extractInfo(std::ifstream& inFile);
    friend void sortInfo(Ticket* ticketInfo);
    void ticketsOutput(int i);
    friend void showFlight(Ticket* ticketInfo, Ticket* personalTicket);
    friend int numberOfEmptySeats(Ticket* ticketInfo, Ticket* personalTicket, int low, int high);
    friend bool isCorrect(Ticket* ticketInfo, Ticket* personalTicket, int low, int high);
    friend int theMostExpensiveTicket(Ticket *ticketInfo);
    void setTrain();
};

#endif //TASK3_TICKET_H
