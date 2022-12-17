#include <iostream>
#include <fstream>
#include "RailwayStation.h"
#include "BoughtTicket.h"

int main() {
// lab7_copy.txt
    std::string filePath = "C:\\files_for_projects";
    std::string fileName = "lab7_copy.txt";
    Ticket personalTicket;
    int train;
    std::ofstream file;
    file.open(filePath + "\\" + "example_lab7.txt", std::ios::out|std::ios::trunc);
    RailwayStation station(filePath, fileName, true);

//    station.showAllTickets();
    std::cout << station.newTheMostExpensiveTicketLab7() << std::endl;
    station.printToFileAllTickets(file);
    file.close();
//    std::cout << "Enter train number: ";
//    std::cin >> train;
//    personalTicket.setTrain(train);
//    station.showFlight(&personalTicket);

    return EXIT_SUCCESS;

    {
        std::ifstream in;
        std::string line;
        int pos = 0;
        in.open(filePath + "\\" + fileName, std::ios::in);
        if (!in.is_open()) {
            std::cerr << filePath + "\\" + fileName << ": wasn't opened" << std::endl;
            return EXIT_FAILURE;
        }

        BoughtTicket testTicket;
        Ticket ticket;


        pos = 0;
        pos = in.tellg();
        std::getline(in, line);
        std::getline(in, line);
        std::getline(in, line);
        std::cout << line.length() << std::endl;
        return 0;

        in.seekg(pos, std::ios_base::beg);
        in >> testTicket;
        std::cout << testTicket;
        std::string s;
        std::cout << "s: " << s << std::endl;
        in >> s >> s;
        std::getline(in, line);
        std::cout << line;
        std::getline(in, line);

//        for (int i = 0; i < line.length(); i++) {
//            std::cout << i << ": " << line.c_str()[i] << std::endl;
//        }

        //        std::cout << testTicket << std::endl;
    }


//    {
//        std::ofstream out;
//
//        out.open("C:\\files_for_projects\\lab6_inherited.txt", std::ios_base::out | std::ios_base::app);
//        if (!out.is_open()) {
//            std::cerr << "file wasn't opened!";
//            return EXIT_FAILURE;
//        }
//        BoughtTicket boughtTicket;
//        Ticket ticket;
//
//        char c;
//        std::cout << "Enter number iterations: ";
//        int n = 2;
//        char choice;
//        for (int i = 0; i < n; i++) {
//
//            std::cout << std::endl << "is it bought boughtTicket? Y/N" << std::endl;
//            std::cin >> choice;
//
//            if (choice == 'Y') {
//                std::cin >> boughtTicket;
//                std::cout << boughtTicket;
//                out << boughtTicket;
//                boughtTicket.clear();
//            } else {
//                std::cin >> ticket;
//                std::cout << ticket;
//                out << ticket << std::endl;
//                ticket.clear();
//            }
//        }
//    }
    return EXIT_SUCCESS;
}
