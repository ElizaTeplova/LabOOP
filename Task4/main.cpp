#include <iostream>
#include "RailwayStation.h"
int main() {
    RailwayStation railwayStation;
    Ticket personalTicket;
    int train;

    std::cout << "Enter train number: ";
    std::cin >> train;
    personalTicket.setTrain(train);
    railwayStation.showFlight(&personalTicket);

}
