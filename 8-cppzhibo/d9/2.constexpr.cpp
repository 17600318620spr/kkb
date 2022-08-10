/*************************************************************************
	> File Name: 2.constexpr.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 09 May 2022 09:43:13 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

constexpr int mul2(int x)
{
    return 2*x;
}

class A{
public:
    constexpr A(){}
    //A(){}
};

int main()
{
    constexpr A a;
    constexpr int k = mul2(3);

    int n;
    cin>>n;
    const int x = 123 + n; //运行时确定
    //constexpr int y = 456 + n; //编译时确定

    int *p = const_cast<int *>(&x);
    *p = 0;
    cout<<&x<<endl;
    cout<<p<<endl;
    cout<<x<<endl; //编译器，汇编层把 x 替换成了123
    cout<<*p<<endl;

    return 0;
}
