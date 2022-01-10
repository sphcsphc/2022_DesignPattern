// CPU
// > 레지스터(register): 명령어를 실행하는데 필요한 변수
//  IP: Instruction Pointer
//   - 현재 실행중인 명령어의 주소
//  SP: Stack Pointer
//  BP: Base Pointer

// 함수
// > 오버헤드가 있습니다.
// - 함수를 호출하면, 함수 인자를 스택을 통해 전달하고, 해당하는 함수의 주소로 이동(점프)합니다.
//   함수의 코드를 실행하고, 함수의 결과를 레지스터로 담아서 다시 복귀합니다.

// C++은 함수를 호출하지 않고, 기계어 코드로 치환하는 문법을 제공합니다.
// - 인라인 함수
//  장점: 호출이 아니라 치환이므로, 속도가 빨라집니다.
//  단점: 함수 기계어가 큰 경우, 전체적인 실행파일의 크기가 늘어납니다.
//      => 코드 블로우트 현상이 발생할 수 있습니다.

#include <iostream>
using namespace std;

inline int add(int a, int b)
{
    return a + b;
}

int main()
{
    int ret = add(10, 20);

    printf("%d\n", ret);
}