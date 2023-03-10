//Mert Gençtürk 22003506
#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

Car::Car(int typeNo, int rowNo, int colNo,int plateNo,string loc) {
    type = typeNo;
    row = rowNo;
    col = colNo;
    plate = plateNo;
    location = loc;
}
Car::Car() {
    plate = 0;
    type=0;
    row=-1;
    col=-1;
    location ="";
}
Car::~Car() {
}
int Car::getRow(){
    return row;
}
int Car::getCol(){
        return col;
    }
int Car::getType(){
        return type;
    }
int Car::getPlate(){
return plate;
}
string Car::getLocation() {
return location;
}
