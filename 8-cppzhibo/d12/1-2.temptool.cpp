/*************************************************************************
	> File Name: 1.temptool.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 May 2022 09:32:48 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

#define BEGIN(x) namespace x{
#define END(x) }

BEGIN(rmvr)
template <typename T>
struct remove_reference{
    typedef T type;
};
template <typename T>
struct remove_reference<T &>{
    typedef T type;
};
template <typename T>
struct remove_reference<T &&>{
    typedef T type;
};

template <typename T>
void func(T &&a)
{
    typename remove_reference<T>::type b;
    b = a;
    cout<<b<<endl;
}

int main()
{
    int n = 3;
    func(n);
    func(234);

    cout<<"=======remove_reference========="<<endl;
    typename remove_reference<int>::type a;
    typename remove_reference<int &>::type b;
    typename remove_reference<int &&>::type c;

    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;
    cout<<typeid(c).name()<<endl;

    return 0;
}
END(rmvr)

//2.add_lvalue_reference 转换成左值引用
BEGIN(adlvr)
template <typename T>
struct add_lvalue_reference{
    typedef T& type;
};
template <typename T>
struct add_lvalue_reference<T &>{
    typedef T& type;
};
template <typename T>
struct add_lvalue_reference<T &&>{
    typedef T& type;
};

int main()
{
    cout<<"=======add_lvalue_reference========="<<endl;
    //int n;
    int n = 3;
    typename add_lvalue_reference<int>::type a = n;
    typename add_lvalue_reference<int &>::type b = n;
    typename add_lvalue_reference<int &&>::type c = n;

    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;
    cout<<typeid(c).name()<<endl;

    return 0;
}
END(adlvr)

//3.remove_pointer 去掉指针
BEGIN(rmvp)
template <typename T>
struct remove_pointer{
    typedef T type;
};
template <typename T>
struct remove_pointer<T *>{
    typedef typename remove_pointer<T>::type type;
};

int main()
{
    cout<<"=======remove_pointer========="<<endl;
    typename remove_pointer<int>::type a;
    typename remove_pointer<int *>::type b;
    typename remove_pointer<int **>::type c;

    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;
    cout<<typeid(c).name()<<endl;

    return 0;
}
END(rmvp)

//4.add_const 增加const限定符
BEGIN(addconst)
template <typename T>
struct add_const{
    typedef const T type;
};
template <typename T>
struct add_const<const T>{
    typedef const T type;
};

int main()
{
    cout<<"=======add_const========="<<endl;
    typename add_const<int>::type a = 1;
    typename add_const<const int>::type b = 2;

    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;

    return 0;
}
END(addconst)

BEGIN(bindtest)
int add(int x, int y)
{
    return x + y;
}
void add1(int &x)
{
    x++;
}
void show(int n, const char *msg)
{
    cout<<n<<":"<<msg<<endl;
}

int main()
{
    int m = 3, n = 4;
    auto t1 = bind(add, m, n);
    cout<<t1()<<endl;
    cout<<t1()<<endl;
    cout<<t1()<<endl;

    auto t2 = bind(add1, ref(m));
    t2();
    t2();
    t2();
    cout<<m<<endl;

    auto t3 = bind(show, placeholders::_2, placeholders::_1);
    t3("hello", 4);
    //printf("%s\n", "printf", 1,2,3,4);
    auto t4 = bind(show, placeholders::_4, placeholders::_1);
    t4("world", 3.4, "he", 4);

    return 0;
}
END(bindtest)

BEGIN(functest)
int add(int x, int y)
{
    return x + y;
}

class ADD{
public:
    int operator()(int x, int y)
    {
        return x + y;
    }
};

template <typename T, typename ...ARGS>
class Base{
public:
    virtual T run(ARGS...) = 0;
    virtual Base *getCopy() = 0;
};

template <typename T, typename ...ARGS>
class NormalFunc:public Base<T, ARGS...>{
private:
    T (*ptr)(ARGS...);
public:
    NormalFunc(T (*p)(ARGS...)):ptr(p){}

    T run(ARGS ...args)override{
        return ptr(forward<ARGS>(args)...);
    }

    Base<T, ARGS...> *getCopy(){
        return new NormalFunc(*this);
    }
};

template <typename CLASS_T, typename T, typename ...ARGS>
class functor:public Base<T, ARGS...>{
private:
    CLASS_T obj;
public:
    functor(CLASS_T &obj):obj(obj){}

    T run(ARGS ...args)override{
        return obj(forward<ARGS>(args)...);
    }

    Base<T, ARGS...> *getCopy(){
        return new functor(*this);
    }
};

template <typename T, typename ...ARGS> class function;
template <typename T, typename ...ARGS>
class function<T(ARGS...)>{
private:
    Base<T, ARGS...> *ptr;
public:
    function(T (*p)(ARGS...)):ptr(new NormalFunc<T, ARGS...>(p)){}

    template <typename CLASS_T>
    function(CLASS_T obj):ptr(new functor<CLASS_T, T, ARGS...>(obj)){}

    T operator()(ARGS ...args){
        return ptr->run(forward<ARGS>(args)...);
    }

    function &operator=(const function &f)
    {
        delete ptr;
        ptr = f.ptr->getCopy();
        return *this;
    }

    virtual ~function(){
        delete ptr;
    }
};

int main()
{
    function<int(int, int)> p = add;
    cout<<p(1 ,2)<<endl;
#if 1
    ADD a;
    function<int(int, int)> p2 = a;
    cout<<p2(3, 4)<<endl;
#endif
    p = p2;
    cout<<p(5, 6)<<endl;

    function<int(int, int)> p3 = [](int a, int b)
    {
        return a + b;
    };
    cout<<p3(3,4)<<endl;

    return 0;
}
END(functest)

int main()
{
#if 0
    rmvr::main();
    adlvr::main();
    rmvp::main();
    addconst::main();
#endif
    cout<<"=================="<<endl;

    bindtest::main();
    functest::main();

    return 0;
}
