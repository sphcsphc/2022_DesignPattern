// 헤더 파일과 소스 파일을 분리하는 방법
// - internal linkage(내부 연결)
//  : 같은 파일에서만 접근이 가능합니다.
//  => 헤더 파일은 반드시 내부 연결에 대해서만 가지고 있어야 합니다.

//   external linkage(외부 연결)
//  : 다른 파일에서 접근이 가능합니다.
//  => 내부 연결 / 외부 연결을 가지는 부분을 모두 가질 수 있습니다.

class Stack
{
private:
    int *buff;
    int idx;

public:
    Stack(int sz = 10);
    ~Stack();

    void push(int v);
    int pop();
};