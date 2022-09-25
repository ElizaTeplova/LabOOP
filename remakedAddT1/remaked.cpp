//
// Created by mrbab on 25.09.2022.
//
#include "remaked.h"
#include <cstdlib>
#include <cstring>
#include <regex>

void extractInfo(FILE* inToFile, FILE* outOfFile, Ticket* ticketInfo){
    int i;
    char* checking;

    for (i = 0; i < numberOfTrains; i++){

        checking = (char* )calloc(numbersOfAvailableSymbols, sizeof(char ));
        fscanf(outOfFile, "%s", checking);
        (ticketInfo + i)->train = atoi(checking);
//        printf("|%3d|", (ticketInfo + i)->train);
        free(checking); checking = (char* )calloc(numbersOfAvailableSymbols, sizeof(char ));

        fscanf(outOfFile, "%s", (ticketInfo + i)->station1);
//        printf("|%15s|", (ticketInfo + i)->station1);

        fscanf(outOfFile, "%s", (ticketInfo + i)->station2);
//        printf("|%15s|", (ticketInfo + i)->station2);

        fscanf(outOfFile, "%s", (ticketInfo + i)->depDay);
//        printf("|%12s|  ", (ticketInfo + i)->depDay);

        strncpy((ticketInfo + i)->depTime, (ticketInfo + i)->depTime, 8);
        fscanf(outOfFile, "%s", (ticketInfo + i)->depTime);
//        printf("|%8s|", (ticketInfo + i)->depTime);

        fscanf(outOfFile,"%s", checking);
        (ticketInfo + i)->coach = atoi(checking);
//        printf("|%2d|", (ticketInfo + i)->coach);
        free(checking); checking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

        fscanf(outOfFile,"%s", checking);
        (ticketInfo + i)->seat = atoi(checking);
//        printf("|%2d|", (ticketInfo + i)->seat);
        free(checking); checking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

        fscanf(outOfFile,"%s", checking);
        (ticketInfo + i)->price = atoi(checking);
//        printf("|%6d|", (ticketInfo + i)->price);
        free(checking);
//        printf("\n");
    }

}

void sortInfo(Ticket* ticketInfo, FILE* inToFile){
    int i, j;
    Ticket tmp;

    for (i = 0; i < numberOfTrains - 1; i++){
        for (j = 0; j < numberOfTrains - i - 1; j++){
            //tmp = {0,"","","","",0,0,0, false};
            if ((ticketInfo + j)->train > (ticketInfo + j + 1)->train){

                tmp = *(ticketInfo + j);
                *(ticketInfo + j) = *(ticketInfo + j + 1);
                *(ticketInfo + j + 1) = tmp;
            }
        }
    }
    for (i = 0; i < numberOfTrains; i++)
        ticketsOutput(ticketInfo, i);

}

void ticketsOutput(Ticket* ticketInfo, int i){
    printf("i: %2d : %-5d", i, (ticketInfo + i)->train);
    printf("%-15s", (ticketInfo + i)->station1);
    printf("%-15s", (ticketInfo + i)->station2);
    printf("%-10s ", (ticketInfo + i)->depDay);
    printf("%-10s", (ticketInfo + i)->depTime);
    printf("%-3d", (ticketInfo + i)->coach);
    printf("%-3d", (ticketInfo + i)->seat);
    printf("%-6d", (ticketInfo + i)->price);
    printf("\n");
}

void inputTicketStructureToFiles(int i, Ticket* ticketInfo, FILE* inToFile){

    fprintf(inToFile,"%-5d",   (ticketInfo + i)->train);
    fprintf(inToFile,"%-16s",  (ticketInfo + i)->station1);
    fprintf(inToFile,"%-16s",  (ticketInfo + i)->station2);
    fprintf(inToFile,"%-10s",  (ticketInfo + i)->depDay);
    fprintf(inToFile,"%-10s",  (ticketInfo + i)->depTime);
    fprintf(inToFile,"%-5d",   (ticketInfo + i)->coach);
    fprintf(inToFile,"%-3d",   (ticketInfo + i)->seat);
    fprintf(inToFile,"%-4d\n", (ticketInfo + i)->price);
}

void showFlight(Ticket* ticketInfo, Ticket* personalTicket){
    int i, low = 0, high = 14, k = 0, quantity;
    for (i = 0; i < numberOfTrains; i++){

        if ((ticketInfo + i)->train == personalTicket->train){
            k++;
            high = i;
        }
    }
    low = high - k + 1;
    printf("high: %-2d  |  low: %-2d\n", high, low);

    for (i = low; i<=high;i++)
        ticketsOutput(ticketInfo, i);
    printf("--------------------------------------------------------------------------------------------------\n");

    do{
        printf("Enter station1: ");
        scanf("%s", personalTicket->station1);
        printf("Enter station2: ");
        scanf("%s", personalTicket->station2);
        printf("Enter depDay: ");
        scanf("%s", personalTicket->depDay);
        printf("Enter coach: ");
        scanf("%d", &personalTicket->coach);

        if (isCorrect(ticketInfo, personalTicket, low, high))
            break;
        printf("false\n");
    }while(true);

    printf("You choose: %s %s %s\n", personalTicket->station1, personalTicket->station2, personalTicket->depDay);
    printf("Coach: %d\n", personalTicket->coach);

    quantity = numberOfEmptySeats(ticketInfo, personalTicket, low, high);
    printf("number of empty seats in this coach: %d\n", quantity);

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

        regular = personalTicket->station1;
        if (std::regex_match((ticketInfo + i)->station1, result, regular))
            f[0] = true;
        regular = personalTicket->station2;
        if (std::regex_match((ticketInfo + i)->station2, result, regular))
            f[1] = true;
        regular = personalTicket->depDay;
        if (std::regex_match((ticketInfo + i)->depDay, result, regular))
            f[2] = true;
        if (personalTicket->coach == (ticketInfo + i)->coach)
            f[3] = true;
        if (f[0] && f[1] && f[2] && f[3])
            k--;
    }
    return k;
}

bool isCorrect(Ticket* ticketInfo, Ticket* personalTicket, int low, int high){
//    char* strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));
    int i;
    bool f[4] = {false, false, false, false};
    std::cmatch result;
    std::regex regular;
    for (i = low; i <= high; i++){
        regular = personalTicket->station1;
        if (std::regex_match((ticketInfo + i)->station1, result, regular))
            f[0] = true;
        regular = personalTicket->station2;
        if (std::regex_match((ticketInfo + i)->station2, result, regular))
            f[1] = true;
        regular = personalTicket->depDay;
        if (std::regex_match((ticketInfo + i)->depDay, result, regular))
            f[2] = true;
        if (personalTicket->coach == (ticketInfo + i)->coach);
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