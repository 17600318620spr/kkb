/*************************************************************************
	> File Name: 5.lamda.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 18 May 2022 07:22:38 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 4, m = 3;

#if 0
    auto func = [=](int a, int b)
    {
        return a + b + n + m;
    };
#else
    auto func = [&](int a, int b)
    {
        n++;
        m++;
        return a + b + n;
    };
#endif

    cout<<func(2,4)<<endl;
    cout<<"n="<<n<<endl;
    cout<<"m="<<m<<endl;

    vector<int> arr(10);
#if 0
    for(int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
#else
    for(int &x:arr)
        x = 5;
#endif

    for(int x:arr)
        cout<<x<<" ";
    cout<<endl;

    for_each(arr.begin(), arr.end(), [](int &x){
        x *= x;
    });

    for_each(arr.begin(), arr.end(), [](int x){
        cout<<x<<" ";
    });
    cout<<endl;

    return 0;
}
