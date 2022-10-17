#include <iostream>
#include <fstream>
#include <ios>
#include "Ticket.h"

int main() {
    Ticket *ticket = new Ticket[numberOfTrains];
    const std::string fileName = R"(C:\textbooks\labs\oop\workshop\Task3\oFile.txt)";
    std::ofstream oFile;
    oFile.open(fileName, std::ios_base::out | std::ios_base::trunc);
    int i;

    for (i = 0; i < numberOfTrains; i++){
        ticket[i].inputTicket();
        ticket[i].inputInfoToFile(oFile);
    }

    std::cout << "-------------------------------" << std::endl;
    for (i = 0; i < numberOfTrains; i++){
        ticket[i].showTicket();
    }

    oFile.close();
}
