#include <iostream> 

/*  함수 오버로딩이란 함수명은 같으며 인자의 자료형이나
    수가 다른 함수의 선언을 허용하는 것을 말함.
    
    c++에서는 두 함수의 이름이 같아도 컴파일러가 오류를 발생안시킴.
*/

namespace A { void Add() { printf("A의 Add() 호출 \n");}}
namespace B { void Add() { printf("B의 Add() 호출 \n");}}

namespace u4bi{ void good(){ printf("u4bi c++ \n"); } }
namespace github{
    void win(){ printf("github win\n");}
    void lose(){ printf("github lose\n");}
}

using namespace u4bi;
using github::win;

using namespace std;
void func(int a){
    cout << "int a : " << a << endl;
}
void func(int a, int b){
    cout << "int a : " << a << " int b : " << b << endl;
}
/*  함수 오버로딩의 특징
    함수명이 같아야 함.
    [매개변수의 수가 다르거나] 아니면 [그 매개변수의 수가 같고 자료형이 달라야 함].
*/

int main() {
    
    func(4);
    func(5, 6);
    
    good();
    
    win();
    github::lose();
    
    A::Add();
    B::Add();
    
    char name[10];
    int age;
    std::cin>>name>>age;
    std::cout << "내 닉네임은 " << name << "이며 " << age << "살입니다." <<std::endl;
    std::cout << "u4bi c++ workspace" <<std::endl;
    return 0;
}