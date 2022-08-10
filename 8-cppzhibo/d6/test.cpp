/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Apr 2022 01:09:58 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
public:
    //const A &operator=(A &a)const
    const A &operator=(const A &a)const
    {
        return *this;
    } //返回 & 可以继续对左值进行操作
};

int main()
{
    const A a;
    const A b;
    A c;

    a = b;
    a = c;

    return 0;
}
