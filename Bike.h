#ifndef __BIKE_H__
#define __BIKE_H__

namespace CAR_CONST{ /**/
    enum{
        ID_LEN=20, MAX_SPD=200, FUEL_STEP=2, ACC_STEP=10, BRK_STEP=10
          /* enum에 바이크에 대한 정보를 담음*/
    };
}

/* car 클래스 선언*/
class Bike{
private:
    char playerName[CAR_CONST::ID_LEN]; /* 유저이름 [상수 이름의 랭쓰]*/
    int fuelGauge; /* 기름게이지*/
    int speedGauge; /* 속도게이지*/
  
public:
  void initPlayer(char *NAME, int fuel); /* 이닛 유저이름, 초기 주입될 기름*/
  void showBikeState(); /* 현재 바이크 상태보기*/
  void bikeAccel(); /* 바이크 엑셀 당김*/
  void bikeBreak(); /* 바이크 브레이크 당김*/
}

#endif