#include <iostream>
// 1. 전체 이름을 사용하는 방법.

// int main()
// {
//   std::cout << "Hello, cpp" << std::endl
//             << "Hello, cpp" << std::endl;
// }

// 2. using 선언(declaration)을 사용하는 방법.

// using std::cout;
// using std::endl;

// int main()
// {
//   cout << "Hello, cpp" << endl
//        << "Hello, cpp" << endl;
// }

// 3. using 지시어(directive)

#include <algorithm>

using namespace std;

int main()
{
  std::cout << "Hello, cpp" << std::endl
            << "Hello, cpp" << std::endl;
}