/*************************************************************************
	> File Name: 2.operator.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Apr 2022 02:55:30 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
public:
    void output(){
        cout<<"hello"<<endl;
    }
};

int main()
{
    A a;
    A *k = &a;

    void (A::*p)() = &A::output;
    (k->*p)();
    (a.*p)();

    return 0;
}
