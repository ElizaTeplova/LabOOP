//
// Created by mrbab on 20.11.2022.
//
#include "Ticket.h"

#ifndef TASK6_BOUGHTTICKET_H
#define TASK6_BOUGHTTICKET_H


//class Builder;

class BoughtTicket : public Ticket {

public:
    BoughtTicket();
    BoughtTicket(std::string &name, std::string &patronymic, std::string &dateOfPurchase, int train,
                 std::string &station1, std::string &station2, std::string &depDay, std::string depTime, int coach,
                 int seat, int price);

    BoughtTicket(BoughtTicket* pTicket);
    int setAllInfoFromLine(std::string& line);

    const std::string &getOwnerName() const;

    const std::string &getOwnerPatronymic() const;

    const std::string &getDateOfPurchase() const;

    friend std::istream &operator>>(std::istream &stream, BoughtTicket &ticket);

    friend std::ostream &operator<<(std::ostream &stream, BoughtTicket &ticket);

    friend std::ofstream &operator<<(std::ofstream &stream, BoughtTicket &ticket);

    friend std::ifstream &operator>>(std::ifstream& stream, BoughtTicket& ticket);

    BoughtTicket operator=(BoughtTicket rhs);

    void clear();


private:
    std::string ownerName;
    std::string ownerPatronymic;
    std::string dateOfPurchase;
};


#endif //TASK6_BOUGHTTICKET_H
