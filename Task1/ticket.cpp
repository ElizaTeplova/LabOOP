//
// Created by mrbab on 11.09.2022.
//

#include "ticket.h"
#include <cstdio>
#include <regex>
#include <string>

void inputTicketStructure(ticket* ticketInfo, FILE* iFile, FILE* iBinFile){
    static int i = 0;
    static int j = 0;
    int multiplier = 1;
    char* strForChecking = nullptr;
    strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));
    std::cmatch result;
    std::regex regular("[1-9]\\d{2}");

    printf("Enter element of structure: train (int), [1-9]{3}\n");                                       //input ticket: train
    do { scanf("%s",strForChecking); } while (!std::regex_match(strForChecking, result, regular));
    for (j = 2; j >= 0; j--){
        (ticketInfo + i)->train += ((int) strForChecking[j] - 48) * multiplier;
        multiplier*=10;
    } multiplier = 1;
    printf("Train: %d\n", (ticketInfo + i)->train);
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = "[a-zA-Z\\s]{1,15}";
    printf("Enter element of structure: station1, (char), [a-zA-Z\\s]{1,15}\n");                                //input ticket: station1
    do { scanf("%s", strForChecking); } while (!std::regex_match(strForChecking, result, regular));
    for (j = 0; j < numbersOfAvailableSymbols; j++) (ticketInfo + i)->station1[j] = *(strForChecking + j);
    printf("Station1: %s\n", (ticketInfo + i)->station1);
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    printf("Enter element of structure: station2, (char), [a-zA-Z\\s]{1,15}\n");                                //input ticket: station1
    do { scanf("%s", strForChecking); } while (!std::regex_match(strForChecking, result, regular));
    for (j = 0; j < numbersOfAvailableSymbols; j++) (ticketInfo + i)->station2[j] = *(strForChecking + j);
    printf("Station1: %s\n", (ticketInfo + i)->station2);
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = R"(\d\d\.\d\d.\d\d)";
    printf("Enter element of structure: depDay, (char), \\d\\d.\\d\\d.\\d\\d\n");
    do { scanf("%s", strForChecking); } while (!std::regex_match(strForChecking, result, regular));
    for (j = 0; j < numbersOfAvailableSymbols; j++) (ticketInfo + i)->depDay[j] = *(strForChecking + j);
    printf("depDay: %s\n", (ticketInfo + i)->depDay);
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = R"([0-2]\d:[0-5]\d:[0-5]\d)";
    printf("Enter element of structure: depTime, (char), hh:mm:ss\n");
    do { scanf("%s", strForChecking); } while ( !std::regex_match(strForChecking, result, regular) ||
                                                (strForChecking[0] == '2') &&
                                                ((int )strForChecking[1] - 48 > 3));
    for (j = 0; j < numbersOfAvailableSymbols; j++) (ticketInfo + i)->depTime[j] = *(strForChecking + j);
    printf("depDay: %s\n", (ticketInfo + i)->depTime);
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = R"([1-9]\d{0,2})";
    printf("Enter element of structure: coach, (int), [1-9]\\d{0,2}\n");
    do { scanf("%s", strForChecking); } while ( !std::regex_match(strForChecking, result, regular));
    for (j = 0; j < numbersOfAvailableSymbols; j++) { if (strForChecking[j] == 0) break; } j--;
    for (; j>=0; j--){
        (ticketInfo + i)->coach += ((int )strForChecking[j] - 48) * multiplier;
        multiplier*=10;
    }
    printf("coach: %d\n", (ticketInfo + i)->coach);
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = R"([1-6])";
    printf("Enter element of structure: seat, (int), [1-6]\n");
    do { scanf("%s", strForChecking); } while ( !std::regex_match(strForChecking, result, regular));
    (ticketInfo + i)->seat = (int )strForChecking[0] - 48;
    printf("seat: %d\n", (ticketInfo + i)->seat);
    free(strForChecking); strForChecking = (char* ) calloc(numbersOfAvailableSymbols, sizeof(char ));

    regular = R"(\d{4})";
    printf("Enter element of structure: price, (int), \\d{4}\n");
    do { scanf("%s", strForChecking); } while ( !std::regex_match(strForChecking, result, regular));
    multiplier = 1;
    for (j = 3; j >= 0; j--){
        (ticketInfo + i)->price += ((int )strForChecking[j] - 48) * multiplier;
        multiplier *= 10;
    }
    printf("price: %d\n", (ticketInfo + i)->price);
    free(strForChecking);
    i++;

}


void inputTicketStructureToFiles(int i, ticket* ticketInfo, FILE* iFile, FILE* iBinFile){
    fwrite((ticketInfo + i), sizeof(ticket), 1, iBinFile);
    fprintf(iFile,"%-5d",   (ticketInfo + i)->train);
    fprintf(iFile,"%-16s",  (ticketInfo + i)->station1);
    fprintf(iFile,"%-16s",  (ticketInfo + i)->station2);
    fprintf(iFile,"%-10s",  (ticketInfo + i)->depDay);
    fprintf(iFile,"%-10s",  (ticketInfo + i)->depTime);
    fprintf(iFile,"%-5d",   (ticketInfo + i)->coach);
    fprintf(iFile,"%-3d",   (ticketInfo + i)->seat);
    fprintf(iFile,"%-4d\n", (ticketInfo + i)->price);
}

void theMostOfExpensiveTicket(int price){

}

void inputNumberOfTickets(int *number) { do { scanf("%d", number); } while (*number <= 0 || *number >= 11); }
