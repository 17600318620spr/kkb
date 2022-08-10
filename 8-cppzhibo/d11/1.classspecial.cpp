/*************************************************************************
	> File Name: 1.classspecial.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 May 2022 04:56:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template <typename T, typename U>
class Test{
public:
    Test()
    {
        cout<<"normal template<T, U>"<<endl;
    }
};

template <>
class Test<int, double>{
public:
    Test()
    {
        cout<<"specialization template<int, double>"<<endl;
    }
};

template <typename T>
class Test<int, T>{
public:
    Test()
    {
        cout<<"partial specialization template<int, T>"<<endl;
    }
};

int main()
{
    Test<int, double> t1;
    Test<double, int> t2;
    Test<int, int> t3;

    return 0;
}
