/* 
   클래스 Car를 대상으로 파일을 나눈다고 예를 들어보기.
   
   Car.h 클래스의 선언을 담음.
   
   Car.cpp 클래스의 정의(멤버함수 정의)를 담음
  
   여기서 말하는 클래스 선언은 멤버변수의 선언과
   멤버함수의 원형을 포함한다고함.
   
   이는 클래스와 관련된 문장의 오류를 잡아내는데 필요한 최소한의 정보
   클래스를 구성하는 외형적인 틀을 보여줌
   
   ------------------------------------------------
   클래스의 정의(definition)에 해당하는 함수의 정의는
   다른 문장의 컴파일에 필요한 정보를 가지고 있지 않음.
   
   따라서 함수의 정의는 컴파일 된 이후에 링커에 의해
   하나의 실행 파일로 묶이기만 하면 된다고 함.
*/

#ifndef __CAR_H__
#define __CAR_H__

namespace CAR_CONST{
    enum{
        ID_LEN=20,MAX_SPD=200,FUEL_STEP=2,
        ACC_STEP=10,BRK_STEP=10
    }; /* 이넘에 차의 정보를 담음*/
}

/* car클래스 선언*/
class Car{
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
  
public:
    void initMembers(char *ID, int fuel);
    void showCarState();
    void Accel();
    void Break();
};

#endif

/* 헤더 파일에는 앞서 언급한 것처럼 클래스와 관련된 문장의 오류를
   잡는데 필요한 최소한의 정보만 들어있음.
   
   각종 상수와 멤버 변수, 멤버 함수 원형이 있는걸 알수 있음.*/

/* 28행과 52행에 생소한 #ifndef와 #endif가 있음.
   
   이건 말 그대로 __CAR_H__가 #define 으로 정의되어 있지 않다면
   아래 라인부터 #endif까지 포함시키라는
   
   전처리 지시어임 매크로
   
   반대로 #ifdef도 존재한다고 함.
*/

/*ifndef 같은 경우 헤더 파일의 중복 포함 문제를 방지하기 위한 매크로 선언이라고 함.*/