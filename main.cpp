#include <iostream> 

/*  힙 영역에 메모리 공간을 할당할 수 있게 도와주는 함수
    new 함수로 메모리를 동적 할당 delete로 동적 할당한 메모리를 해제함.
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
void func(int a){ cout << "int a : " << a << endl; }
void func(int a, int b){ cout << "int a : " << a << " int b : " << b << endl; }

int main() {
    
    int * ptr1 = new int; // 객체를 동적 할당
    int * ptr2 = new int[10]; // 길이가 10인 객체의 배열을 동적 할당
    delete ptr1; // 동적 할당된 객체를 소멸 - 3행
    delete []ptr2; // 동적 할당된 객체의 배열을 소멸 - 4행
    /*  동적 할당된 객체의 배열을 소멸시킬때는 4행처럼 작성해야 함
        만약 3행처럼 소멸시킬다면 메모리 누수가 발생한다고 함.
    */
    
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