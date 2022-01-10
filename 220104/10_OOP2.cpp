#include <iostream>
using namespace std;

// 1. 전역 변수 / 함수를 이용한 스택
/*
int buff[10];
int idx = 0;

void push(int v)
{
    buff[idx++] = v;
}

int pop()
{
    return buff[--idx];
}

int main()
{
    push(10);
    push(20);

    cout << pop() << endl;
    cout << pop() << endl;
}
*/

// 2. Stack 타입을 설계해봅시다.
/*
struct Stack
{
    int buff[10];
    int idx;
};

void push(Stack *s, int v)
{
    s->buff[(s->idx)++] = v;
}

int pop(Stack *s)
{
    return s->buff[--(s->idx)];
}

Stack s1;

int main()
{
    Stack s2;

    s1.idx = 0;
    s2.idx = 0;
    
    push(&s1, 10);
    push(&s2, 20);

    cout << pop(&s1) << endl;
    cout << pop(&s2) << endl;
}
*/

// 3. 상태를 나타내는 데이터와 상태를 조작하는 함수를 묶자.
// 4. 구조체 내부의 데이터를 외부에서 함부로 조작할 수 없도록 정보 은닉이 필요합니다.
//     => 접근 지정자
//    - 구조체는 접근 지정자를 사용하지 않을 경우,
//      기본적으로 public이 됩니다.
//     => class
//      기본 접근 지정이 private 입니다.
// 5. 생성자 함수를 도입합니다.
//   생성자(Constructor)
//   - 함수 이름이 클래스 이름과 동일하고, 반환 타입을 표기하지 않습니다.
//   > 객체가 생성되면 자동으로 호출됩니다.
/*
class Stack
{
private:
    int buff[10];
    int idx;

public:
    Stack() 
    {
        cout << "Stack()" << endl;
        idx = 0;
    }
    // 멤버 함수
    // - 멤버 데이터에 접근하는 함수
    // > 명시적인 함수 인자로 Stack*을 받을 필요가 없습니다.

    void init()
    {
        idx = 0;
    }

    void push(int v)
    {
        buff[idx++] = v;
    }

    int pop()
    {
        return buff[--idx];
    }
};

Stack s1;

int main()
{
    Stack s2;

    s1.push(10);
    s2.push(20);

    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}
*/

// 6. 사용자가 스택의 크기를 결정할 수 있도록 합니다.
// > 생성자는 인자를 가져도 되고, 인자를 가지지 않아도 됩니다.
//   생성자는 오버로딩이 가능합니다.
// 7. 더이상 객체를 사용하지 않을 때,
//    객체가 파괴되는 시점에 호출되는 함수가 있습니다.
//   > 소멸자(Destructor)
//   - 함수 이름은 ~클래스이름() 입니다.
//   - 반환 타입을 표기하지 않습니다.
//   - 인자를 가질 수 없습니다.
//   - 객체가 파괴되는 시점에 수행됩니다.

class Stack
{
private:
    int *buff;
    int idx;

public:
    Stack(int sz = 10)
    {
        idx = 0;
        buff = new int[sz];
    }

    ~Stack()
    {
        cout << "소멸자 수행" << endl;
        delete[] buff;
    }

    void push(int v)
    {
        buff[idx++] = v;
    }

    int pop()
    {
        return buff[--idx];
    }
};

Stack s1;

int main()
{
    Stack s2(100);
    Stack s3{100};

    s1.push(10);
    s2.push(20);

    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}