#include <iostream> 

/*  C++의 접근 제어 지시자에는 public, private, protected가 있음
    만약 접근 제어가 생략될 경우 기본적으로 public멤버로 간주 됨.
    
    public : 어디서든 접근이 가능
    private : 외부에서 접근이 불가능
    protected : 외부에서 접근이 불가능하나 상속된 파생 클래스에서는 접근이 허용
    
    protected는 상속관련 항목에서 다시 다룸
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

struct user{
private:
    int id;
    char *name;
    float exp;
public:
    void show();
    void setInfo(int _id, char * _name, float _exp);
/*  28행과 32행을 보면 각각 private와 public 지시자가 쓰여있음.
    이는 멤버 변수인 id, name, exp의 접근이 private로 제한 되었음을 의미
    
    그리고 지시자를 사용할 때 private: public : 이런식으로
    지시자 뒤에 :를 붙혀서 사용해야 한다고 함
    
    show() 와 showInfo()는 public 지시자로 지정 됨
*/
};

void user::show(){
    cout << "번호 : " << id << endl;
    cout << "이름 : " << name << endl;
    cout << "경험 : " << exp << endl;
}

void user::setInfo(int _id, char * _name, float _exp){
    id = _id;
    name = _name;
    exp = _exp;
}

struct player{
    int id;
    char name[24];
    float exp;
    
    void show(){
        cout << "번호 : " <<id << endl;
        cout << "이름 : " <<name << endl;
        cout << "경험 : " <<exp << endl;
    }
    /*  구조체 내에 함수 사용 : void show()
    */
    void show_Example2();
};

/* 함수의 정의를 밖으로 빼낼 수도 있음. 이 역시 결과 같음. */
void player::show_Example2(){
    cout << "번호 : " <<id << endl;
    cout << "이름 : " <<name << endl;
    cout << "경험 : " <<exp << endl;
}

void func(int a){ cout << "int a : " << a << endl; }
void func(int a, int b){ cout << "int a : " << a << " int b : " << b << endl; }

void NewDeleteExample(){
    int len, total=0; int * score; int i;    
    cout << "학생수 입력 : ";
    cin >> len;
    
    score = new int[len];
    
    for(i=0; i<len; i++){
        cout << i+1 << "번 학생의 점수: ";
        cin >> score[i];
        total += score[i];
    }
    cout << "모든 학생의 평균: " << total/len << endl;
    delete []score;
}

int main() {
    
    user u;
    //u.id = 1
    /* u.id = 1 은 위에서 private 지시자로 설정 외부에서 접근 불가 내부에서만 가능*/
    u.setInfo(123, "u4bi", 55.6);
    u.show();
    
    player p = {1, "u4bi", 67.5};
    cout << "번호 : " <<p.id << endl;
    cout << "이름 : " <<p.name << endl;
    cout << "경험 : " <<p.exp << endl;
    
    p.show();
    /*  구조체 내의 함수를 구초체 변수에 접근하듯 호출함
    */
    p.show_Example2();
    
    int * ptr1 = new int;
    int * ptr2 = new int[10];
    delete ptr1;
    delete []ptr2;
    
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