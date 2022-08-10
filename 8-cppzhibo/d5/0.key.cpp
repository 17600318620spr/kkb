/*************************************************************************
	> File Name: 0.key.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 20 Apr 2022 02:45:32 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
public:
    A()=default; //使用系统默认构造
private:
    A(const A &a)=delete;
    A &operator=(const A &a);
};

int main()
{
    A a;
    A b;
    a = b;

    return 0;
}
