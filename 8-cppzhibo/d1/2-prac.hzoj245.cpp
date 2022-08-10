/*************************************************************************
	> File Name: 2-prac.hzoj245.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jun 2022 11:25:45 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        int t;
        cin>>t, v.push_back(t);
    }

    sort(v.begin(), v.end());

    int pos = v[n/2];
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += abs(v[i]-pos);
    }
    cout<<sum<<endl;

    return 0;
}
