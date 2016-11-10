#include <iostream> 

/*  객체 생성시에 호출되는 생성자
    private로 지정된 멤버 변수 초기화 시키기 위해 SetInfo 함수를 따로 만들어 초기화 함
    그런데 이것보다 더 편하게 객체 생성과 동시에 초기화 시키는게 생성자임
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

class human{
private:
    char *name;
    int age;
public:
    human(char *_name, int age);
    void ShowInfo();
};
/*  위의 형식처럼 생성자를 정의할 때 생성자의 이름이 클래스의 이름과 같음
    생성자도 함수와 같이 매개변수를 가질 수 있음 그리고 반환형이 없음 */
human::human(char *_name, int _age){
    name = _name;
    age = _age;
}
void human::ShowInfo(){
    cout << "이름 : " << name << " 나이 : " << age << endl;
}

class child{
private:
    char *name;
    int age;
    char *hobby;
public:
    void ShowInfo();
    void SetInfo(char *_name, int _age, char *_hobby);
    void Study();
    void Sleep();
};
void child::ShowInfo(){
    cout << "이름 : " << name << " 나이 : " << age << " 취미 : " << hobby << endl;
}
void child::SetInfo(char *_name, int _age, char *_hobby){
    name = _name;
    age = _age;
    hobby = _hobby;
}
void child::Study(){
    cout << "공부!" << endl;
}
void child::Sleep(){
    cout << "잠!" << endl;
}

struct user{
private:
    int id;
    char *name;
    float exp;
public:
    void show();
    void setInfo(int _id, char * _name, float _exp);
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
    void show_Example2();
};

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
    
    /* 객체 생성시 호출되는 생성자에게 인자를 넘겨 초기화 시킴*/
    human h("u4bi", 12);
    h.ShowInfo();
    
    child c;
    c.SetInfo("u4bi", 11, "c++");
    c.ShowInfo();
    c.Study();
    c.Sleep();
    
    user u;
    u.setInfo(123, "u4bi", 55.6);
    u.show();
    
    player p = {1, "u4bi", 67.5};
    cout << "번호 : " <<p.id << endl;
    cout << "이름 : " <<p.name << endl;
    cout << "경험 : " <<p.exp << endl;
    
    p.show();
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