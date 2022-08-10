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

template <class T>
class Type_trial{
public:
    static string has_constructor;
};
template <class T>
string Type_trial<T>::has_constructor = "yes";

template <>
class Type_trial<double>{
public:
    static string has_constructor;
};
string Type_trial<double>::has_constructor = "no";

template <>
class Type_trial<int>{
public:
    static string has_constructor;
};
string Type_trial<int>::has_constructor = "no";

template <>
class Type_trial<string>{
public:
    static string has_constructor;
};
string Type_trial<string>::has_constructor = "no";

template <class T>
class Type_trial<T *>{
public:
    static string has_constructor;
};
template <class T>
string Type_trial<T *>::has_constructor = "no";


int main()
{
    cout<<Type_trial<double>::has_constructor<<endl;
    cout<<Type_trial<int>::has_constructor<<endl;
    cout<<Type_trial<string>::has_constructor<<endl;
    cout<<Type_trial<char *>::has_constructor<<endl;
    cout<<Type_trial<double *>::has_constructor<<endl;
    cout<<Type_trial<A *>::has_constructor<<endl;
    //cout<<no

    cout<<Type_trial<A>::has_constructor<<endl;
    cout<<Type_trial<A>::has_constructor<<endl;
    //cout<<yes

    return 0;
}
