/*************************************************************************
	> File Name: 3.nullptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 May 2022 11:56:28 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void test(int x)
{
    cout<<__PRETTY_FUNCTION__<<endl;
    return ;
}
void test(int *x)
{
    cout<<__PRETTY_FUNCTION__<<endl;
    return ;
}

int main()
{
    //test(NULL);
    test(0);
    test(nullptr);
    
    void *p = NULL;
    void *k = nullptr;
    cout<<p<<endl;
    cout<<k<<endl;

    cout<<typeid(NULL).name()<<endl;
    cout<<typeid(nullptr).name()<<endl;

    return 0;
}
