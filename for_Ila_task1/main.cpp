#include <iostream>
#include "record.h"


int main() {

    Record *record = (Record* ) calloc(3, sizeof(Record ));

    system("pause");

    for (int i = 0; i < 2; i++) {
        setInfoAboutRecord((record + i));
    }
    for (int i = 0; i < 2; i++) {
        showAllFields((record + i));
    }

    printf("%d\n", findNumbersOfRecordsAccordingToSport(record, 3));
    showWomenRecordsDuringLastYear(record);
    system("pause");

    free(record);

    return EXIT_SUCCESS;
}
