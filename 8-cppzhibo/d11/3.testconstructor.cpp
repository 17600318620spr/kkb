/*************************************************************************
	> File Name: 2.testconstructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 May 2022 08:54:37 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{};
class C{};

class yes_constructor{};
class no_constructor{};


template <class T>
class Type_trial{
public:
    typedef yes_constructor has_constructor;
};

template <>
class Type_trial<double>{
public:
    typedef no_constructor has_constructor;
};

template <>
class Type_trial<int>{
public:
    typedef no_constructor has_constructor;
};

template <>
class Type_trial<string>{
public:
    typedef no_constructor has_constructor;
};

template <class T>
class Type_trial<T *>{
public:
    typedef no_constructor has_constructor;
};

#define TEST(type){ \
    cout<<#type<<":"<<Type_trial<type>::has_constructor()<<endl; \
}

ostream &operator<<(ostream &out, const yes_constructor &)
{
    out<<"yes";
    return out;
}
ostream &operator<<(ostream &out, const no_constructor &)
{
    out<<"no";
    return out;
}

int main()
{
    TEST(double);
    TEST(int);
    TEST(string);
    TEST(char *);
    TEST(double *);
    TEST(A *);
    //cout<<no

    TEST(A);
    TEST(C);
    //cout<<yes

    return 0;
}
