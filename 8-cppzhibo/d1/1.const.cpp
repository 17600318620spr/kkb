/*************************************************************************
	> File Name: 1.const.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 11:26:22 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
public:
    int x;
    int y;
    //mutable int y;

    A():x(123), y(x+1){}
    
    void say1() const{
        cout << y << endl;
    }
    void say2(){

    }
};

int main(void)
{
    const A a;
    a.say1();
    a.say1();
    //a.say2(); // void say2() const{}

    return 0;
}
