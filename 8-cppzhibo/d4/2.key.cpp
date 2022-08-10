/*************************************************************************
	> File Name: 2.key.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Apr 2022 09:10:54 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
public:
    A()=default;
    A(const A &a) = delete;
};

int main()
{
    A a;

    return 0;
}
