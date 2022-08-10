/*************************************************************************
	> File Name: 4.leftright.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 May 2022 02:52:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define func(x) __func(x, "func(" #x ")")
#define func2(x) __func2(x, "func2(" #x ")")
void __func2(int &x, string str)
{
    cout<<str<<" is left value"<<endl;
    return ;
}
void __func2(int &&x, string str)
{
    cout<<str<<" is right value"<<endl;
    return ;
}
void __func(int &x, string str)
{
    cout<<str<<" is left value"<<endl;
    func2(x);
    //func2(move(x));
    cout<<"============"<<endl;
    return ;
}
void __func(int &&x, string str)
{
    cout<<str<<" is right value"<<endl;
    //func2(move(x));
    func2(forward<int &&>(x));
    cout<<"============"<<endl;
    return ;
}

int main1()
{
    int x = 123, y = 456;

    func(123); //r
    func(x);   //l
    func(x+y); //r
    func(x++); //r
    func(++x); //l

    func(x+3);  //r
    func(x*=33);//l
    func(y+=3); //l
    func(y*3);  //r

    return 0;
}

int main2()
{
    int &&r = 123;
    r = 5;
    cout<<r<<endl;
    
    return 0;
}

class A{
    int x;
public:
    A(int x = 0):x(x){
        cout<<this<<":default constructor"<<endl;
    }
#if 1
    A(const A &a):x(a.x){
        cout<<this<<":copy constructor"<<endl;
    }
#endif
    A operator+(const A &a)
    {
        return A(x+a.x);
    }
    ~A(){
        cout<<this<<":destructor"<<endl;
    }
};

int main()
{
    A a(1), b(2);
    A &&c = a + b;
    //A c = a + b;
    cout<<"==========================="<<endl;
    
    return 0;
}
