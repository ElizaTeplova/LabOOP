//
// Created by mrbab on 29.10.2022.
//

#include "RailwayStation.h"

const std::string RailwayStation::DEFAULT_FILE_PATH = "C:\\files_for_projects";
const std::string RailwayStation::DEFAULT_FILE_NAME = "oFile.txt";
int RailwayStation::sizeTrain = 0;

RailwayStation::RailwayStation(int numberOfTrainsClass, std::string& fileName, std::string& filePath) {

    static std::ifstream inFile;
    inFile.open(filePath + "\\" + fileName, std::ios::in);
    std::string s[8];
    int i;


    if (!inFile.is_open()){
        std::cerr << "RailwayStation: File wasn't opened. Operation prohibited .Exit program" << std::endl;
        exit(0);
    } else {
        std::cout << "File: " << filePath << "\\" << fileName << " was opened." << std::endl;
    }

    while (!inFile.eof()){
        for (i = 0; i < 8; i++){
            inFile >> s[i];
//            std::cout << s[i] << std::endl;
        }
//        ticket.emplace_back(new Ticket(std::atoi(s[0].c_str()), s[1], s[2], s[3], s[4], std::atoi(s[5].c_str()), std::atoi(s[6].c_str()), std::atoi(s[7].c_str())));
        ticket.emplace_back(new Ticket(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7]));
        ticket.at(sizeTrain).ticketsOutput(sizeTrain);
        sizeTrain++;

//        std::cout << "Do you want to exit program? Y/N" <<std::endl;
//        std::cin >> s[0];
//        if (s[0] == "Y"){
//            break;
//        }
    }

    inFile.close();
}