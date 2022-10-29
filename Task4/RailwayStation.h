#pragma once
#include "Ticket.h"
#include <fstream>
#include <vector>

#ifndef TASK4_RAILWAYSTATION_H
#define TASK4_RAILWAYSTATION_H


class RailwayStation {
private:
    static const std::string DEFAULT_FILE_PATH;
    static const std::string DEFAULT_FILE_NAME;
    static int sizeTrain;

    std::string stationAddress;
    std::vector<Ticket> ticket;
public:
    RailwayStation() : RailwayStation(sizeTrain, (std::string&)DEFAULT_FILE_NAME, (std::string&)DEFAULT_FILE_PATH){

    }
    RailwayStation(int numberOfTrainsClass);
    RailwayStation(int numberOfTrainsClass, std::string& fileName, std::string& filePath);

    ~RailwayStation(){
        ticket.clear();
    }
};


#endif //TASK4_RAILWAYSTATION_H
