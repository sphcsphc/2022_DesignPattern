#include <iostream>
using namespace std;

class Integer {
private:
    int value;

public:
    Integer(int n = 0)
        : value(n)
    {
    }

    // 멤버 함수로 연산자 재정의 함수를 제공합니다.
    //  ++n
    Integer& operator++()
    {
        ++value;
        return *this;
    }

    //  n++
    // 차이점) 반환타입이 값 타입입니다.
    Integer operator++(int)
    {
        Integer temp = *this; // 값이 변경되기 전의 상태를 보관합니다.
        ++value;

        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Integer& i);
};

std::ostream& operator<<(std::ostream& os, const Integer& i)
{
    return os << i.value;
}

int main()
{
    int n1 = 0;
    cout << n1 << endl;

    ++n1;
    n1++;

    Integer n2;
    cout << ++n2 << endl;
    // => cout.operator<<(n2)
    // => operator<<(cout, n2)
    
    Integer n3;
    cout << n3++ << endl;
    cout << n3 << endl;
}