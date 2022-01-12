#include <iostream>
using namespace std;

// 핵심: 변하지 않는 전체 알고리즘에서 변해야 하는 정책 코드는 분리되어야 한다.
// > 일반 함수에서는 변하는 것을 함수 인자(함수 포인터)로 뽑아내면 됩니다.

inline bool cmp1(int a, int b) { return a > b; } // 오름차순
inline bool cmp2(int a, int b) { return a < b; } // 내림차순

void Sort(int* x, int n, bool (*cmp)(int a, int b))
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
    // Sort(x, 10);
    Sort(x, 10, &cmp1);
    // Sort(x, 10, &cmp2);

    for (int e : x) {
        cout << e << endl;
    }
}