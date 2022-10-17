#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include "Ticket.h"
int main() {

    Ticket *ticket = new Ticket[numberOfTrains];
    Ticket* personalTicket = new Ticket[1];
    std::string nameFile = R"(C:\textbooks\labs\oop\workshop\Task3\oFile.txt)";
    std::ifstream inFile;
    int i;
    inFile.open(nameFile, std::ios::in);
    if (inFile.is_open()){
        std::cout << "File was opened" << std::endl;
    } else {
        std::cout<< "File wasn't opened" << std::endl;
    }

    for (i = 0; i < numberOfTrains; i++){
        ticket[i].extractInfo(inFile);
    }
    sortInfo(ticket);

    std::cout << "Enter train number: ";
    personalTicket->setTrain();
    showFlight(ticket, personalTicket);

    std::cout << "the most expensive ticket:" << theMostExpensiveTicket(ticket);

    inFile.close();
}
