#include <cstdio>
#include <cstdlib>
#include "remaked.h"

int main(){

    Ticket* personalTicket = (Ticket* ) calloc(1, sizeof(Ticket));
    FILE* outOfFile = fopen(R"(C:\textbooks\labs\oop\workshop\Task1\testTask1.txt)", "r");
    FILE* inToFile = fopen(R"(C:\textbooks\labs\oop\workshop\remakedAddT1\sortedTrains.txt)", "w");
    int i, j, trainNumber, maxPrice = 0;
    if (outOfFile == nullptr || inToFile == nullptr) {
        perror("Can't open file!\n");
        return EXIT_FAILURE;
    }
    Ticket* ticketInfo = (Ticket* )calloc(numberOfTrains, sizeof(Ticket ));


    //вынимаю инфу из файла
    extractInfo(inToFile, outOfFile, ticketInfo);
    fclose(outOfFile);
    printf("--------------------------------------------------------------------------------------------------\n");
    //сортирую полученную инфу
    sortInfo(ticketInfo, inToFile);
    printf("--------------------------------------------------------------------------------------------------\n");

    //заношу отсортированныфй массив по поездам в файл
    for (i = 0; i < numberOfTrains; i++){ inputTicketStructureToFiles(i, ticketInfo, inToFile); }

    //ищу количество свободных мест
    printf("Enter train number: ");
    scanf("%d", &personalTicket->train);
    showFlight(ticketInfo, personalTicket);
    fclose(inToFile);

    //ищу самый дорогой билет
    maxPrice = theMostExpensiveTicket(ticketInfo);
    printf("The most expensive ticket: %d\n", maxPrice);
    free(personalTicket);
    free(ticketInfo);
    system("pause");
}