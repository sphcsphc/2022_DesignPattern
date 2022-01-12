#include <iostream>
using namespace std;

bool cmp1(int a, int b) { return a > b; }
bool cmp2(int a, int b) { return a < b; }

#include <algorithm> // 이미 정책 변경 가능한 sort가 이 안에 있습니다.

#include <functional>
// less<>, greater<> 함수 객체가 있습니다.

int main()
{
    less<int> l;
    greater<int> g;

    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    sort(x, x + 10);
    sort(x, x + 10, &cmp1);

    sort(x, x + 10, l);
    sort(x, x + 10, g);

    for (int e : x) {
        cout << e << endl;
    }
}