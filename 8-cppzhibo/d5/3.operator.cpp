/*************************************************************************
	> File Name: 3.operator.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Apr 2022 03:12:53 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Point{
    int x, y;
public:
    Point();
    Point(int x, int y);

    friend Point operator+(const Point &a, const Point &b);
    friend ostream &operator<<(ostream &out, const Point &a);

    Point operator+(const Point &b)
    {
        cout<<"inner add"<<endl;
        return Point(this->x + b.x, this->y + b.y);
    }

    Point operator+=(int x)
    {
        this->x += x;
        this->y += x;
        return *this;
    }

    int &operator[](string str)
    {
        if(str == "x")
            return this->x;
        if(str == "y")
            return this->y;
    }

    void operator()(string str)
    {
        cout<<str<<":"<<x<<","<<y<<endl;
    }
    void operator()(int a)
    {
        cout<<a<<":"<<x<<","<<y<<endl;
    }

    void func()
    {
        cout<<"a func"<<endl;
    }
    int cnt;
};

//Point::Point():x(0),y(0){}
Point::Point():Point(0,0){} // 委托构造
Point::Point(int m, int n):x(m),y(n){}

Point operator+(const Point &a, const Point &b) //a+b作为右值，返回一个对象（不能返回引用）
{
    cout<<"outer add"<<endl;
    return Point(a.x + b.x, a.y + b.y);
}

ostream &operator<<(ostream &out, const Point &a)
{
    out<<"("<<a.x<<","<<a.y<<")";
    return out;
}

class PPoint{
    Point *p;
public:
    PPoint(Point *addr):p(addr){}

    Point *operator->()
    {
        return p;
    }
};

int main()
{
    Point a(3,4);
    /*
    Point b(2,2);
    Point c;

    c = a + b;
    ((c += 2) += 3) += 4;
    //operator+(a, b);
    //a.operator+(b);

    cout<<c<<endl;
    */

    a["x"] = 0;
    cout<<a["x"]<<endl;

    a("point");
    a(0);


    PPoint p = &a;
    p->             func();
    p.operator->()->func();
    (&a)->func(); 
    p->cnt;

    return 0;
}
