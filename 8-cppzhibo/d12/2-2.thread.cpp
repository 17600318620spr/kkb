/*************************************************************************
	> File Name: 2.thread.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 May 2022 09:20:42 PM CST
 ************************************************************************/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void func(int x, string msg)
{
    cout<<x<<":"<<msg<<endl;
}

bool is_prime(int x)
{
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}

int cnt = 0;
mutex mtx;
int count_prime(int l, int r)
{
    for(int i = l; i <= r; i++)
    {
        int r = is_prime(i);
        //unique_lock<mutex> lock(mtx);
        __sync_fetch_and_add(&cnt, r);
        //cnt += r;
        //lock.unlock();
    }
    return cnt;
}

void worker(int l, int r)
{
    cout<<this_thread::get_id()<<":begin"<<endl;
    count_prime(l, r);
    cout<<this_thread::get_id()<<":end"<<endl;
    return ;
}

//计算5000w内有多少个素数
int main()
{
#if 0
    thread t1(func, 3, "hello");
    t1.join();
#endif

    cout<<count_prime(1, 10)<<endl;

    const int batch = 5000000;
    thread *trr[10];
    //int ret[10]; //避免资源竞争

    for(int i = 0, j = 1; i < 10; i++, j += batch)
    {
        trr[i] = new thread(worker, j, j + batch - 1);
    }

    for(int i = 0; i < 10; i++)
    {
        trr[i]->join();
    }

    for(auto x:trr)
        delete x;

    cout<<cnt<<endl;

    return 0;
}
