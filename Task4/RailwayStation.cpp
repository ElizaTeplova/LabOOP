//
// Created by mrbab on 29.10.2022.
//

#include "RailwayStation.h"
#include <regex>


const std::string RailwayStation::DEFAULT_FILE_PATH = "C:\\files_for_projects";
const std::string RailwayStation::DEFAULT_FILE_NAME = "oFile.txt";
int RailwayStation::sizeTrain = 0;

RailwayStation::RailwayStation(int numberOfTrainsClass, std::string& fileName, std::string& filePath) {

    static std::ifstream inFile;
    inFile.open(filePath + "\\" + fileName, std::ios::in);
    std::string s[8];
    int i;


    if (!inFile.is_open()) {
        std::cerr << "RailwayStation: File wasn't opened. Operation prohibited. Exit program" << std::endl;
        exit(0);
    } else {
        std::cout << "File: " << filePath << "\\" << fileName << " was opened." << std::endl;
    }

    while (!inFile.eof()) {
        for (i = 0; i < 8; i++) {
            inFile >> s[i];
        }
        ticket.emplace_back(new Ticket(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7]));
        ticket.at(sizeTrain).ticketsOutput(sizeTrain);
        sizeTrain++;

    }
//    std::cout << "sizeTrain: " << sizeTrain << std::endl;
//    system("pause");
//    exit(0);
    inFile.close();
    sortTickets();
}

void RailwayStation::showFlight(Ticket* personalTicket){
    char *strForChecking;
    int i, low = 0, high = sizeTrain, k = 0, quantity;
    for (i = 0; i < sizeTrain; i++){

        if (ticket.at(i).getTrain() == personalTicket->getTrain()){
           k++;
           high = i;
        }
    }
    low = high - k + 1;
    std::cout<<"high:" << high << " low: " << low << std::endl;
    if (low == sizeTrain - 0 + 1){
        std::cout << "showFlight: This train number wasn't found. Exit method..." << std::endl;
        return;
    }

    do{
        for (i = low; i<=high;i++)
            ticket.at(i).ticketsOutput(i);
        std::cout << "--------------------------------------------------------------------------------------------------\n";

        strForChecking = new char[numbersOfAvailableSymbols];
        printf("Enter station1: ");
        std::cin >> strForChecking;
        personalTicket->setStation1(strForChecking);
        delete strForChecking;

        strForChecking = new char[numbersOfAvailableSymbols];
        printf("Enter station2: ");
        std::cin >> strForChecking;
        personalTicket->setStation2(strForChecking);
        delete strForChecking;

        strForChecking = new char[dataSymbols];
        printf("Enter depDay: ");
        std::cin >> strForChecking;
        personalTicket->setDepDay(strForChecking);
        delete strForChecking;

        strForChecking = new char[1];
        printf("Enter coach: ");
        std::cin >> strForChecking;
        personalTicket->setCoach((int) (strForChecking) - 48) ;
        personalTicket->setCoach(atoi(strForChecking));
        delete strForChecking;

        if (isCorrect(personalTicket, low, high))
            break;
        printf("false\n");
        std::cout << "--------------------------------------------------------------------------------------------------\n";
    }while(true);

    std::cout << "You choose: " << personalTicket->getStation1() << " " << personalTicket->getStation2() << " "
              << personalTicket->getDepDay() << std::endl;
    std::cout << "Coach: " << personalTicket->getCoach() << std::endl;

    quantity = numberOfEmptySeats(personalTicket, low, high);
    std::cout << "number of empty seats in this coach: " << quantity << std::endl;

}

bool RailwayStation::isCorrect(Ticket *personalTicket, int low, int high) {
    int i;
    bool f[4] = {false, false, false, false};
    std::cmatch result;
    std::regex regular;
    for (i = low; i <= high; i++) {
        regular = personalTicket->getStation1().c_str();
        if (std::regex_match(ticket.at(i).getStation1().c_str(), result, regular))
            f[0] = true;
        regular = personalTicket->getStation2().c_str();
        if (std::regex_match(ticket.at(i).getStation2().c_str(), result, regular))
            f[1] = true;
        regular = personalTicket->getDepDay().c_str();
        if (std::regex_match(ticket.at(i).getDepDay().c_str(), result, regular))
            f[2] = true;
        if (personalTicket->getCoach() == ticket.at(i).getCoach())
            f[3] = true;
        if (f[0] && f[1] && f[2] && f[3])
            return true;
    }
    return false;
}

int RailwayStation::numberOfEmptySeats(Ticket* personalTicket, int low, int high){
    int k = 6;
    printf("You can see 6 empty seats in empty flight...\n");
    bool f[4] = {false, false, false, false};
    int i;
    std::cmatch result;
    std::regex regular;
    for (i = low; i <= high; i++){
        f[0] = false; f[1] = false; f[2] = false; f[3] = false;

        regular = personalTicket->getStation1().c_str();
        if (std::regex_match(ticket.at(i).getStation1().c_str(), result, regular))
            f[0] = true;
        regular = personalTicket->getStation2().c_str();
        if (std::regex_match(ticket.at(i).getStation2().c_str(), result, regular))
            f[1] = true;
        regular = personalTicket->getDepDay().c_str();
        if (std::regex_match(ticket.at(i).getDepDay().c_str(), result, regular))
            f[2] = true;
        if (personalTicket->getCoach() == ticket.at(i).getCoach())
            f[3] = true;
        if (f[0] && f[1] && f[2] && f[3])
            k--;
    }
    return k;
}

void RailwayStation::sortTickets(){
    int i, j;
    Ticket tmp;

    for (i = 0; i < sizeTrain - 1; i++){
        for (j = 0; j < sizeTrain - i - 1; j++){

            if (ticket.at(j).getTrain() > ticket.at(j + 1).getTrain()){

                tmp = ticket.at(j);
                ticket.at(j) = ticket.at(j + 1);
                ticket.at(j + 1) = tmp;
            }
        }
    }
    for (i = 0; i < sizeTrain; i++)
        ticket.at(i).ticketsOutput(i);
}

int RailwayStation::theMostExpensiveTicket(){
    int i, max = 0;
    for (i = 0; i < sizeTrain; i++)
        if (max < ticket.at(i).getPrice())  max = ticket.at(i).getPrice();

    return max;
}

void RailwayStation::setStationAddress(char* address){
    this->stationAddress.assign(stationAddress);
}
std::string RailwayStation::getStationAddress(){
    return this->stationAddress;
}