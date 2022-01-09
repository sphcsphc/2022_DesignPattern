// 1) 이름 충돌을 해결할 수 있습니다.
// 2) 프로그램의 각 요소를 관련된 요소끼리 그룹화 할 수 있습니다.
// 3) C++ 표준에서 제공하는 모든 요소들은 std의 이름공간안에 존재합니다.

#include <iostream>

namespace Audio
{
  void init() { std::cout << "Audio::init" << std::endl; }
}

namespace Video
{
  void init() { std::cout << "Video::init" << std::endl; }
}

void init()
{
  std::cout << "Global init" << std::endl;
}

int main()
{
  Audio::init();
  Video::init();

  init();
}