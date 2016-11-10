#include <iostream> 

/*  네임 스페이스란 뭘까
    예로 A, B, C 팀으로 나누어 팀 프로젝트 진행함.
    이렇게 팀 나누어 개발이 모두 끝나면 A, B, C가 개발한
    프로젝트를 하나로 합친다고 생각해보자.
    
    그렇게 해서 프로젝트를 합치고 모든 일이 만사천리로 해결되는듯
    하였으나 A에서 정의한 함수의 이름과 B에서 정의한 함수의 이름
    C에서 정의한 함수의 이름이 상당수가 동일하여 충돌이 일어날것임.
    
    위의 문제를 해결하기 위해선 어떻게 해야할까 라는 주제다.
    
    네임스페이스로 이러한 충돌을 미연에 방지할 수 있음.
    
    네임 스페이스를 간단히 말하면 관련 있는 녀석끼리
    모여있는 공간을 말함.
    
*/
namespace A {
    void Add() {
        printf("A의 Add() 호출 \n");
    }
}
 
namespace B {
    void Add() {
        printf("B의 Add() 호출 \n");
    }
}

int main() {
    /*  여기서 :: 연산자는 범위 지정 연산자
        어떠한 네임스페이스를 가리킬 때 사용하는 연산자임.
        
        정리하자면 아래와 같이 정의
        
        namespace 이름{
            변수, 함수 등
        }
        
    */
    A::Add();
    B::Add();
    
    char name[10];
    int age;
    std::cin>>name>>age;
    std::cout << "내 닉네임은 " << name << "이며 " << age << "살입니다." <<std::endl;
    std::cout << "u4bi c++ workspace" <<std::endl;
    return 0;
}