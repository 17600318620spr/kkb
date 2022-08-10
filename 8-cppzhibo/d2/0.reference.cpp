/*************************************************************************
	> File Name: 0.reference.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 02:21:13 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int a = 333;
    int &p = a;

    p = 444;

    cout << a << endl;
    cout << p << endl;

    return 0;
}


int test1()
{
    int a = 333;
    int &b = a;

    return b;
}

int test2()
{
    int a = 333;
    int *p = &a;

    return *p;
}
