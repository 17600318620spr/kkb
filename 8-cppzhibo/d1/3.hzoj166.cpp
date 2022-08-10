/*************************************************************************
	> File Name: 3.hzoj166.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 02:21:26 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    string s1, s2;
    int n;

    cin >> s1 >> n >> s2;

    int len = s1.size();
    len = len > 100 ? 100 : len;
    cout << len << endl;

    s1.insert(n-1, s2);
    cout << s1 << endl;

    //cout << len - s1.rfind("x") << endl;
    cout << s1.size() - s1.rfind("x") << endl;

    return 0;
}
