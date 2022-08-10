/*************************************************************************
	> File Name: 3.memberPointer.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 May 2022 09:52:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
public:
    int x, y;
    A():x(100),y(200){}
    void vxlogin(){
        cout<<"weixin login"<<endl;
    }
    void zfblogin(){
        cout<<"zhifubao login"<<endl;
    }
    void uplogin(){
        cout<<"user-passwd login"<<endl;
    }
};

int main()
{
    A a;
#if 0
    void (*p)() = &A::vxlogin;      //普通指针 error!!
    void (A::*p)() = &A::vxlogin;   //类中方法的指针
    (a.*p)();
#endif
    void (A::*p[3])();
    p[0] = &A::vxlogin;
    p[1] = &A::zfblogin;
    p[2] = &A::uplogin;

    srand(time(0));
    for(int i = 0; i < 10; i++)
    {
        (a.*p[rand()%3])();
    }

    //类中属性的指针
    int A::*k = &A::x;
    cout<<a.*k<<endl;
    k = &A::y;
    cout<<a.*k<<endl;

    return 0;
}
