/*************************************************************************
	> File Name: 4.args.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 May 2022 03:33:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template <class T>
void print(T a)
{
    cout<<a<<endl;
}

template <class T, class ...ARGS>
void print(T a, ARGS... args)
{
    cout<<a<<endl;
    print(args...);
}

//模板类
template <class T, class ...ARGS>
class N_ARGS{
public:
    typedef T type;
    typedef N_ARGS<ARGS...> rest;
};

template <class T>
class N_ARGS<T>{
public:
    //typedef T type;
    typedef T last;
};

template <class T, class ...ARGS> class Test;
template <class T, class ...ARGS>
class Test<T(ARGS...)>{
public:
    //T operator()(class N_ARGS<ARGS...>::type a, class N_ARGS<ARGS...>::rest::type b)
    //T operator()(typename N_ARGS<ARGS...>::type a, typename N_ARGS<ARGS...>::rest::type b)
    T operator()(typename N_ARGS<ARGS...>::type a, typename N_ARGS<ARGS...>::rest::last b)
    {
        return a + b;
    }
};

int main()
{
    print(123);
    print(12.3, "aaa");
    print("asdfasdf", 3, 333.222);

    N_ARGS<int, double, string>::type a;
    N_ARGS<int, double, string>::rest::type b;
    //N_ARGS<int, double, string>::rest::rest::type c;
    N_ARGS<int, double, string>::rest::rest::last c;

    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;
    cout<<typeid(c).name()<<endl;

    cout<<"====================="<<endl;
    Test<int(int, int)> t1;
    Test<double(double, int)> t2;
    //Test<double, double, int, float> t3;

    cout<<t1(1.1, 2.2)<<endl;
    cout<<t2(1.1, 2.2)<<endl;

    return 0;
}
