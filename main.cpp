#include <iostream> 

/*  using이란건 네임스페이스를 쉽게 사용할 수 있도록 도와주는 역할을 함.
    using에는 지시자와 선언자가 있음.
    
    예로 우리가 네임스페이스를 사용하며 네임스페이스 내에 있는 함수를 빈번하게
    호출할 경우 네임스페이스명과 범위 지정 연산자를 추가로 적어야하므로 여간 귀찮은게 아님.
    
    그냥 함수 이름만 써놓고 이 함수를 호출할때는 어느 네임스페이스 내에 있는 함수를 호출하겠다.
    라고 해두면 얼마나 좋을까 라는거임.
    
    이런 문제를 바로 using이 해결함.
*/

namespace u4bi{
    void good(){
        printf("u4bi c++ \n");
    }
}

namespace github{
    void win(){
        printf("github win\n");
    }
    
    void lose(){
        printf("github lose\n");
    }
}

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

using namespace u4bi;
/*  using 지시자를 사용
    이건 u4bi라는 네임스페이스를 명시적으로 사용하겠다는 말임.
    
    이렇게 되면 더이상 귀찮게 네임스페이스명을 붙일 필요가 없어짐.
    즉 네임스페이스 전체를 가져온 셈임.
*/
using github::win;
/*  using 선언자를 사용
    github 네임스페이스에 있는 win 함수만 사용하도록 명시함.
    
    참고로 네임스페이스에 있는 함수와 이미 영역에 존재하는
    함수의 이름이 겹치면 충돌한다함.
*/
int main() {
    
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