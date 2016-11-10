#include <iostream> 
/* c++ 기본 입출력 함수인 cin, cout
    cout : printf와 흡사
    
    cout 사용 위해 앞에 std:: 붙어야함.
    << >> : 시프트 연산자라 불림.
    << : 왼쪽으로 전달 >> : 오른쪽으로 전달
    
    std::endl : c언어에서 ₩n 개행과 동일 줄바꿔줌
    
*/
int main() {
    char name[10];
    int age;
    
    // cin
    std::cin>>name>>age;
    /*  키보드로 전달받은 값을 >>으로 전달
        데이터 입력 기준 스페이스바, 탭 엔터키같은 공백에 의해 나뉨. */
    
    // cout
    std::cout << "내 닉네임은 " << name << "이며 " << age << "살입니다." <<std::endl;
    std::cout << "u4bi c++ workspace" <<std::endl;
    return 0;
}