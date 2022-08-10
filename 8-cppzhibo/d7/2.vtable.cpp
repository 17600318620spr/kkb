/*************************************************************************
	> File Name: 2.vtable.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 May 2022 09:41:20 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
public:
    int x;
    virtual void run(int x){
        this->x = x;
        cout<<"A run x="<<this->x<<endl;
    }
    virtual void eat(){
        cout<<"A eat"<<endl;
    }
    virtual void sleep(){
        cout<<"A sleep"<<endl;
    }
};

class B:public A{
public:
    void run(int x)override{
        this->x = x;
        cout<<"B run x="<<this->x<<endl;
    }
    void eat()override{
        cout<<"B eat"<<endl;
    }

};

//typedef void (*)() funcp;
typedef void (*funcp)();

int main()
{
    //cout<<sizeof(A)<<endl;
    A a;
    B b, c;
#if 0
    //cout<<*(long *)&b<<endl;
    cout<<*(void**)&b<<endl;
    cout<<*(void**)&c<<endl;

    (*(funcp **)&b)[0]();
    (*(funcp **)&b)[1]();
    (*(funcp **)&b)[2]();

    (*(void (***)())&b)[0]();
    (*(void (***)())&b)[1]();
    (*(void (***)())&b)[2]();
#endif
#if 0
    A *p;
    p = &a;
    p->run();
    p = &b;
    p->run();

    *(void **)&b = *(void **)&a;
    cout<<"======== b vptr <- a vptr ======="<<endl;

    p = &a;
    p->run();
    p = &b;
    p->run();
#endif
#if 0
    (*(void (***)(B *,int))&b)[0](&b,100);
    cout<<b.x<<endl;
#endif
#if 1
    a.x = 0;
    b.x = 0;
    (*(void (***)(void *,int))&b)[0](&a,100);
    cout<<"a.x="<<a.x<<endl;
    cout<<"b.x="<<b.x<<endl;
#endif
    return 0;
}

