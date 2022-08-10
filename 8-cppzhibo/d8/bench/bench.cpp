/*************************************************************************
> File Name: 1.bench.cpp
> Author: 
> Mail: 
> Created Time: Fri 06 May 2022 02:50:33 PM CST
************************************************************************/

#include "bench.h"

Timer::Timer(){
    startTimePoint = hrc::now();
}
void Timer::stop(){
    auto endTimePoint = hrc::now();
    auto start = std::chrono::time_point_cast<mcs>(startTimePoint).time_since_epoch().count();
    auto end   = std::chrono::time_point_cast<mcs>(endTimePoint).time_since_epoch().count();
    auto duration = end - start;
    cout<<"耗时："<<duration*0.001<<"毫秒（"<<duration<<"微秒）"<<endl;
}
Timer::~Timer(){
    stop();
}

