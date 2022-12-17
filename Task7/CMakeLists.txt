cmake_minimum_required(VERSION 3.0)
project(Task7)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task7 main.cpp Ticket.cpp Ticket.h RailwayStation.cpp RailwayStation.h BoughtTicket.cpp BoughtTicket.h ElectronicTicket.cpp ElectronicTicket.h)
