#include <iostream> 
#include <cstring>
 
/*  상속은 간단히 설명하면 부모님이 돌아가시면 부모님 재산을 모두 물려받게 되는 의미가 동일
    상속도 C++에서 존재함
    
    Human 클래스는 부모 클래스라고 말할 수 있고 그 클래스를 상속한 Student 클래스는 자식 클래스라고 말할 수 있음.
    
    상속의 대상인 Human같은 클래스의 경우는
    부모 클래스, 상위 클래스, 기초 클래스(base class), 슈퍼 클래스(super class)라고 함.
    
    상속을 하는 클래스인 Student같은 클래스의 경우는
    자식 클래스, 하위 클래스, 유도 클래스(derived class), 서브 클래스(sub class)라고 함
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

class Human{
private:
    int age;
    char name[10];
    char hobby[20];
public:
    /*  :age(_age)란 코드는 Human 클래스의 생성자로 _age 인자가 넘어오면
        Human 클래스내의 멤버 변수인 age값을 _age로 초기화 시켜주는 역할임 */
    Human(int _age, char *_name, char *_hobby) : age(_age){
        strcpy(name, _name);
        strcpy(hobby, _hobby);
    }
    void getup(){
        cout << "기상!" << endl;
    }
    void sleep(){
        cout << "취침!" << endl;
    }
    void eat(){
        cout << "식사!" << endl;
    }
    void study(){
        cout << "공부!" << endl;
    }
    void showInfo(){
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
        cout << "취미 : " << hobby << endl;
    }
};
class Student : public Human {
/* Student 클래스에서 Human 클래스를 public으로 상속함*/
private:
    char school[30];
public:
    Student(int _age, char *_name, char *_hobby, char *_school) : Human(_age, _name, _hobby){
        /*  Human 클래스와 마찬가지로 멤버 이니셜라이저가 사용
        
            Student클래스에서 Human 클래스 내의 매개변수가 있는 생성자를 호출하고
            _age, _name, _hobby를 각각 넘겨 age, name, hobby의 값으로 초기화 함
        */
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

int main() {

    Student stu(12, "u4bi", "coding", "c++ school");
    /*  stu라는 객체를 만들고 그 안의 값을 생성자로 넘겨주어 초기화
        그 후 함수들을 호출
    */
    stu.schoolInfo();
    stu.getup();
    stu.eat();
    stu.study();
    stu.sleep();
    /*  Student 클래스에서 Human 클래스내의 함수까지 호출하고 있음
        당연히 물려받았으니 사용 가능함
        
        다만, private의 멤버는 상속이 불가능
    */
    
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