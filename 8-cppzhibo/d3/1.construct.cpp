/*************************************************************************
	> File Name: 1.construct.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Apr 2022 10:52:43 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Data{
private:
    int x, y;
public:
    Data(int a, int b):x(a),y(b){
        cout<<"data param default constructor"<<endl;
    }
#if 0
    Data(){
        cout<<"data non-param default constructor"<<endl;
    }
#endif
};

class A{
public:
    Data c;
    Data d;
    int x;

    A():d(3,4),c(1,1){
        cout<<this<<":constructor"<<endl;
    }
    A(int x):x(x),d(3,4),c(1,1){ //转换构造函数 把整型x转换成A的对象
        //this->x = x; //赋值，不是初始化
        cout<<this<<":transform constructor"<<endl;
    }
    const A &operator=(const A &a)const{
        cout<<"operator = "<<endl;
        return *this;
    }
    A(A &x):d(3,4),c(1,1){
        cout<<this<<":copy constructor"<<endl;
    }
    ~A(){
        cout<<this<<":destructor"<<endl;
    }
};


int main()
{
#if 0
    const A a;
    a = 100;

    //A b(a);
#endif

#if 1
    char c = 0xff; //char c = (char)0xff;
    cout<<sizeof(0xff)<<endl; //4
    cout<<sizeof(0xffffffff)<<endl; //4

    //if(c == 0xff)
    if(c == 0xffffffff)
    {
        cout<<"same"<<endl;
    }
    else
    {
        cout<<"diff"<<endl;
    }
#endif

    return 0;
}
