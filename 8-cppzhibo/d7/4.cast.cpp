/*************************************************************************
	> File Name: 4.cast.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 May 2022 10:33:15 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal{
public:
    virtual void run(){
    //void run(){
        cout<<"i don't know how to run"<<endl;
    }

    virtual ~Animal(){
        cout<<"Animal destructor"<<endl;
    }
    Animal(){
        cout<<"Animal constructor"<<endl;
    }
};

class Horse:public Animal{
public:
    void run()override{
    //void run(){
        cout<<"run fast"<<endl;
    }
    void say(){
        cout<<"say horse"<<endl;
    }

    ~Horse(){
        delete p;
        cout<<"Horse destructor"<<endl;
    }
    Horse(){
        p = new int;
        cout<<"Horse constructor"<<endl;
    }
    int *p;
};

class Donkey:public Animal{
public:
    void run()override{
    //void run(){
        cout<<"run slowly"<<endl;
    }

    void swim(){
        cout<<"swim happy"<<endl;
    }
};

int main()
{
#if 0
    //隐式转换
    int a = 3.5;
    //double b = a + 3.5;
    //double b = (int)3.5 + 3.5;
    double b = static_cast<int>(3.5) + 3.5;
    cout<<b<<endl;
#endif
    srand(time(0));
    Animal *p;

    switch(rand()%2)
    {
        case 0:
            p = new Horse;
            cout<<"---new Horse---"<<endl;
            break;
        case 1:
            p = new Donkey;
            cout<<"---new Donkey---"<<endl;
            break;
    }
    p->run();

#if 0
    cout<<dynamic_cast<Horse *>(p)<<endl;
    cout<<dynamic_cast<Donkey *>(p)<<endl;
#else
    Horse *h;
    Donkey *d;
    if(h = dynamic_cast<Horse *>(p))
    {
        h->say();
        cout<<"---h->say()---"<<endl;
    }
    if(d = dynamic_cast<Donkey *>(p))
    {
        d->swim();
        cout<<"---d->swim()---"<<endl;
    }
#endif

#if 1
    Horse x;
    Donkey y;
    Animal *k = &x;
    cout<<"==================="<<endl;
    k->run();
    //k->say();
    cout<<"==================="<<endl;
    cout<<dynamic_cast<Donkey *>(k)<<endl;
    *(void **)&x = *(void **)&y;
    cout<<dynamic_cast<Donkey *>(k)<<endl;
    cout<<"==================="<<endl;
#endif

    return 0;
}

int main2()
{
    Animal *p = new Horse;
    delete p;

    return 0;
}
