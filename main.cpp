#include <iostream> 
#include <cstring>
 
/*  오버라이딩이란?

    오버로딩이 인자의 자료형이나 수가 다른 함수를 같은 이름으로 여러번 중복 정의하는 것이라면
    오버라이딩은 이미 있는 함수를 무시해버리고 새롭게 함수를 재정의하는 것이라고 말할 수 있음.
    
    더 자세히 말하자면 오버라이딩(overriding, 재정의)는 부모 클래스와 자식 클래스의 상속 관계에서
    부모 클래스에 이미 정의된 함수를 같은 이름으로 자식 클래스에서 재정의 하는 것을 의미함.
    
    이때 부모의 멤버 함수의 원형이 완전 같아야 한다고 함. 그리고 오버라이딩 시 부모 클래스의 함수가 모두 가려진다 함
*/

#define PI 3.141592
// #define CU(x) ((x)*(x)*(x))

inline int CU(int x){
    return x*x*x;
}

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

class overriding_A{
/* A라는 클래스가 정의 */
public: void over(){ cout << " A 클래스의 over 함수 호출 " << endl; }
/* 내부를 보면 over()라는 함수가 존재 */
};
class overriding_B : public overriding_A {
/* 그리고 B라는 클래스가 정의 이 B 클래스는 A라는 클래스를 상속 */
public: void over(){ cout << " B 클래스의 over 함수 호출 " << endl; }
/* B 클래스 내부에도 over()라는 함수가 존재함 */
};

class thisPointer{
private:
    int age;
public:
    thisPointer(int age){
        age = age;
    }
};

class ThisPointExample{
private:
    int num_a;
    int num_b;
public:
    ThisPointExample(int num_a, int num_b){
        this->num_a = num_a;
        this->num_b = num_b;
    }
    void getInfo(){
        cout << "num a : " << num_a << endl;
        cout << "num_b : " << num_b << endl;
    }
};

class ItemEX{
private:
    int id;
    char name[10];
    int price;
public:
    ItemEX(int _id, char *_name, int _price) : id(_id), price(_price) { strcpy(name, _name); }
    void getInfo(){
        cout << "번호 : " << id << endl;
        cout << "물품 : " << name << endl;
        cout << "가격 : " << price << endl;
    }
};

class Item{
private:
    int id;
    char name[10];
    int price;
public:
    Item(){ cout << "생성자 호출 " << endl; }
    void setInfo(int _id, char *_name, int _price){
        id = _id;
        strcpy(name, _name);
        price = _price;
    }
    void getInfo(){
        cout << "번호 : " << id << endl;
        cout << "물품 : " << name << endl;
        cout << "가격 : " << price << endl;
    }
    ~Item(){ cout << "소멸자 호출 " << endl; }
};

class Parent{
private : int num_a;
protected : int num_b;
public : int num_c;
};
class Base_Private : private Parent{};
class Base_Protected : protected Parent{};
class Base_Public : public Parent{};
 
class memInit{
private:
    int num_a;
    int num_b;
public:
    memInit(int _num_a, int _num_b) : num_a(_num_a), num_b(_num_b){}
    void show(){
        cout << "num a : " << num_a << " num b : " << num_b << endl;
    }
};

class Human{
private:
    int age;
    char name[10];
    char hobby[20];
public:
    Human(int _age, char *_name, char *_hobby) : age(_age){
        strcpy(name, _name);
        strcpy(hobby, _hobby);
    }
    void getup(){ cout << "기상!" << endl; }
    void sleep(){ cout << "취침!" << endl; }
    void eat(){ cout << "식사!" << endl; }
    void study(){ cout << "공부!" << endl; }
    void showInfo(){
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
        cout << "취미 : " << hobby << endl;
    }
};
class Student : public Human {
private:
    char school[30];
public:
    Student(int _age, char *_name, char *_hobby, char *_school) : Human(_age, _name, _hobby){
        strcpy(school, _school);
    }
    void schoolInfo(){
        showInfo();
        cout << "학교 : " << school << endl;
    }
};

class Friend_B;
class Friend_A{
private:
    int adata;
public:
    Friend_A(int _data){
        adata = _data;
    }
    void show(Friend_B b);
    friend class Friend_B;
};

class Friend_B{
private:
    int bdata;
public:
    Friend_B(int _data){
        bdata = _data;
    }
    void show(Friend_A a){
        cout << "a.data : " << a.adata << endl;
    }
    friend class Friend_A;
};

void Friend_A::show(Friend_B b){
    cout << "b.data : " << b.bdata << endl;
}

class deep{
private:
    char *str;
public:
    deep(const char *_str){
        str = new char[strlen(_str)+1];
        strcpy(str, _str);
    }
    deep(const deep& dp){
        str = new char[strlen(dp.str)+1];
        strcpy(str, dp.str);
    }
    ~deep(){
        delete []str;
        cout << "~deep()" << endl;
    }
    void show(){
        cout << "str : " << str << endl;
    }
};

class shallow{
private:
    char *str;
public:
    shallow(const char *_str){
        str = new char[strlen(_str)+1];
        strcpy(str, _str);
    }
    ~shallow(){
        delete []str;
        cout << "~shallow()" << endl;
    }
    void show(){
        cout << "str: " << str << endl;        
    }
};

class dog{
public:
    dog(){
        cout << "dog()" << endl;
    }
    ~dog(){
        cout << "~dog()" << endl;
    }
};

class copied{
private:
    int num1;
    int num2;
public:
    copied(int a, int b){
        num1 = a;
        num2 = b;
    }
    void show(){
        cout << "num1 : " << num1 << " num2 : " << num2 << endl;
    }
};

class human{
private:
    char *name;
    int age;
public:
    human();
    human(char *_name);
    human(char *_name, int age);
    void ShowInfo();
};
human::human(char *_name, int _age){
    name = _name;
    age = _age;
}
human::human(char *_name){
    cout << "human(char name) overloading" << endl;
}
human::human(){
    cout << "human() overloading" << endl;
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

void boolNum(){
    cout << true << endl;
    cout << false << endl;
}

void boolLen(){
    cout << "sizeof true: " << sizeof true << endl;
    cout << "sizeof false: " << sizeof false << endl;
}

void boolExample(){
    int a, b;
    bool isMax;
    
    cin >> a >> b;
    
    if(a>b) isMax = true;
    else isMax = false;
    
    cout << "isMax : " << isMax << endl;
}

void inlineExample(){
    cout << PI << endl;
    cout << CU(7.4) << endl;
}

void referenceExample(){
    int aaa=50;
    int &bbb=aaa;
    
    cout << "aaa : " << aaa << endl;
    cout << "bbb : " << bbb << endl;
    
    cout << "aaa path : " << &aaa << endl;
    cout << "bbb path : " << &bbb << endl;
}

void swap(int &ref_a, int &ref_b){
    int temp = ref_a;
    
    ref_a = ref_b;
    ref_b = temp;
}
void callByReferenceExample(){
    
    int a = 50, b = 40;
    cout << "swap 하기전 a : " << a << " b : " << b << endl;
    
    swap(a, b);
    cout << "swap 한 후 a : " << a << " b : " << b << endl;
}

void objectArrayExample(){
    Item item[2];
    
    int id, price;
    char name[10];
    
    for(int i=0; i<2; i++){
        cout << "id : ";
        cin >> id;
        cout << "name : ";
        cin >> name;
        cout << "price : ";
        cin >> price;
        
        item[i].setInfo(id, name, price);
    }
    for(int i=0; i<2; i++){
        item[i].getInfo();
    }
}

void objectArrayExample_memberInitializer(){
    ItemEX itemEx[2] = {ItemEX(1, "apple", 500),ItemEX(1, "box", 1000)};
    for(int i=0; i<2; i++){
        itemEx[i].getInfo();
    }
}

void objectPointerArray(){
    ItemEX * itemEx[2];
    
    int id, price;
    char name[10];

    for(int i=0; i<2; i++){
        cin >> id >> name >> price;
        itemEx[i] = new ItemEX(id, name, price);
    }
    for(int i=0; i<2; i++){
        itemEx[i]->getInfo();
	}
    delete itemEx[0];
    delete itemEx[1];
}

int main() {
    
    overriding_B ob;
    ob.over();
    /*  ob라는 객체를 만들고 over()함수를 호출하면
        부모 클래스의 over()함수는 무시되고 자식 클래스의 over()함수가 호출됨
    */
    
    ThisPointExample tp(10, 20);
    tp.getInfo();
    
    objectPointerArray();
    
    objectArrayExample();
    objectArrayExample_memberInitializer();
    
    memInit mi(50, 70);
    mi.show();
    
    Student stu(12, "u4bi", "coding", "c++ school");
    stu.schoolInfo();
    stu.getup();
    stu.eat();
    stu.study();
    stu.sleep();
    
    Friend_A friend_a(10);
    Friend_B friend_b(20);
    friend_a.show(friend_b);
    friend_b.show(friend_a);

    callByReferenceExample();
    referenceExample();
    inlineExample();
    
    boolNum();
    boolLen();
    boolExample();

    deep dp1("deep copy");
    deep dp2 = dp1;
    dp1.show();
    dp2.show();
    
    /* deep copy test comment line
    shallow sw1("shallow copy");
    shallow sw2 = sw1;
    sw1.show();
    sw2.show();
    */
    
    dog d;

    copied cp1(30, 31);
    copied cp2 = cp1;
    cp2.show();
    
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