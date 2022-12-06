//
// Created by mrbab on 06.12.2022.
//

#ifndef FOR_ILA_TASK1_RECORD_H
#define FOR_ILA_TASK1_RECORD_H

//Asia, Africa, North America, South America, Antarctica, Europe, and Australia

#define numberOfRecords 2

enum Type_of_record {
    WORLD = 0,
    EUROPE = 1,
    ASIA = 2,
    AFRICA = 3,
    AMERICA_NORTH = 4,
    AMERICA_SOUTH = 5,
    AUSTRALIA = 6
};

enum Gender {
    MALE = 0,
    FEMALE = 1
};

#define AVAILABLE_SYMBOLS 15

struct Record {
    char sport[AVAILABLE_SYMBOLS];
    char discipline[AVAILABLE_SYMBOLS];
    Type_of_record typeOfRecord;
    Gender gender;
    char date[AVAILABLE_SYMBOLS];
    char patronymic[AVAILABLE_SYMBOLS];
    char country[AVAILABLE_SYMBOLS];
    char achievement[AVAILABLE_SYMBOLS];
};

void setInfoAboutRecord(Record *record);
void showContinents();
void showGenders();
void showAllFields(Record * record);

int findNumbersOfRecordsAccordingToSport(Record *record, int f);

void showWomenRecordsDuringLastYear(Record* record);

bool secondCondition(char* date);

#endif //FOR_ILA_TASK1_RECORD_H