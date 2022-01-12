#include <iostream>
using namespace std;

#include <list>

// 그런데 클라이언트가 stack을 요구합니다.
// 1. stack을 다시 만듭니다.
// 2. list를 한쪽으로만 사용하면 stack 입니다.
//    list를 재사용합니다.

// SW 재사용
// 1) 상속

// stack은 list의 모든 기능을 상속합니다.
#if 0
class stack : public list<int> {
public:
    void push(int n)
    {
        push_back(n);
    }

    void pop()
    {
        pop_back();
    }

    int& top()
    {
        return back();
    }
};
#endif

// Adapter Pattern
// : 기존 클래스(list)의 인터페이스(함수 이름)을 변경해서
//   사용자가 요구하는 새로운 클래스처럼 보이게 하는 패턴

// 상속
// : 부모가 제공하는 데이터와 인터페이스를 물려받습니다.

// class stack : public list<T> {

// private 상속: 부모로부터 구현은 물려받지만(자식이 내부적으로 사용하지만)
//              인터페이스는 물려받지 않겠다.(부모 함수를 외부로 노출하지 않겠다.)

#if 0
template <typename T>
class stack : private list<T> {
public:
    inline void push(const T& n)
    {
        list<T>::push_back(n);
    }

    inline void pop()
    {
        list<T>::pop_back();
    }

    inline T& top()
    {
        return list<T>::back();
    }
};
#endif

// 상속의 문제점
// 1. 부모 클래스와 자식 클래스의 강한 결합이 형성됩니다.
//  > 부모 클래스에 대한 변경이 자식 클래스로 전파됩니다.
//   - 유지보수에 어려움이 있습니다.
//
// 2. 부모 클래스를 자식 클래스에서 public 상속할 경우
//    불필요한 인터페이스가 외부에 노출되는 문제가 있습니다.
//   => C++ : private 상속
//
// 3. 상속을 기존 클래스의 재사용 목적으로 사용하는 것은 권장하지 않습니다.
//   => 포함을 이용하는 것이 좋을 때가 많습니다.

//                                 std::deque<int>
#if 0
template <typename T, typename C = std::list<int>>
class stack {
    // std::list<T> st;
    C st;

public:
    inline void push(const T& n)
    {
        st.push_back(n);
    }

    inline void pop()
    {
        st.pop_back();
    }

    inline T& top()
    {
        return st.back();
    }
};
#endif

#include <stack>
#include <vector>

int main()
{
    stack<int, vector<int>> s;
    s.push(10);
    s.push(20);
    s.push(30);

    // s.push_front(10);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}