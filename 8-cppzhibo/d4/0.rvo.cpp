/*************************************************************************
	> File Name: 0.rvo.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Apr 2022 11:04:15 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
    int x;
public:
    //int x;
    A(){
        cout<<this<<" default constructor"<<endl;
    }
    A(int x):x(x){
        cout<<this<<" param constructor"<<endl;
    }
    //A(const A &a):x(a.x+2){ //error!!
    A(const A &a):x(a.x){
        cout<<this<<" copy constructor"<<endl;
    }
    ~A(){
        cout<<this<<" destructor"<<endl;
    }
};

A func()
{
    A tmp(100);
    cout<<"tmp:"<<&tmp<<endl;
    return tmp;
}

int main()
{
    //A a(10);
    //A b(a);
    A a = func();
    cout<<"  a:"<<&a<<endl;
    //A a(b); A a = b;

    return 0;
}
