#include <iostream>
#include <cstring>
#include "Bike.h"
using namespace std;

void Bike::initPlayer(char *NAME, int fuel){
    strcpy(playerName, NAME);
    fuelGauge= fuel;
    speedGauge=0;
}
