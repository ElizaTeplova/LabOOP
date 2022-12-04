//
// Created by mrbab on 20.11.2022.
//

#include "BoughtTicket.h"
#include <regex>

BoughtTicket::BoughtTicket(std::string &name, std::string &patronymic, std::string &dateOfPurchase, int train,
                           std::string &station1, std::string &station2, std::string &depDay, std::string depTime,
                           int coach, int seat, int price) {
    Ticket(train, station1, station2, depDay, depTime, coach, seat, price);
    this->ownerName = name;
    this->ownerPatronymic = patronymic;
    this->dateOfPurchase = dateOfPurchase;
}

BoughtTicket::BoughtTicket() {
    Ticket();
    this->ownerName = "";
    this->ownerPatronymic = "";
    this->dateOfPurchase = "";
}

BoughtTicket::BoughtTicket(BoughtTicket *pTicket) {
    this->setTrain(pTicket->getTrain());
    this->setStation1(pTicket->getStation1());
    this->setStation2(pTicket->getStation2());
    this->setDepDay(pTicket->getDepDay());
    this->setDepTime(pTicket->getDepTime());
    this->setCoach(pTicket->getCoach());
    this->setSeat(pTicket->getSeat());
    this->setPrice(pTicket->getPrice());
    this->ownerName = pTicket->ownerName;
    this->ownerPatronymic = pTicket->ownerPatronymic;
    this->dateOfPurchase = pTicket->dateOfPurchase;
}


const std::string &BoughtTicket::getOwnerName() const {
    return ownerName;
}

const std::string &BoughtTicket::getOwnerPatronymic() const {
    return ownerPatronymic;
}

const std::string &BoughtTicket::getDateOfPurchase() const {
    return dateOfPurchase;
}

std::istream &operator>>(std::istream &stream, BoughtTicket &ticket) {
    stream >> static_cast<Ticket &>(ticket);
    std::cmatch result;
    std::regex regular("[A-Z][a-z]{3,15}");
    std::cout << "Enter name: [A-Z][a-z]{3,14}" << std::endl;
    char *strForChecking = (char *) calloc(numbersOfAvailableSymbols, sizeof(char));
    int i = 0;

    do {
        stream >> strForChecking;
    } while (!std::regex_match(strForChecking, result, regular));

    for (i = 0; i < strlen(strForChecking); i++) {
        ticket.ownerName += *(strForChecking + i);
    }
    free(strForChecking);

    strForChecking = (char *) calloc(numbersOfAvailableSymbols, sizeof(char));
    std::cout << "Enter patronymic: [A-Z][a-z]{3,14}" << std::endl;
    do {
        stream >> strForChecking;
    } while (!std::regex_match(strForChecking, result, regular));
    for (i = 0; i < strlen(strForChecking); i++) {
        ticket.ownerPatronymic += *(strForChecking + i);
    }
    free(strForChecking);

    regular = R"(\d\d\.\d\d.\d\d)";
    strForChecking = (char *) calloc(numbersOfAvailableSymbols, sizeof(char));
    std::cout << R"(Enter data or purchase: \d\d.\d\d.\d\d)" << std::endl;

    do {
        stream >> strForChecking;
    } while (!std::regex_match(strForChecking, result, regular));
    for (i = 0; i < strlen(strForChecking); i++) {
        ticket.dateOfPurchase += *(strForChecking + i);
    };
    free(strForChecking);

    return stream;
}


std::ostream &operator<<(std::ostream &stream, BoughtTicket &ticket) {
    stream << static_cast<Ticket &>(ticket) << " ";

    stream.setf(std::ios_base::left);
    stream << std::setw(numbersOfAvailableSymbols) << ticket.ownerName;
    stream << std::setw(numbersOfAvailableSymbols) << ticket.ownerPatronymic;
    stream << std::setw(numbersOfAvailableSymbols) << ticket.dateOfPurchase << std::endl;

    return stream;
}

std::ofstream &operator<<(std::ofstream &stream, BoughtTicket &ticket) {
    stream << static_cast<Ticket &>(ticket) << " ";
    stream << std::setw(numbersOfAvailableSymbols) << ticket.ownerName;
    stream << std::setw(numbersOfAvailableSymbols) << ticket.ownerPatronymic;
    stream << std::setw(10) << ticket.dateOfPurchase << std::endl;

    return stream;
}

int BoughtTicket::setAllInfoFromLine(std::string &line) {
    static_cast<Ticket>(this).setAllInfoFromLine(line);
    this->ownerName = line.substr(70, 70 + numbersOfAvailableSymbols);
    std::cout << "read ownerName: " << ownerName << std::endl;
    this->ownerPatronymic = line.substr(85, numbersOfAvailableSymbols);
    std::cout << "read ownerPatronymic: " << ownerName << std::endl;
    this->dateOfPurchase = line.substr(100, line.length());
    std::cout << "read date of purchase: " << dateOfPurchase << std::endl;
    return 0;
}

void BoughtTicket::clear() {
    this->ownerName = "";
    this->ownerPatronymic = "";
    this->dateOfPurchase = "";
//    static_cast<Ticket>(this).clear();
    this->setTrain(0);
    this->setStation1("");
    this->setStation2("");
    this->setDepTime("");
    this->setDepDay("");
    this->setCoach(0);
    this->setSeat(0);
    this->setPrice(0);
}

std::ifstream& operator>>(std::ifstream& stream, BoughtTicket& ticket) {
    std::string b;
    stream >> static_cast<Ticket& >(ticket);
    stream >> ticket.ownerName;
    stream >> ticket.ownerPatronymic;
    stream >> ticket.dateOfPurchase;
    std::getline(stream, b);
    return stream;
}

BoughtTicket BoughtTicket::operator= (BoughtTicket rhs) {
    this->setTrain(rhs.getTrain());
    this->setStation1(rhs.getStation1());
    this->setStation2(rhs.getStation2());
    this->setDepDay(rhs.getDepDay());
    this->setDepTime(rhs.getDepTime());
    this->setCoach(rhs.getCoach());
    this->setSeat(rhs.getSeat());
    this->setPrice(rhs.getPrice());
    this->ownerName = rhs.ownerName;
    this->ownerPatronymic = rhs.ownerPatronymic;
    this->dateOfPurchase = rhs.dateOfPurchase;
    return *this;
}