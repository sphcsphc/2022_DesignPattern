#include <stdio.h>

int main()
{
    int n = 0;

    ++ ++ ++n; // C에서는 값이 반환합니다.
               // 값을 다시 증가할 수 없습니다.
               // C++에서는 참조가 반환합니다.
               // 참조는 다시 증가할 수 있습니다.
    printf("%d\n", n);
    n++;
    printf("%d", n);
}