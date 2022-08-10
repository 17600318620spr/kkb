/*************************************************************************
	> File Name: 1.reference.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 03:14:33 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int a[10];
    int (&b)[10] = a;

    cout << a << endl;
    cout << b << endl;

    return 0;
}
