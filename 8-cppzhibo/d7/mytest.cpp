/*************************************************************************
	> File Name: mytest.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 May 2022 10:00:10 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base{
    char a;
    virtual void f();
    virtual void g();
};

int main()
{
    cout<<sizeof(Base)<<endl;

    return 0;
}
