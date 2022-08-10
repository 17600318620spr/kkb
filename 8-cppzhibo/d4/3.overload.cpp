/*************************************************************************
	> File Name: 3.overload.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Apr 2022 09:32:49 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int inc(double x)
{
    return x++;
}

int inc(const double x)
{
    return x++;
}

int inc(int *p)
{
    return *p;
}

int inc(int const *p)
{
    return *p;
}

int main()
{
    //inc(4);

    return 0;
}
