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

/* 바이크 엑셀 당김*/
void Bike::bikeAccel(){
  cout << "부아아아앙" << endl;
  if(fuelGauge <= 0) return; /* 0이거나 0이 더 높으면 리턴*/
  else fuelGauge -= BIKE_CONST::FUEL_STEP; /*아니면 상수에 설정된 만큼 차감하기*/
  
  if( (speedGauge+BIKE_CONST::ACC_STEP) >= BIKE_CONST::MAX_SPD){
    speedGauge = BIKE_CONST::MAX_SPD;
    return;
  }
  /* (현재속도+더해질 초기 상수속도값)이 최대속도(MAX_SPD)보다 높거나 같을때 최대속도로 변경하고 리턴*/
  speedGauge += BIKE_CONST::ACC_STEP;
  /*그게 아니여서 리턴이 안되면 현재 속도에 ACC_STEP 속도값을 더해줌*/
  
}

void Bike::bikeBreak(){
  cout << "끼이이익" << endl;
  if(speedGauge < BIKE_CONST::BRK_STEP){
    speedGauge = 0;
    return;
    /* BRK_STEP이 더 높을 때 현재 속도 0으로 변경하고 리턴*/
  }
  speedGauge -= BIKE_CONST::BRK_STEP;
  /*그게 아니여서 리턴이 안되면 현재 속도값에서 BRK_STEP값 만큼 빼줌*/
  
}