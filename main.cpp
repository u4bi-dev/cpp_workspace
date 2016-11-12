#include <iostream> 
#include <cstring>
 
/*  C++에서의 friend 클래스와 클래스끼리 친구(friend)관계를 형성할 수 있음
    A와 B란 클래스가 존재한다고 하면 A와 B 클래스 둘다 private 멤버를 가지고 있음
    
    이미 알고 있듯 private 멤버는 외부에서 접근할 수 없음.
    
    A 클래스 내에서 B 클래스를 친구로 지정하면
    B 클래스는 A 클래스의 private 멤버에 직접 접근이 가능해짐
    그러나 A클래스에서는 B클래스의 private 멤버에 직접 접근이 불가능 함
    
    A 클래스도 가능하게 해주기 위해선 B클래스 내에서도 A 클래스를 대상으로 친구로 지정 해주어야 함
    
    친구로 지정할 때 friend 선언을 해주어야 하는데 선언은 friend와 함께 친구로 정할 클래스의 이름을 밝혀야 함 
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

class Friend_B;
/* B 클래스가 있다는걸 알림 */
/*  class Friend_B; 라 선언되어 있는데 B라는 클래스가 있다는걸 알리기 위함
    이 구문을 빼버린다면 컴파일러는 그런 클래스가 어딨냐며 불만을 토로함 */
class Friend_A{
private:
    int adata;
public:
    Friend_A(int _data){
        adata = _data;
    }
    void show(Friend_B b);
    friend class Friend_B;
    /*  A클래스 내의 마지막에 B클래스를 대상으로 friend 선언
        이 선언으로 인해 [B 클래스에서 A클래스로 직접 접근]이 가능함 */
};

/* 그 다음 B 클래스도 A클래스와 비슷한 구조를 띄고 있음 */
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
    /*  B 클래스 내의 마지막에서도 A 클래스를 대상으로한 friend 선언이 등장하며
        이는 [A 클래스에서 B 클래스로 직접 접근]이 가능하단 얘기 */
};

/* Friend_A show */
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

    Friend_A friend_a(10);
    /* A라는 객체를 만듬과 동시에 생성자로 10이란 값을 넘겨줌 */
    Friend_B friend_b(20);
    /* B라는 객체를 만듬과 동시에 생성자에게 20이란 값을 넘겨줌 */
    friend_a.show(friend_b);
    friend_b.show(friend_a);
    /* 값 확인 */
    
    /*  이처럼 friend 선언은 언뜻보면 아무런 이상이 없을거 같지만 이 friend 선언은
        객체지향의 핵심중 하나인 '정보은닉'을 깨버리는 행위가 됨
        이는 매우 위험함
        
        friend 선언을 많이 사용하게되면 더 큰 문제를 부를 수 있음.
        나중에 오버로딩 공부할 떄 friend 선언이 쓰이나 그 외ㅔ 특별한 경우가 아니고선
        friend의 사용을 자제해야 한다고 함
    */
    
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