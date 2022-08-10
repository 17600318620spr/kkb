/*************************************************************************
	> File Name: 1.auto.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 09 May 2022 08:17:33 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
//#include <typeinfo>
using namespace std;

//string getName(auto x) //error
string getName()
{
    return "kkb";
}
#if 0 //error
auto a[3] = {1,2,3};
class{
    int x, y;
    auto z;
};
#endif
int main()
{
    auto a = 3;
    auto b = a;
    auto c = 3.5;
    auto d = 3.5f;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(b)<<endl;
    cout<<sizeof(c)<<endl;
    cout<<sizeof(d)<<endl;

    map<int, int> m;
    for(int i = 0; i < 10; i++)
    {
        m[rand()%10] = rand();
    }

    //for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    auto it = m.begin();
    for(; it != m.end(); it++)
    {
        cout<<it->first<<","<<it->second<<endl;
    }

    auto name = getName();
    cout<<name<<endl;
    //cout<<name.size()<<endl;
    
    cout<<typeid(b).name()<<endl;
    cout<<typeid(it).name()<<endl;
    cout<<typeid(name).name()<<endl;

    if(typeid(c).hash_code() == typeid(float).hash_code())
    {
        cout<<"c is float"<<endl;
    }
    if(typeid(c).hash_code() == typeid(double).hash_code())
    {
        cout<<"c is double"<<endl;
    }

    return 0;
}
