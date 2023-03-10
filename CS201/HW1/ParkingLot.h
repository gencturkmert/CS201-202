//Mert Gençtürk 22003506
#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <string>
#include "Car.h"

using namespace std;
class ParkingLot
{
public:
    ParkingLot(int id, int rows, int columns);
    ParkingLot();
    ~ParkingLot();
    int getRows();
    int getColumns();
    int getID();
    string **lot;
    Car** cars;
    void parkCar(string location, string carType, int plateNumber);
    void removeCar(int plateNumber);
    int emptySpaces;
    int carNumber;
private:
    int id;
    int rows;
    int columns;
    void sortCars();


};
#endif
