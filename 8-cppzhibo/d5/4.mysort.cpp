/*************************************************************************
	> File Name: 4.mysort.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2022 05:09:16 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

ostream &operator<<(ostream &out, const vector<int> v)
{
    for(auto x:v)
    {
        out<<x<<" ";
    }

    return out;
}

class CMP{
    int opt;
public:
    CMP(int x = 0):opt(x){}
    bool operator()(int a, int b)
    {
        //return opt ? a > b : a < b;
        return opt ^ a < b;
    }
};

int main()
{
    int n = 10;
    vector<int> v;

    while(n--)
    {
        int a;
        cin>>a, v.push_back(a);
    }

    //sort(v.begin(), v.end(), cmp);
#if 0 //有名对象
    CMP c;
    sort(v.begin(), v.end(), c);
#else //匿名对象
    sort(v.begin(), v.end(), CMP(1));
#endif
    cout<<v<<endl;

    return 0;
}
