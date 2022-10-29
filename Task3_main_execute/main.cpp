#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <regex>
#include "Ticket.h"
int main() {

    Ticket *ticket = new Ticket[numberOfTrains];
    Ticket* personalTicket = new Ticket[1];
    std::string nameFile = R"(C:\textbooks\labs\oop\workshop\Task3\oFile.txt)";
    std::ifstream inFile;
    std::cmatch result;
    std::regex regular;
    char *strForChecking;
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


//                  sortInfo(Ticket* ticketInfo);
    int j;
    Ticket tmp;

    for (i = 0; i < numberOfTrains - 1; i++) {
        for (j = 0; j < numberOfTrains - i - 1; j++) {

            if ((ticket + j)->getTrain() > (ticket + j + 1)->getTrain()) {

                tmp = *(ticket + j);
                *(ticket + j) = *(ticket + j + 1);
                *(ticket + j + 1) = tmp;
            }
        }
    }
    for (i = 0; i < numberOfTrains; i++)
        (ticket + i)->ticketsOutput(i);


//                  showFlights();
    std::cout << "Enter train number: ";
    personalTicket->setTrain();

    {
//        char *strForChecking;
        int low = 0, high = 14, k = 0, quantity;
        for (i = 0; i < numberOfTrains; i++){

            if ((ticket + i)->getTrain() == personalTicket->getTrain()){
                k++;
                high = i;
            }
        }
        low = high - k + 1;
        std::cout<<"high:" << high << " low: " << low << std::endl;
        bool f[4];
        do{
            for (i = 0; i < 4; i++){
                f[i] = false;
            }
            for (i = low; i<=high;i++)
                (ticket + i)->ticketsOutput(i);
            std::cout << "--------------------------------------------------------------------------------------------------\n";
//            std::cmatch result;
//            std::regex regular;
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
//            personalTicket->coach = (int) (strForChecking) - 48;
//            personalTicket->coach = atoi(strForChecking);
            personalTicket->setCoach(atoi(strForChecking));
            delete strForChecking;
//                      isCorrect();
            for (i = low; i <= high; i++) {
                regular = personalTicket->getStation1().c_str();
                if (std::regex_match((ticket + i)->getStation1().c_str(), result, regular))
                    f[0] = true;
                regular = personalTicket->getStation2().c_str();
                if (std::regex_match((ticket + i)->getStation2().c_str(), result, regular))
                    f[1] = true;
                regular = personalTicket->getDepDay().c_str();
                if (std::regex_match((ticket + i)->getDepDay().c_str(), result, regular))
                    f[2] = true;
                if (personalTicket->getCoach() == (ticket + i)->getCoach())
                    f[3] = true;
                if (f[0] && f[1] && f[2] && f[3])
                    break;
            }
        } while (!(f[0] && f[1] && f[2] && f[3]));

        {
            quantity = 6;
            printf("You can see 6 empty seats in empty flight...\n");
//            std::cmatch result;
//            std::regex regular;
            for (i = low; i <= high; i++){
                f[0] = false; f[1] = false; f[2] = false; f[3] = false;

                regular = personalTicket->getStation1().c_str();
                if (std::regex_match((ticket + i)->getStation1().c_str(), result, regular))
                    f[0] = true;
                regular = personalTicket->getStation2().c_str();
                if (std::regex_match((ticket + i)->getStation2().c_str(), result, regular))
                    f[1] = true;
                regular = personalTicket->getDepDay().c_str();
                if (std::regex_match((ticket + i)->getDepDay().c_str(), result, regular))
                    f[2] = true;
                if (personalTicket->getCoach() == (ticket + i)->getCoach())
                    f[3] = true;
                if (f[0] && f[1] && f[2] && f[3])
                    quantity--;
            }
            std::cout << "You choose: " << personalTicket->getStation1() << " " << personalTicket->getStation2() << " "
                      << personalTicket->getDepDay() << std::endl;
            std::cout << "Coach: " << personalTicket->getCoach() << std::endl;
            std::cout << "number of empty seats in this coach: " << quantity << std::endl;
        }
    }

//    sortInfo(ticket);
//
//    std::cout << "Enter train number: ";
//    personalTicket->setTrain();
//    showFlight(ticket, personalTicket);
//
//    std::cout << "the most expensive ticket:" << theMostExpensiveTicket(ticket);

    inFile.close();
}
