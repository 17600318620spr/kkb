/*************************************************************************
	> File Name: 3.reference.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 04:01:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    const int &b = 10;
    //*&b = 100;
    *(int *)&b = 100;

    cout << b <<endl;
    cout << &b <<endl;

    return 0;
}
