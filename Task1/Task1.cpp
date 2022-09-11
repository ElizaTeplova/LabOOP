#include <cstdlib>
#include <cstdio>
#include "ticket.h"
int main() {
    ticket *ticketInfo;
    int numberOfTickets;

    printf("Enter number of tickets in the range from 0 to 10 inclusive:\n");
    inputNumberOfTickets(&numberOfTickets);
    printf("Numbers of tickets considered: %d\n", numberOfTickets);
    ticketInfo = (ticket*) calloc(numberOfTickets, sizeof(ticket));


    inputTicketStructure(ticketInfo);


    free(ticketInfo);
    return 0;
}
