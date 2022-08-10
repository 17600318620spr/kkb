/*************************************************************************
	> File Name: 6.bindorder.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 May 2022 12:59:39 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#if 0
void func(int &x)
{
    cout<<__PRETTY_FUNCTION__<<endl;
}
void func(int &&x)
{
    cout<<__PRETTY_FUNCTION__<<endl;
}
#endif
void func(const int &x)
{
    cout<<__PRETTY_FUNCTION__<<endl;
}

int main()
{
    int x = 3;
    const int y = 6;

    func(x);
    func(4);
    func(y);

    return 0;
}
