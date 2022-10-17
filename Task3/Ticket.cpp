#include "Ticket.h"
#include <regex>
#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

Ticket &Ticket::operator=(Ticket &ticket1) = default;

//                             first part: write to file
void Ticket::inputTicket(){
    static int i = 0;
    static int j = 0;
    int multiplier = 1;
    char* strForChecking;
    strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));
    std::cmatch result;
    std::regex regular("[1-9]\\d{2}");

    printf("Enter element of structure: train (int), [1-9]{3}\n");                                       //input Ticket: train
    do { std::cin >> strForChecking; } while (!std::regex_match(strForChecking, result, regular));
    for (j = 2; j >= 0; j--){
        this->train += ((int) strForChecking[j] - 48) * multiplier;
        multiplier*=10;
    } multiplier = 1;
    std::cout << "Train: " << this->train << std::endl;
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = "[A-Z][a-zA-Z\\s]{1,13}";
    std::cout<<"Enter element of structure: station1, (char), [A-Z\\s]{1,15}\n";
    do { std::cin >> strForChecking; } while (!std::regex_match(strForChecking, result, regular));
    for (j = 0; j < numbersOfAvailableSymbols; j++) this->station1 += *(strForChecking + j);
    std::cout << "Station1: " << this->station1 << std::endl;
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    std::cout << "Enter element of structure: station2, (char), [A-Z\\s]{1,15}\n";
    do { std::cin >> strForChecking; } while (!std::regex_match(strForChecking, result, regular));
    for (j = 0; j < numbersOfAvailableSymbols; j++) this->station2 += *(strForChecking + j);
    std::cout << "Station2: " << this->station2 << std::endl;
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = R"(\d\d\.\d\d.\d\d)";
    std::cout << "Enter element of structure: depDay, (char), \\d\\d.\\d\\d.\\d\\d\n";
    do { std::cin >> strForChecking; } while (!std::regex_match(strForChecking, result, regular));
    for (j = 0; j < numbersOfAvailableSymbols; j++) this->depDay += *(strForChecking + j);
    std::cout << "depDay: " << this->depDay << std::endl;
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = R"([0-2]\d:[0-5]\d:[0-5]\d)";
    std::cout << "Enter element of structure: depTime, (char), hh:mm:ss\n";
    do { std::cin >> strForChecking; } while ( !std::regex_match(strForChecking, result, regular) ||
                                               (strForChecking[0] == '2') &&
                                               ((int )strForChecking[1] - 48 > 3));
    for (j = 0; j < numbersOfAvailableSymbols; j++) this->depTime += *(strForChecking + j);
    std::cout << "depTime: " << this->depTime << std::endl;
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = R"([1-9]\d{0,2})";

    std::cout << "Enter element of structure: coach, (int), [1-9]\\d{0,2}\n";
    do { std::cin >> strForChecking; } while ( !std::regex_match(strForChecking, result, regular));
    for (j = 0; j < numbersOfAvailableSymbols; j++) { if (strForChecking[j] == 0) break; } j--;
    for (; j>=0; j--){
        this->coach += ((int )strForChecking[j] - 48) * multiplier;
        multiplier*=10;
    }
    std::cout << "coach: " << this->coach << std::endl;
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = R"([1-6])";
    std::cout << "Enter element of structure: seat, (int), [1-6]\n";
    do { std::cin >> strForChecking; } while ( !std::regex_match(strForChecking, result, regular));
    this->seat = (int )strForChecking[0] - 48;
    std::cout << "seat: " << this->seat << std::endl;
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = R"(\d{4})";
    std::cout << "Enter element of structure: price, (int), \\d{4}\n";
    do { std::cin >> strForChecking; } while ( !std::regex_match(strForChecking, result, regular));
    multiplier = 1;
    for (j = 3; j >= 0; j--){
        this->price += ((int )strForChecking[j] - 48) * multiplier;
        multiplier *= 10;
    }

    std::cout << "price: " << this->price << std::endl;
    free(strForChecking);
}

void Ticket::inputInfoToFile(std::ofstream& oFile) {

    oFile.setf(std::ios::left);
    oFile << std::setw(5) << this->train;
    oFile << std::setw(16) << this->station1.c_str();
    oFile << std::setw(16) << this->station2.c_str();
    oFile << std::setw(10) << this->depDay.c_str();
    oFile << std::setw(10) << this->depTime.c_str();
    oFile << std::setw(5) << this->coach;
    oFile << std::setw(3) << this->seat;
    oFile << std::setw(4) << this->price << std::endl;
}

void Ticket::showTicket() {
    std::cout << "Train: " << this->train << std::endl;
    std::cout << "Station1: " << this->station1 << std::endl;
    std::cout << "Station2: " << this->station2 << std::endl;
    std::cout << "depDay: " << this->depDay << std::endl;
    std::cout << "depTime: " << this->depTime << std::endl;
    std::cout << "coach: " << this->coach << std::endl;
    std::cout << "seat: " << this->seat << std::endl;
    std::cout << "price: " << this->price << std::endl;
}


//                              second part: extract info

void Ticket::extractInfo(std::ifstream& inFile){
    std::string s;

    inFile >> s;
    this->train = atoi(s.c_str());
    inFile >> s;
    this->station1 = s;
    inFile >> s;
    this->station2 = s;
    inFile >> s;
    this->depDay = s;
    inFile >> s;
    this->depTime = s;
    inFile >> s;
    this->coach = atoi(s.c_str());
    inFile >> s;
    this->seat = atoi(s.c_str());
    inFile >> s;
    this->price = atoi(s.c_str());
    showTicket();
//        ticketsOutput(ticket, i);
}

void sortInfo(Ticket* ticketInfo){
    int i, j;
    Ticket tmp;

    for (i = 0; i < numberOfTrains - 1; i++){
        for (j = 0; j < numberOfTrains - i - 1; j++){

            if ((ticketInfo + j)->train > (ticketInfo + j + 1)->train){

                tmp = *(ticketInfo + j);
                *(ticketInfo + j) = *(ticketInfo + j + 1);
                *(ticketInfo + j + 1) = tmp;
            }
        }
    }
    for (i = 0; i < numberOfTrains; i++)
        (ticketInfo + i)->ticketsOutput(i);
//        ticketsOutput(ticketInfo, i);
}

void Ticket::ticketsOutput(int i) {
    std::cout << "i: " << std::setw(2) << i << std::setw(5) << this->train;
    std::cout << std::setw(15) << this->station1;
    std::cout << std::setw(15) << this->station2;
    std::cout << std::setw(10) << this->depDay;
    std::cout << std::setw(10) << this->depTime;
    std::cout << std::setw(3)  << this->coach;
    std::cout << std::setw(3)  << this->seat;
    std::cout << std::setw(6)  << this->price << std::endl;
}

void showFlight(Ticket* ticketInfo, Ticket* personalTicket){
    char *strForChecking;
    int i, low = 0, high = 14, k = 0, quantity;
    for (i = 0; i < numberOfTrains; i++){

        if ((ticketInfo + i)->train == personalTicket->train){
            k++;
            high = i;
        }
    }
    low = high - k + 1;
    std::cout<<"high:" << high << " low: " << low << std::endl;

    for (i = low; i<=high;i++)
        (ticketInfo + i)->ticketsOutput(i);
    std::cout << "--------------------------------------------------------------------------------------------------\n";

    do{
        strForChecking = new char[numbersOfAvailableSymbols];
        printf("Enter station1: ");
        std::cin >> strForChecking;
        personalTicket->station1 = strForChecking;
        delete strForChecking;

        strForChecking = new char[numbersOfAvailableSymbols];
        printf("Enter station2: ");
        std::cin >> strForChecking;
        personalTicket->station2 = strForChecking;
        delete strForChecking;

        strForChecking = new char[dataSymbols];
        printf("Enter depDay: ");
        std::cin >> strForChecking;
        personalTicket->depDay = strForChecking;
        delete strForChecking;

        strForChecking = new char[1];
        printf("Enter coach: ");
        std::cin >> strForChecking;
        personalTicket->coach = (int) (strForChecking) - 48;
        personalTicket->coach = atoi(strForChecking);
        delete strForChecking;

        if (isCorrect(ticketInfo, personalTicket, low, high))
            break;
        printf("false\n");
    }while(true);

    std::cout << "You choose: " << personalTicket->station1 << " " << personalTicket->station2 << " "
              << personalTicket->depDay << std::endl;
    std::cout << "Coach: " << personalTicket->coach << std::endl;

    quantity = numberOfEmptySeats(ticketInfo, personalTicket, low, high);
    std::cout << "number of empty seats in this coach: " << quantity << std::endl;

}

int numberOfEmptySeats(Ticket* ticketInfo, Ticket* personalTicket, int low, int high){
    int k = 6;
    printf("You can see 6 empty seats in empty flight...\n");
    bool f[4] = {false, false, false, false};
    int i;
    std::cmatch result;
    std::regex regular;
    for (i = low; i <= high; i++){
        f[0] = false; f[1] = false; f[2] = false; f[3] = false;

        regular = personalTicket->station1.c_str();
        if (std::regex_match((ticketInfo + i)->station1.c_str(), result, regular))
            f[0] = true;
        regular = personalTicket->station2.c_str();
        if (std::regex_match((ticketInfo + i)->station2.c_str(), result, regular))
            f[1] = true;
        regular = personalTicket->depDay.c_str();
        if (std::regex_match((ticketInfo + i)->depDay.c_str(), result, regular))
            f[2] = true;
        if (personalTicket->coach == (ticketInfo + i)->coach)
            f[3] = true;
        if (f[0] && f[1] && f[2] && f[3])
            k--;
    }
    return k;
}

bool isCorrect(Ticket* ticketInfo, Ticket* personalTicket, int low, int high){
    int i;
    bool f[4] = {false, false, false, false};
    std::cmatch result;
    std::regex regular;
    for (i = low; i <= high; i++){
        regular = personalTicket->station1.c_str();
        if (std::regex_match((ticketInfo + i)->station1.c_str(), result, regular))
            f[0] = true;
        regular = personalTicket->station2.c_str();
        if (std::regex_match((ticketInfo + i)->station2.c_str(), result, regular))
            f[1] = true;
        regular = personalTicket->depDay.c_str();
        if (std::regex_match((ticketInfo + i)->depDay.c_str(), result, regular))
            f[2] = true;
        if (personalTicket->coach == (ticketInfo + i)->coach)
            f[3] = true;
        if (f[0] && f[1] && f[2] && f[3])
            return true;
    }
    return false;
//    std::regex_match(strForChecking, result, regular)
}

int theMostExpensiveTicket(Ticket *ticketInfo){
    int i, max = 0;
    for (i = 0; i < numberOfTrains; i++)
        if (max < (ticketInfo + i)->price)  max = (ticketInfo + i)->price;

    return max;
}

void Ticket::setTrain(){
    std::cout << "Enter train number: ";
    std::cin>>this->train;
}