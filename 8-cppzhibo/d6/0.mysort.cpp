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

namespace kkb{
void mysort(int *arr, int l, int r, function<bool(int,int)> cmp=CMP()){
    if(l >= r)
        return ;

    int x = l, y = r, z = arr[(l+r)>>1];
    do{
        while(cmp(arr[x], z)) ++x;
        while(cmp(z, arr[y])) --y;
        if(x <= y)
        {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    }while(x <= y);

    mysort(arr, l, y, cmp);
    mysort(arr, x, r, cmp);

    return ;
}
}

int main()
{
    int brr[5] = {1,6,3,5,2};
    kkb::mysort(brr, 0, 4);
    for(int i = 0; i < 5; i++)
    {
        i && cout<<",";
        cout<<brr[i];
    }
    cout<<endl;

    return 0;
}

int main1()
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

