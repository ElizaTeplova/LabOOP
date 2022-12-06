//
// Created by mrbab on 06.12.2022.
//
#include <regex>
#include "record.h"
#include <cstdio>
#include <cstdlib>

void setInfoAboutRecord(Record *record) {
    std::cmatch result;
    std::regex regular("[A-Z][a-z]{1,14}");
    char *strForChecking;
    int i;

    strForChecking = (char *) calloc(AVAILABLE_SYMBOLS, sizeof(char));
    do {
        printf("Enter sport: [A-Z][a-z]{1,14}: ");
        scanf("%s", strForChecking);
    } while (!std::regex_match(strForChecking, result, regular));
    strcpy(record->sport, strForChecking);
    free(strForChecking);

    strForChecking = (char *) calloc(AVAILABLE_SYMBOLS, sizeof(char));
    do {
        printf("Enter discipline: [A-Z][a-z]{1,14}: ");
        scanf("%s", strForChecking);
    } while (!std::regex_match(strForChecking, result, regular));
    strcpy(record->discipline, strForChecking);
    free(strForChecking);

    strForChecking = (char *) calloc(AVAILABLE_SYMBOLS, sizeof(char));
    showContinents();
    do {
        printf("Enter continent: ");
        scanf("%c", &strForChecking[0]);
    } while (strForChecking[0] >= '7' || strForChecking[0] < '0');
    record->typeOfRecord = static_cast<Type_of_record>(atoi(&strForChecking[0]));
    printf("you wrote: %d\n", record->typeOfRecord);
    free(strForChecking);

    strForChecking = (char *) calloc(AVAILABLE_SYMBOLS, sizeof(char));
    showGenders();
    do {
        printf("Set gender: ");
        scanf("%c", &strForChecking[0]);
    } while (strForChecking[0] >= '2' || strForChecking[0] < '0');
    record->gender = static_cast<Gender>(atoi(&strForChecking[0]));
    printf("you wrote: %d\n", record->gender);
    free(strForChecking);

    strForChecking = (char *) calloc(AVAILABLE_SYMBOLS, sizeof(char));
    regular = R"(\d\d\.\d\d.\d\d)";
    do {
        printf(R"(Enter day: \d\d\.\d\d\.\d\d: )");
        scanf("%s", strForChecking);
    } while (!std::regex_match(strForChecking, result, regular));
    strcpy(record->date, strForChecking);
    printf("Day: %s\n", record->date);
    free(strForChecking);

    regular = "[A-Z][a-z]{1,14}";
    strForChecking = (char *) calloc(AVAILABLE_SYMBOLS, sizeof(char));
    do {
        printf("Enter patronymic: [A-Z][a-z]{1,14}: ");
        scanf("%s", strForChecking);
    } while (!std::regex_match(strForChecking, result, regular));
    strcpy(record->patronymic, strForChecking);
    free(strForChecking);

    strForChecking = (char *) calloc(AVAILABLE_SYMBOLS, sizeof(char));
    do {
        printf("Enter country: [A-Z][a-z]{1,14}: ");
        scanf("%s", strForChecking);
    } while (!std::regex_match(strForChecking, result, regular));
    strcpy(record->country, strForChecking);
    free(strForChecking);

    regular = R"([A-Z].{1,13})";
    strForChecking = (char *) calloc(AVAILABLE_SYMBOLS, sizeof(char));
    do {
        printf("Enter achievement: [A-Z][a-z]\\.{1,13} : ");
        gets(strForChecking);
    } while (!std::regex_match(strForChecking, result, regular));
    strcpy(record->achievement, strForChecking);
    free(strForChecking);

}

void showGenders() {
    printf("|---------------|---|\n");
    printf("|%-15s|%3d|\n", "MALE", MALE);
    printf("|---------------|---|\n");
    printf("|%-15s|%3d|\n", "FEMALE", FEMALE);
    printf("|---------------|---|\n");
}

void showContinents() {
    printf("|---------------|---|\n");
    printf("|%-15s|%3d|\n", "WORLD", 0);
    printf("|---------------|---|\n");
    printf("|%-15s|%3d|\n", "EUROPE", EUROPE);
    printf("|---------------|---|\n");
    printf("|%-15s|%3d|\n", "ASIA", ASIA);
    printf("|---------------|---|\n");
    printf("|%-15s|%3d|\n", "AFRICA", AFRICA);
    printf("|---------------|---|\n");
    printf("|%-15s|%3d|\n", "AMERICA_NORTH", AMERICA_NORTH);
    printf("|---------------|---|\n");
    printf("|%-15s|%3d|\n", "AMERICA_SOUTH", AMERICA_SOUTH);
    printf("|---------------|---|\n");
    printf("|%-15s|%3d|\n", "AUSTRALIA", AUSTRALIA);

}

void showAllFields(Record *record) {
    printf("|---------------|---------------|---|---|---------------|---------------|---------------|---------------|\n");
    printf("|%-15s", record->sport);
    printf("|%-15s", record->discipline);
    printf("|%-3d", record->typeOfRecord);
    printf("|%-3d", record->gender);
    printf("|%-15s", record->date);
    printf("|%-15s", record->patronymic);
    printf("|%-15s", record->country);
    printf("|%-15s|\n", record->achievement);
    printf("|---------------|---------------|---|---|---------------|---------------|---------------|---------------|\n");
}

int findNumbersOfRecordsAccordingToSport(Record *record, int f) {

    int i = 0;
    int quantity = -1;

    for (i = 0; i < numberOfRecords; i++) {
        if (strncmp((record + f)->sport, (record + i)->sport, strlen((record + f)->sport)) == 0) {
            quantity++;
        }
    }
//    printf("quantity: %d\n", quantity);
    return quantity;
}

void showWomenRecordsDuringLastYear(Record *record) {

    printf("Women with record in our 22 year: \n");
    for (int i = 0; i < numberOfRecords; i++) {
        if (
            (record + i)->typeOfRecord == WORLD &&
            secondCondition((record + i)->date) &&
            (record + i)->gender == FEMALE
            ) {
            showAllFields((record + i));
        }
    }
}

bool secondCondition(char *date) {

    if (date[6] == '2' && date[7] == '2') {
        return true;
    }

    return false;
}