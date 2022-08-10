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

class yes_constructor{
public:
    static string has_constructor;
};
string yes_constructor::has_constructor = "yes";

class no_constructor{
public:
    static string has_constructor;
};
string no_constructor::has_constructor = "no";



template <class T>
class Type_trial:public yes_constructor{
};

template <>
class Type_trial<double>:public no_constructor{
};

template <>
class Type_trial<int>:public no_constructor{
};

template <>
class Type_trial<string>:public no_constructor{
};

template <class T>
class Type_trial<T *>:public no_constructor{
};

#define TEST(type){ \
    cout<<#type<<":"<<Type_trial<type>::has_constructor<<endl; \
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
