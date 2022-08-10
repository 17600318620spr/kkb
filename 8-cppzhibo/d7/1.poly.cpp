/*************************************************************************
	> File Name: 1.poly.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 May 2022 03:08:13 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
//using namespace std;
using std::cout;
using std::endl;

class Animal{ //抽象类
public:
#if 0
    virtual void run()
    {
        cout<<"I don't know how to run"<<endl;
    }
#else
    //纯虚函数
    virtual void run()=0;
#endif
    void say(){
        cout<<"Animal say"<<endl;
    }
};

class Cat:public Animal{
public:
    void run()override{
        cout<<"I run with 4 legs"<<endl;
    }
    void say(){
        cout<<"Cat say"<<endl;
    }
};

int main1()
{
//    Animal a;
//    a.run();

    Cat c;
    //c.run();

    Animal *p = &c;
    p->run();
    p->say();
    Animal &r = c;
    r.run();
    r.say();

    return 0;
}

class Feeder:public Animal{
public:
    void run(){
        cout<<"run with 2 legs"<<endl;
    }
};

class Panda:public Animal{
public:
    void run(){
        cout<<"gun gun"<<endl;
    }
};

class Taisui:public Animal{
public:
    void run(){
        cout<<"don't run"<<endl;
    }
};

#if 1
int main()
{
    int const n = 10;
    srand(time(0));
    
    Animal **zoo = new Animal*[n];
    for(int i = 0; i < n; ++i)
    {
        switch(rand()%4)
        {
            case 0:
                zoo[i] = new Cat;
                break;
            case 1:
                zoo[i] = new Feeder;
                break;
            case 2:
                zoo[i] = new Panda;
                break;
            case 3:
                zoo[i] = new Taisui;
                break;
            //default:
                //cout<<"none"<<endl;
        }
    }

    for(int i = 0; i < n; i++)
    {
        zoo[i]->run();
    }
    
    return 0;
}
#else
int main()
{
    int const n = 10;
    srand(time(0));
    cout<<rand()%2<<endl;
    
    return 0;
}
#endif

