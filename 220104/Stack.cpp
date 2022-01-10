#include "Stack.h"

Stack::Stack(int sz /* = 10 */)
{
    idx = 0;
    buff = new int[sz];
}

Stack::~Stack()
{
    delete[] buff;
}

void Stack::push(int v)
{
    buff[idx++] = v;
}

int Stack::pop()
{
    return buff[--idx];
}
