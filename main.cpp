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

void NewDeleteExample(){
    int len, total=0;
    int * score;
    int i;
    
    cout << "학생수 입력 : ";
    cin >> len;
    
    score = new int[len];
    /*  new 연산이 등장 len에 5라는 값이 들어왔다고 가정하면
        길이가 5인 int형 배열을 동적 할당함
    */
    
    for(i=0; i<len; i++){
        cout << i+1 << "번 학생의 점수: ";
        cin >> score[i];
        
        total += score[i];
    }
    
    cout << "모든 학생의 평균: " << total/len << endl;
    delete []score;
    /*  동적으로 할당된 int형 배열이기 때문에 []score로 해제해주어야 함
    
    delete와 delete[]는 서로 다른 기능을 하는 연산자임.
    
    delete 연산자를 사용하면 단일 객체에 대한 소멸자를 호출하고 메모리를 반환 함
    그러나 delete[] 연산자를 사용하면 각 요소마다 소멸자를 호출하여 메모리 반환 함.
    */
}
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
    
    NewDeleteExample();
        
    char name[10];
    int age;
    std::cin>>name>>age;
    std::cout << "내 닉네임은 " << name << "이며 " << age << "살입니다." <<std::endl;
    std::cout << "u4bi c++ workspace" <<std::endl;
    return 0;
}