/*************************************************************************
	> File Name: 1.bench.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 06 May 2022 02:50:33 PM CST
 ************************************************************************/
#ifndef _BENCH_H_
#define _BENCH_H_

#include <iostream>
#include <chrono>

#define BEGINT { \
    Timer t;
#define ENDT }

using namespace std;
using hrc = std::chrono::high_resolution_clock;
using mcs = std::chrono::microseconds;

class Timer{
    std::chrono::time_point<hrc> startTimePoint;
public:
    Timer();
    void stop();
    ~Timer();
};

#endif
