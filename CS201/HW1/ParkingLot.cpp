//Mert Gençtürk 22003506
#include <iostream>
#include <string>
#include "ParkingLot.h"
#include "Car.h"


const char* list = "ABCDEFGHIJKL";
const string nos[] = {"1","2","3","4","5","6","7","8","9","10","11","12"};
const int MAX_SIZE = 12;

ParkingLot::ParkingLot(int idNo, int rowsNo, int columnsNo)
{
    id = idNo;
    rows = rowsNo;
    columns = columnsNo;
    emptySpaces = columns*rows;
    lot = new string *[rows];
    for (int i = 0; i < rows; i++)
    {
        lot[i] = new string[columns];
        for (int j = 0; j < columns; j++)
        {
            lot[i][j] = "+";
        }
    }

    cars = new Car *[columns*rows];
    for(int i = 0; i<emptySpaces; i++) {
        cars[i] = new Car();
    }

    carNumber =0;
}

ParkingLot::ParkingLot()
{
    id = 0;
    rows = 0;
    columns = 0;
    carNumber = 0;
    lot = NULL;
    cars = NULL;
}

ParkingLot::~ParkingLot()
{
    if(lot != NULL && cars != NULL) {
    for (int i = 0; i < rows; i++)
    {
        delete[] lot[i];
    }

    delete[] lot;

    for(int j=0; j<columns*rows;j++) {
        delete cars[j];
    }
    delete [] cars;
    }
}

int ParkingLot::getID() {
return id;
}

int ParkingLot::getColumns() {
return columns;
}

int ParkingLot::getRows(){
return rows;
}

void ParkingLot::parkCar(string location, string carType, int plateNumber) {
    char col = location[0];
    string row ="0";


    if(location.size() == 2) {
            row = location[1];
    }
    else {
        row = location.substr(1,3);
    }


    int colNo = -1;
    int type = -1;
    int rowNo = -1;

    if(carType == "a") {
        type = 1;
    }
    else if ( carType == "b") {
        type = 2;
    }


    for(int i = 0; i<MAX_SIZE; i++) {
        if(col == list[i]) {
            colNo = i + 1;
        }
    }

    for(int j=0;j<MAX_SIZE;j++) {
        if(row == nos[j]) {
            rowNo = j+1;
        }
    }



    if( colNo != -1) {
        if(type == 1) {
            if( lot[colNo-1][rowNo-1] == "+") {
                lot[colNo-1][rowNo-1] = "a";
                //delete?
                delete cars[carNumber];

                cars[carNumber] = new Car(type,colNo,rowNo,plateNumber,location);
                sortCars();
                cout<<"carno"<<carNumber<<endl;
                cout<<"Light-duty car with number plate "<<plateNumber<<" has been parked at location "<<
                location<<", lot "<<id<<endl;
                emptySpaces--;

            }
            else {
                //Place is already filled
                cout<<"Space is already filled by another car"<<endl;
            }
        }
        else if(type == 2) {
            if(colNo != 1){
            if( lot[colNo-1][rowNo-1] == "+" && rowNo<this->rows && lot[colNo-2][rowNo-1] == "+" ) {
                lot[colNo-1][rowNo-1] = "b";
                lot[colNo-2][rowNo-1] = "b";
                //delete ?
                delete cars[carNumber];
                cars[carNumber] = new Car(type,colNo,rowNo,plateNumber,location);
                sortCars();
                cout<<"carno"<<carNumber<<endl;
              //  cout<<"Successfully added"<<endl;
                cout<<"Heavy-duty car with number plate "<<plateNumber<<" has been parked at location "<<
                location<<", lot "<<id<<endl;
                emptySpaces = emptySpaces -2;
            }

                else{
                    cout<<"Space is already filled by another car"<<endl;
                }
            }else{
            cout<<"Cannot park, not enough space"<<endl;
            }

        }
    }




}

void ParkingLot::removeCar(int plateNumber){
    for(int i = 0; i<rows*columns;i++) {
        if(plateNumber == cars[i]->getPlate()) {
            Car* ptr = cars[i];
            if(ptr->getType() == 1) {
                lot[ptr->getRow()-1][ptr->getCol()-1] = "+";
            }else if (ptr->getType() == 2) {
                lot[ptr->getRow()-1][ptr->getCol()-1] = "+";
                lot[ptr->getRow()-2][ptr->getCol()-1] = "+";
            }
            delete ptr;
            cars[i] = new Car();
            cout<<plateNumber<<" succesfully removed from lot "<<id<<endl;
            sortCars();

        }
    }


}

void ParkingLot::sortCars() {
  int i, j;
    for (i = 0; i < rows*columns; i++) {

    // Last i elements are already in place
        for (j = 0; j < 30-i-1; j++) {
            if (cars[j]->getPlate()<cars[j+1]->getPlate()) {
                Car* temp = cars[j];
                cars[j] = cars[j+1];
                cars[j+1] = temp;
            }

        }
    }

    for(int k = 0; k <rows*columns ;k++){
        if(cars[k]->getPlate() == 0) {
            carNumber=k;
            break;
        }
    }
    }


