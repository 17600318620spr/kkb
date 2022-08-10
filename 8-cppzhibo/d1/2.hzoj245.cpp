/*************************************************************************
	> File Name: 2.hzoj245.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 11:12:36 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> v;
    int n, t;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t,v.push_back(t);

    sort(v.begin(), v.end());

    int pos = v[n/2], sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += abs(v[i] - pos);
    }
    cout << sum << endl;

    return 0;
}
