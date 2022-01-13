#include <iostream>
using namespace std;

// 컨테이너 설계 기술. 3. Thin Template
// 1. void* 기반으로 만듭니다.

struct Node {
    void* data;
    Node* next;

    Node(void* a, Node* n)
        : data(a)
        , next(n)
    {
    }
};

class SlistImpl {
    Node* head;

public:
    SlistImpl()
        : head(nullptr)
    {
    }

    void push_front(void* a) { head = new Node(a, head); }

    void* front() { return head->data; }
};

// SListImpl을 직접 사용할 경우, 캐스팅에 대한 코드가 불편합니다.
// 사용자가 편리하게 사용할 수 있도록 Template으로 자식 클래스를 제공합니다.
// => Thin Template
// => inline을 사용할 경우, 치환되는 함수에 대해서 코드 메모리에 존재하지 않습니다.
// => SListImpl의 구현을 물려 받지만, 인터페이스는 물려 받지 않아야 합니다.
// => private 상속

template <typename T>
class Slist : private SlistImpl {
public:
    inline void push_front(const T& a)
    {
        // &a => const T* => const_cast => T* => void*
        SlistImpl::push_front(const_cast<T*>(&a));
    }

    inline T& front()
    {
        // void* => static_cast => T* => * => T&
        return *(static_cast<T*>(SlistImpl::front()));
    }
};

int main()
{
    Slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    int n = s.front();
    cout << n << endl;
}
