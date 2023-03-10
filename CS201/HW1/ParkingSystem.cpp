//Mert Gençtürk 22003506


#include <iostream>
#include <string>
#include "ParkingSystem.h"
#include "ParkingLot.h"


const char* list2 = "ABCDEFGHIJKL";
const int nos2[] = {1,2,3,4,5,6,7,8,9,10,11,12};

ParkingSystem::ParkingSystem()
{
    lotNumber = 0;

    lotArray = new ParkingLot* [30];
    for(int i = 0; i<30; i++) {
        lotArray[i] = new ParkingLot();
    }
}

//check if parking lots are destructed too
ParkingSystem::~ParkingSystem()
{
    for(int i = 0; i<30; i++) {
        delete lotArray[i];
    }
    delete[] lotArray;
}

void ParkingSystem ::createLot(int idNumber, int rows, int columns)

{
    if (rows > 12 || columns > 12)
    {
        cout << "Cannot create the parking lot" << idNumber << ", dimensions exceed acceptable bounds" << endl;
    }
    else if (idNumber == 0)
    {
        cout << "Lot ID cannot be 0" << endl;
    }
    else
    {
        int creation = 0;

        for (int k = 0; k < 30; k++)
        {
            if (idNumber == lotArray[k]->getID())
            {
                creation = -1;
            }
        }

        if (creation == 0)
        {
            delete lotArray[lotNumber];
            lotArray[lotNumber] = new ParkingLot(idNumber, rows, columns);
            cout<<"Parking lot with ID "<<idNumber <<" and dimensions ("<< rows<<","<<columns<<") has been added to the system"<<endl;
            lotNumber++;
            sortLot();
            //delete ptr;
        }
        else
        {
            cout << "Cannot create the parking lot " << idNumber << ", a lot with this ID already exists" << endl;
        }
    }
}


void ParkingSystem ::removeLot(int id)
{
    int exists=0;
    for (int i = 0; i < 30; i++)
    {
        if (lotArray[i]->getID() == id)
        {

            delete lotArray[i];
            lotArray[i] = new ParkingLot();
            cout<<"Lot array "<<id<<" succesfully removed"<<endl;
            exists =1;
        }
    }

    if(exists == 1) {
    sortLot();
    }else{
    cout<<"Lot "<<id<<" cannot found"<<endl;
    }
}

//Empty Parking Spaces will be added
void ParkingSystem ::listLots()
{
    cout << "List of lots:" << endl;
    for (int i = 0; i < 30; i++)
    {
        //cout<<"lotArrayid:"<<lotArray[i]->getID()<<endl;
        if (lotArray[i]->getID() != 0)
        {

            cout << "ID: " << lotArray[i]->getID() << ", Dim: (" << lotArray[i]->getRows() << "," << lotArray[i]->getColumns() << "), number of empty parking spaces:" << endl;
            cout<<"i:"<<i<<endl;
        }
    }
}

void ParkingSystem::lotContents(int id)
{
    ParkingLot* ptr = NULL;
    for(int i = 0; i<30; i++) {
        if( id == lotArray[i]->getID()) {
            ptr = lotArray[i];
            break;
        }
    }

    if(ptr == NULL) {
        cout<<"Lot does not exist!"<<endl;
    }
    else{
    cout<<"ID: "<<id<<", ("<<ptr->getRows()<<","<<ptr->getColumns()<<"), empty slots: "<<ptr->emptySpaces<<" parked cars: ";
    for(int o = 0; o<ptr->getColumns()*ptr->getRows(); o++) {
            if(ptr->cars[o]->getPlate() != 0) {
            cout<<ptr->cars[o]->getPlate()<<" ";
            }
    }
    cout<<endl;

    cout<<"   ";
    for(int j = 0; j< ptr->getColumns(); j++) {
        cout<<nos2[j]<<" ";
    }
    cout<<endl;

    for(int k = 0; k<ptr->getRows();k++) {

        cout<<list2[k]<<"  ";

        for(int h = 0; h<ptr->getColumns();h++) {
        if(h - 10 > -2) {
        cout<<ptr->lot[k][h]<<"  ";
        }else{
            cout<<ptr->lot[k][h]<<" ";
        }
        }
        cout<<endl;
    }
    }


}

void ParkingSystem ::parkCar(int lotId, string location, string carType, int plateNumber)
{
    int exists=0;
    for(int i = 0; i<30;i++) {
        if(lotArray[i]->getID() == lotId) {
            lotArray[i]->parkCar(location,carType,plateNumber);
            exists = 1;
            break;
        }
    }

    if(exists == 0) {
        cout<<"Lot "<<lotId<<" is not in the system!"<<endl;
    }
}

void ParkingSystem ::findCar(int plateNumber)
{
    int creation = 0;
    for(int i = 0; i<30;i++) {
        for(int j=0; j<lotArray[i]->getColumns()*lotArray[i]->getRows();j++) {

            if(lotArray[i]->cars[j]->getPlate() == plateNumber) {
                    creation = 1;

                if(lotArray[i]->cars[j]->getType()==1){

                    cout<<"Light-duty car with number plate "<<lotArray[i]->cars[j]->getPlate()<<" is at location "<<
                    lotArray[i]->cars[j]->getLocation()<<", lot "<<lotArray[i]->getID()<<endl;
                }
                else if(lotArray[i]->cars[j]->getType()==2){

                    cout<<"Heavy-duty car with number plate "<<lotArray[i]->cars[j]->getPlate()<<" is at location "<<
                    lotArray[i]->cars[j]->getLocation()<<", lot "<<lotArray[i]->getID()<<endl;
                }
            }
        }
    }

    if(creation == 0){
        cout<<plateNumber<<" not found"<<endl;
    }
}

void ParkingSystem ::removeCar(int plateNumber)
{
    int removal = 0;
    for(int i = 0; i<30;i++) {
        for(int j=0; j<lotArray[i]->getColumns()*lotArray[i]->getRows();j++) {

            if(lotArray[i]->cars[j]->getPlate() == plateNumber) {
                   lotArray[i]->removeCar(plateNumber);
                   removal = 1;
            }
        }
}
    if(removal == 0){
        cout<<plateNumber<<" not found"<<endl;
    }
}

void ParkingSystem::sortLot() {

    int i, j;
    for (i = 0; i < 30; i++) {

    // Last i elements are already in place
        for (j = 0; j < 30-i-1; j++) {
            if (lotArray[j]->getID()<lotArray[j+1]->getID()) {
                ParkingLot* temp = lotArray[j];
                lotArray[j] = lotArray[j+1];
                lotArray[j+1] = temp;
            }

        }
    }

    for(int k = 0; k <30 ;k++){
        if(lotArray[k]->getID() == 0) {
            lotNumber=k;
            break;
        }
    }
}
