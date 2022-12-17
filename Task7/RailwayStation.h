#pragma once
#include "Ticket.h"
#include <fstream>
#include <vector>
#include "BoughtTicket.h"
#include "ElectronicTicket.h"

#ifndef TASK4_RAILWAYSTATION_H
#define TASK4_RAILWAYSTATION_H


class RailwayStation {
private:
    static const std::string DEFAULT_FILE_PATH;
    static const std::string DEFAULT_FILE_NAME;
    static int sizeTrain;

    std::string stationAddress;
    std::vector<Ticket> ticket;
    std::vector<BoughtTicket> boughtTicketVector;
    std::vector<ElectronicTicket> electronicTicketVector;

    std::vector<Ticket* > allTicket;

    bool isCorrect(Ticket* personalTicket, int low, int high);
    int numberOfEmptySeats(Ticket* personalTicket, int low, int high);
    void sortTickets();

//    lab7
    void unionAllTicket();
public:

    void setStationAddress(char* address);
    std::string getStationAddress();
    RailwayStation() : RailwayStation(sizeTrain, (std::string&)DEFAULT_FILE_NAME, (std::string&)DEFAULT_FILE_PATH){ }
    RailwayStation(int numberOfTrainsClass, std::string& fileName, std::string& filePath);
    ~RailwayStation(){
        ticket.clear();
        boughtTicketVector.clear();
    }

    void showFlight(Ticket* personalTicket);
    int theMostExpensiveTicket();
    void operator+=(const Ticket& copyTicket);


//    lab6. inherited class
    void showAllTickets();
    RailwayStation(std::string& filePath, std::string& fileName);
    int newTheMostExpensiveTicket(bool f);

//    lab7. dynamic polymorphism
    RailwayStation(std::string& filePath, std::string& fileName, bool flagLab7);
    int newTheMostExpensiveTicketLab7();
    void printToFileAllTickets(std::ofstream& stream);
};


#endif //TASK4_RAILWAYSTATION_H
