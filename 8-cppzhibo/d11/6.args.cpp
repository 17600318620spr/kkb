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

template <int N, typename T, typename ...ARGS>
struct C_ARGS{
    typedef typename C_ARGS<N-1, ARGS...>::type type;
};

template <typename T>
struct C_ARGS<1, T>{
    typedef T type;
};
template <typename T, typename ...ARGS>
struct C_ARGS<1, T, ARGS...>{
    typedef T type;
};

//1.获得参数个数
template <typename T, typename ...ARGS>
struct NUM_ARGS{
    static constexpr int n = NUM_ARGS<ARGS...>::n+1;
};
template <typename T>
struct NUM_ARGS<T>{
    static constexpr int n = 1;
};
//2.判断是否为0
template <int N>
struct Zero{
    typedef int no;
};
template <>
struct Zero<0>{
    typedef int yes;
};

template <class T, class ...ARGS> class Test;
template <class T, class ...ARGS>
class Test<T(ARGS...)>{
public:
    //判断剩下的参数就是2个，多了会报错
    typedef typename Zero<NUM_ARGS<ARGS...>::n-2>::yes XYZ;
    T operator()(typename C_ARGS<1, ARGS...>::type a, typename C_ARGS<2, ARGS...>::type b)
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

    cout<<"====================="<<endl;
    cout<<NUM_ARGS<int, float, double>::n<<endl;;

    return 0;
}
