/*************************************************************************
	> File Name: 2.thread.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 May 2022 09:20:42 PM CST
 ************************************************************************/

#include <iostream>
#include <thread>
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

int count_prime(int l, int r)
{
    int cnt = 0;
    for(int i = l; i <= r; i++)
    {
        cnt += is_prime(i);
    }
    return cnt;
}

void worker(int l, int r, int &ret)
{
    cout<<this_thread::get_id()<<":begin"<<endl;
    ret = count_prime(l, r);
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
    int ret[10]; //避免资源竞争

    for(int i = 0, j = 1; i < 10; i++, j += batch)
    {
        trr[i] = new thread(worker, j, j + batch - 1, ref(ret[i]));
    }

    for(int i = 0; i < 10; i++)
    {
        trr[i]->join();
    }

    int ans = 0;
    for(auto x:ret)
        ans += x;
    for(auto x:trr)
        delete x;

    cout<<ans<<endl;

    return 0;
}
