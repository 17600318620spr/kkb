/*************************************************************************
	> File Name: 1.bench.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 06 May 2022 02:50:33 PM CST
 ************************************************************************/

#include <iostream>
#include <chrono>
#include <vector>
#include <memory>
#include "bench.h"
using namespace std;

int main()
{
BEGINT
    int sum = 0;
    for(int i = 0; i < 1000000; i++)
    {
        sum += 2;
    }
ENDT

    cout<<"make shared"<<endl;
BEGINT
    vector<shared_ptr<int>> shared_vector;
    for(int i = 0; i < 1000; ++i)
    {
        shared_vector.push_back(make_shared<int>());
    }
ENDT

    cout<<"new shared"<<endl;
BEGINT
    vector<shared_ptr<int>> shared_vector2;
    for(int i = 0; i < 1000; ++i)
    {
        shared_vector2.push_back(shared_ptr<int>(new int));
    }
ENDT

#if 0 //c++14
    cout<<"make unique"<<endl;
BEGINT
    vector<unique_ptr<int>> unique_vector;
    for(int i = 0; i < 1000; ++i)
    {
        unique_vector.push_back(make_unique<int>());
    }
ENDT
#endif

    cout<<"new unique"<<endl;
BEGINT
    vector<unique_ptr<int>> unique_vector2;
    for(int i = 0; i < 1000; ++i)
    {
        unique_vector2.push_back(unique_ptr<int>(new int));
    }
ENDT

    return 0;
}
