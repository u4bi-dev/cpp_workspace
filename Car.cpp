#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::initMembers(char *ID, int fuel){
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed=0;

}

void Car::showCarState(){
    cout << "소유자번호 : " << gamerID << endl;
    cout << "연료량 : " << fuelGauge << endl;
    cout << "현재속도 : " << curSpeed << endl;
}

void Car::Accel(){
    cout << "부아아앙" << endl;
    if(fuelGauge <=0) return;
    else fuelGauge -= CAR_CONST::FUEL_STEP;
  
    if(curSpeed+CAR_CONST::ACC_STEP)curSpeed = CAR_CONST::MAX_SPD; return;
    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break(){
     cout << "끼이익" << endl;
    if(curSpeed+CAR_CONST::BRK_STEP) curSpeed=0; return;
    curSpeed -= CAR_CONST::BRK_STEP;
}