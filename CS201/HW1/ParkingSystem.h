//Mert Gençtürk 22003506
#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H

#include <string>
#include "ParkingLot.h"
using namespace std;

class ParkingSystem
{
public:
    ParkingSystem();
    ~ParkingSystem();
    void createLot(int id, int rows, int columns);
    void removeLot(int id);
    void listLots();
    void lotContents(int id);
    void parkCar(int lotId, string location, string carType, int plateNumber);
    void findCar(int plateNumber);
    void removeCar(int plateNumber);

private:
    ParkingLot** lotArray;
    int checkId(int id);
    int lotNumber;
    void sortLot();

};

#endif

