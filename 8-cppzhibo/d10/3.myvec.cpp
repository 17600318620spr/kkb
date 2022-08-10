/*************************************************************************
	> File Name: 3.myvec.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 May 2022 11:21:59 AM CST

:%s/__size/__capacity/g  g表示所有的
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define KKBB namespace kkb{
#define KKBE }

class A{
    int x;
public:
    A() = delete;
    A(int x):x(x){}
};

KKBB
template <typename T>
class vector{
    int __size;
    T *data;
public:
    //vector(int n = 10):__size(n), data(new T[__size]){}
    vector(int n = 10):__size(n), data(nullptr)
    {
        data = (T *)malloc(sizeof(T) * __size);
    }
    virtual ~vector()
    {
        if(data)
            //delete[] data;
            free(data);
        __size = 0;
    }

    vector(const vector<T> &v):__size(v.__size) //拷贝构造
    {
        data = (T *)malloc(sizeof(T) * __size);
        for(int i = 0; i < __size; i++)
        {
            //data[i] = v.data[i]; //任何的值(data[i])在使用之前应该初始化
            new (data+i) T(v.data[i]); //原地构造
        }
    }

    vector(vector<T> &&v):__size(v.__size), data(v.data) //移动构造
    {
        v.__size = 0;
        v.data = nullptr;
    }
    
    T &operator[](int idx)const
    {
        return data[idx];
    }

    int size()
    {
        return __size;
    }
};
KKBE


int main()
{
    vector<A> v;
    kkb::vector<A> v2;

    cout<<v.size()<<endl;
    cout<<v2.size()<<endl;

    return 0;
}
