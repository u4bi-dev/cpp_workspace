#include <iostream>
#include <cstring>
#include "Bike.h"
using namespace std;

/* 이닛 유저이름, 초기 주입될 기름*/
void Bike::initPlayer(char *NAME, int fuel){
    strcpy(playerName, NAME);
    fuelGauge= fuel;
    speedGauge=0;
}

/* 현재 바이크 상태보기*/
void Bike::showBikeState(){
  cout << "이름 : " << playerName << " 현재 연료 : " << fuelGauge << " 현재 속도 : " << speedGauge << endl;
}