/*************************************************************************
	> File Name: 5.int.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 May 2022 08:28:06 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template <int M>
void print()
{
    cout<<M<<",";
    print<M-1>();
    return ;
}

template <>
void print<1>()
{
    cout<<1<<endl;;
    return ;
}

int main()
{
    print<5>();
    print<10>();
    print<2>();

    return 0;
}
