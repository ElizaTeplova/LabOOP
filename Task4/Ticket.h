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

//              changed version

    int getTrain() const;
    std::string getStation1()   const;
    std::string getStation2()   const;
    std::string getDepDay()    const;
    std::string getDepTime()   const;
    int         getCoach()      const;
    int         getSeat()       const;
    int         getPrice()      const;

    void        setStation1(char* station1);
    void        setStation2(char*  station2);
    void        setDepDay(char* depDay);
    void        setDepTime(char* depTime);
    void        setCoach(int coach);
    void        setSeat(int seat);
    void        setPrice(int price);

//    bool isCorrect(int low, int high);

    Ticket(Ticket *pTicket);

public:
    Ticket(int train, std::string& station1, std::string& station2, std::string& depDay, std::string depTime, int coach, int seat, int price);
    Ticket() : Ticket(0, (std::string &) "", (std::string &) "", (std::string &) "", "", 0, 0, 0){
            std::cout << "Default constructor is called" << std::endl;
    }
    void setTrain(int train);

    Ticket(std::string& train,
           std::string& station1,
           std::string& station2,
           std::string& depDay,
           std::string& depTime,
           std::string& coach,
           std::string& seat,
            std::string& price
           );

};

#endif //TASK3_TICKET_H