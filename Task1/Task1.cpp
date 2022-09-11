#include <cstdlib>
#include <cstdio>
#include "ticket.h"
int main() {
    ticket *ticketInfo;
    int i, j;
    int numberOfTickets;
    FILE *iFile;
    iFile = fopen(R"(C:\textbooks\labs\oop\workshop\Task1\testTask1.txt)", "a");
    FILE *iBinFile;
    iBinFile = fopen(R"(C:\textbooks\labs\oop\workshop\Task1\testTask1.bin)", "ab");
    printf("Enter number of tickets in the range from 0 to 10 inclusive:\n");
    inputNumberOfTickets(&numberOfTickets);
    printf("Numbers of tickets considered: %d\n", numberOfTickets);
    ticketInfo = (ticket*) calloc(numberOfTickets, sizeof(ticket));

    if (iFile == nullptr || iBinFile == nullptr){
        perror("Can't open file iFile or iBinFile");
        return EXIT_FAILURE;
    }

    for (i = 0; i < numberOfTickets; i++) {
        inputTicketStructure(ticketInfo, iFile, iBinFile);
        if (i != 0)
            for (j = i - 1; j >= 0; j--)
                if (
                        (ticketInfo + i)->train     == (ticketInfo + j)->train      &&
                        (ticketInfo + i)->station1  == (ticketInfo + j)->station1   &&
                        (ticketInfo + i)->station2  == (ticketInfo + j)->station2   &&
                        (ticketInfo + i)->depDay    == (ticketInfo + j)->depDay     &&
                        (ticketInfo + i)->depTime   == (ticketInfo + j)->depTime    &&
                        (ticketInfo + i)->coach     == (ticketInfo + j)->coach      &&
                        (ticketInfo + i)->seat      == (ticketInfo + j)->seat       &&
                        (ticketInfo + i)->price     == (ticketInfo + j)->price
                        ) {
                    (ticketInfo + i)->theSame = true;
                    printf("You wrote the same data as ticketInfo[%d]\n", j);
                }
        if (!ticketInfo->theSame)
            inputTicketStructureToFiles(i, ticketInfo, iFile, iBinFile);
    }

    fclose(iFile);
    fclose(iBinFile);
    free(ticketInfo);


    return 0;
}

/*
 * Условие задачи поставлено с неточностями, а именно:
 * непонятно как мне считать количество свободных мест в заданном вагоне заданного поезда
 * по-нормально если я руки устанут вбивать, заполнив 3 структуры. Так же наверное нкжно обработать ошибки когда
 * мы ввели одинаковые данные ведь такого не может быть
 */
