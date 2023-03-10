//Mert Gençtürk 22003506
#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
using namespace std;


class Car{
public:
    Car(int typeNo, int rowNo, int colNo,int plateNo,string loc );
    Car();
    ~Car();
    int getRow();
    int getCol();
    int getType();
    int getPlate();
    string getLocation();

private:
    int col;
    int row;
    int type; //1 for a 2 for b
    int plate;
    string location;
};
#endif // CAR_H
