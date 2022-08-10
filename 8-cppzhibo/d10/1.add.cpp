/*************************************************************************
	> File Name: 1.add.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 May 2022 02:00:16 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
    int x;
public:
    A() = delete;
    A(int x):x(x){}

    A operator+(const A &b)
    {
        return A(x+b.x);
    }

    friend ostream &operator<<(ostream &out, const A &a);
};

ostream &operator<<(ostream &out, const A &a)
{
    out<<"A:"<<a.x;
    return out;
}

template <typename T, typename U>
//decltype(T()+U()) add(T a, U b)
auto add(T a, U b)->decltype(a+b)
{
    return a + b;
}

int main()
{
    cout<<add(1,2)<<endl;
    cout<<add(1.1f,2.2f)<<endl;
    cout<<add(2.3,4.5)<<endl;
    cout<<add<int>(1,2.3)<<endl;
    cout<<add<float>(1,2.3)<<endl;

    decltype(1+2) a;
    cout<<typeid(a).name()<<endl;
    cout<<add(3, 3.5)<<endl;

    A aa(3), bb(4);
    cout<<add(aa,bb)<<endl;

    return 0;
}
