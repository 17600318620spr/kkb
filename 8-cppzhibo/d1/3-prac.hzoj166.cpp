/*************************************************************************
	> File Name: 3-prac.hzoj166.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jun 2022 02:01:11 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    int n;

    cin>>s1>>n>>s2;
    int len = s1.size();
    len = len>100?100:len;
    cout<<len<<endl;

    cout<<s1.insert(n-1, s2)<<endl;
    cout<<s1.size()-s1.rfind("x")<<endl;

    return 0;
}
