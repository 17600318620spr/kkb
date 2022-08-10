/*************************************************************************
	> File Name: 3.myvec.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 May 2022 11:21:59 AM CST

:%s/__size/__capacity/g  g表示所有的
 ************************************************************************/

#include <iostream>
#include <vector>
#include "../bench/bench.h"
using namespace std;

#define KKBB namespace kkb{
#define KKBE }

class A{
    int x;
public:
    A() = delete;
    A(int x):x(x){}

    friend ostream &operator<<(ostream &out, const A &a);
};

ostream &operator<<(ostream &out, const A &a)
{
    out<<"A:"<<a.x;
    return out;
}

KKBB
template <typename T>
class vector{
    int __capacity;
    T *data;
    int __size;
public:
#if 0
    vector(int);
#else
    vector(int n = 100):__capacity(n), data(nullptr), __size(0)
    {
        data = (T *)malloc(sizeof(T) * __capacity);
    }
#endif
    virtual ~vector();
    vector(const vector<T> &v);
    vector(vector<T> &&v);
    T &operator[](int idx)const;
    int size()const;

    void push_back(const T &t)
    {
        new (data+__size) T(t);
        __size++;
        return ;
    }
    void push_back(T &&t)
    {
        new (data+__size) T(move(t));
        __size++;
        return ;
    }
};
#if 0
template <typename T>
vector<T>::vector(int n=100):__capacity(n), data(nullptr), __size(0)
{
    data = (T *)malloc(sizeof(T) * __capacity);
}
#endif

template <typename T>
vector<T>::~vector()
{
    if(data)
        //delete[] data;
        free(data);
    __capacity = 0;
    __size = 0;
}

template <typename T>
vector<T>::vector(const vector<T> &v):__capacity(v.__capacity), __size(v.__size) //拷贝构造
{
    data = (T *)malloc(sizeof(T) * __size);
    for(int i = 0; i < __size; i++)
    {
        //data[i] = v.data[i]; //任何的值(data[i])在使用之前应该初始化
        new (data+i) T(v.data[i]); //原地构造
    }
}

template <typename T>
vector<T>::vector(vector<T> &&v):__capacity(v.__capacity), data(v.data), __size(v.__size) //移动构造
{
    v.__capacity = 0;
    v.__size = 0;
    v.data = nullptr;
}

template <typename T>
T &vector<T>::operator[](int idx)const
{
    return data[idx];
}

template <typename T>
int vector<T>::size()const
{
    return __size;
}
KKBE

ostream &operator<<(ostream &out, const kkb::vector<A> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        i && cout<<",";
        cout<<v[i];
    }
    return out;
}

ostream &operator<<(ostream &out, const vector<A> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        i && cout<<",";
        cout<<v[i];
    }
    return out;
}

int main()
{
    //const vector<A> v;
    //const kkb::vector<A> v2;
    vector<A> v;
    kkb::vector<A> v2;

    cout<<v.size()<<endl;
    cout<<v2.size()<<endl;

    //cout<<v[0]<<endl; //segmentation fault
    cout<<v2[0]<<endl;

BEGINT
    for(int i = 0; i < 100; i++)
    {
        v.push_back(rand());
    }
    //cout<<v<<endl;
ENDT
BEGINT
    for(int i = 0; i < 100; i++)
    {
        v2.push_back(rand());
    }
    //cout<<v2<<endl;
ENDT
    return 0;
}
