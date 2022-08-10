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

#define BEGINT {
#define ENDT }

using namespace std;
using hrc = std::chrono::high_resolution_clock;
using mcs = std::chrono::microseconds;

class Timer{
    std::chrono::time_point<hrc> startTimePoint;
public:
    Timer(){
        startTimePoint = hrc::now();
    }
    void stop(){
        auto endTimePoint = hrc::now();
        auto start = std::chrono::time_point_cast<mcs>(startTimePoint).time_since_epoch().count();
        auto end   = std::chrono::time_point_cast<mcs>(endTimePoint).time_since_epoch().count();
        auto duration = end - start;
        cout<<"耗时："<<duration*0.001<<"毫秒（"<<duration<<"微秒）"<<endl;
    }
    ~Timer(){
        stop();
    }
};

int main()
{
BEGINT
    Timer t;
    int sum = 0;
    for(int i = 0; i < 1000000; i++)
    {
        sum += 2;
    }
ENDT

BEGINT
    cout<<"make shared"<<endl;
    Timer t;
    vector<shared_ptr<int>> shared_vector;
    for(int i = 0; i < 1000; ++i)
    {
        shared_vector.push_back(make_shared<int>());
    }
ENDT

BEGINT
    cout<<"new shared"<<endl;
    Timer t;
    vector<shared_ptr<int>> shared_vector2;
    for(int i = 0; i < 1000; ++i)
    {
        shared_vector2.push_back(shared_ptr<int>(new int));
    }
ENDT
#if 0 //c++14
    vector<unique_ptr<int>> unique_vector;
    for(int i = 0; i < 1000; ++i)
    {
        unique_vector.push_back(make_unique<int>());
    }
#endif
BEGINT
    cout<<"new unique"<<endl;
    Timer t;
    vector<unique_ptr<int>> unique_vector2;
    for(int i = 0; i < 1000; ++i)
    {
        unique_vector2.push_back(unique_ptr<int>(new int));
    }
ENDT

    return 0;
}
