#include <iostream>
#include <fstream>
#include "RailwayStation.h"
int main() {
    RailwayStation railwayStation;
    Ticket personalTicket;
    int train;
    std::ofstream stream;
//    stream.open("C:\\files_for_projects\\textOverloading.txt", std::ios_base::out | std::ios_base::app);
    stream.open("C:\\files_for_projects\\oFile.txt", std::ios_base::out | std::ios_base::app);
    if (!stream.is_open()) {
        std::cerr << "File wasn't open. Exit program" << std::endl;
        stream.close();
        return 0;
    }

    std::cin >> personalTicket;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
//    std::cout << personalTicket;
//    std::cout << personalTicket.getDepDay();
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    stream << personalTicket;
    railwayStation += personalTicket;
    stream.close();

//    std::cout << "Enter train number: ";
//    std::cin >> train;
//    personalTicket.setTrain(train);
//    railwayStation.showFlight(&personalTicket);
//    std::cout<<"The most expensive ticket price: " << railwayStation.theMostExpensiveTicket();
}
