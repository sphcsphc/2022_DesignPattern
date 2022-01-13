#include <iostream>
using namespace std;

// 함수 객체 버전
struct Less {
    inline bool operator()(int a, int b) const { return a > b; }
};

struct Greater {
    inline bool operator()(int a, int b) const { return a < b; }
};

// 함수 버전
bool cmp1(int a, int b) { return a > b; } // 오름차순
bool cmp2(int a, int b) { return a < b; } // 내림차순

// void Sort(int* x, int n, bool (*cmp)(int a, int b))
// void Sort(int* x, int n, Less cmp)
// void Sort(int* x, int n, Greater cmp)

// 정책을 함수 포인터로 전달가능하고,
// 자신만의 타입을 가지는 함수 객체도 사용할 수 있습니다.
// => 정책을 템플릿 인자로 전달하는 이유입니다.
template <typename T>
void Sort(int* x, int n, T cmp)
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // if (x[i] < x[j])
            if (cmp(x[i], x[j]))
                swap(x[i], x[j]);
        }
    }
}

int main()
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    Less less;
    Greater greater;
    // 1) 함수 객체로 전달
    // 장점: 정책이 호출되는 것이 아니라 인라인 치환됩니다. 빠르다.
    // 단점: 코드를 생성합니다.
    
    Sort(x, 10, less); // => Sort(int*, int, Less)
    Sort(x, 10, greater); // => Sort(int*, int, Greater)

    // 2) 함수 포인터 전달
    // 장점: 한 개의 생성된 함수를 공유해서 사용 가능합니다.
    //      코드 메모리 사용량 증가하지 않습니다.
    // 단점: 호출 오버헤드가 있습니다.
    //      인라인 치환이 불가능합니다.

    Sort(x, 10, &cmp1); // => Sort(int*, int, bool(*)(int, int))
    Sort(x, 10, &cmp2); // => Sort(int*, int, bool(*)(int, int))

    for (int e : x) {
        cout << e << endl;
    }
}
