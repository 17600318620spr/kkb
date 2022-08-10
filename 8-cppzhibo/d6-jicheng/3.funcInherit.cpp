/*************************************************************************
	> File Name: 3.funcInherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 03 May 2022 11:11:39 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
public:
    A() = default;
    A(const A&) = delete;
    A &operator=(const A &) = delete;
};

class B{
public:
    B() = default;
    B(const B &) = delete;
    B &operator=(const B &) = delete;
};

class C:public A{

};

int main()
{
    C a;
    //A b(a);
    //A c = a;

    return 0;
}
