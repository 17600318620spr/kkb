/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 06 May 2022 10:16:56 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include "bench/bench.h"
using namespace std;

class PQueue{
public:
    virtual void push(int) = 0;
    virtual void pop() = 0;
    virtual bool empty() = 0;
    virtual int top() = 0;
    virtual int size() = 0;
};

class vector_queue:public PQueue, public vector<int>{
public:
    virtual void push(int x){
        this->vector<int>::push_back(x);
    }
    virtual void pop(){
        if(empty())
            return ;

        vector<int>::iterator p = this->begin();
        for(auto iter = begin(); iter != end(); iter++)
        {
            if(*iter > *p)
                p = iter;
        }
        erase(p);
        return ;
    }
    virtual bool empty(){
        return size() == 0;
    }
    virtual int top(){
        if(empty())
            return 0;
        int m = at(0);
        for(int i = 1; i < size(); i++)
        {
            m = max(at(i), m);
        }
        return m;
    }
    virtual int size(){
        return this->vector<int>::size();
    }
};

class heap_queue:public PQueue, public vector<int>{
public:
    virtual void push(int x){
        push_back(x);
        //向上调整
        up_maintain(size());
        return ;
    }
    virtual void pop()
    {
        std::swap(at(0), at(size()-1));
        pop_back();
        //向下调整
        down_maintain(0);
        return ;
    }
    virtual bool empty(){
        return size() == 0;
    }
    virtual int top(){
        if(empty())
            return 0;
        return at(0);
    }
    virtual int size(){
        return this->vector<int>::size();
    }

    void up_maintain(int idx)
    {
        while(idx>1 && at(idx-1) > at((idx/2)-1))
        {
            std::swap(at(idx-1), at((idx/2)-1));
            idx/=2;
        }
        return ;
    }
    void down_maintain(int idx)
    {
        while(2*idx+1 < size())
        {
            int tmp = idx;
            if(at(2*idx+1) > at(idx))
                tmp = 2*idx+1;
            if(2*idx+2 < size() && at(2*idx+2) > at(tmp))
                tmp = 2*idx+2;
            if(tmp == idx)
                break;
            std::swap(at(idx), at(tmp));
            idx = tmp;
        }
        return ;
    }
};

int main()
{
    srand(time(0));

    vector_queue q1;
    for(int i = 0; i < 10; i++)
    {
        int rnd = rand() % 100;
        q1.push(rnd);
        cout<<rnd<<" ";
    }
    cout<<endl;

BEGINT
    while(!q1.empty())
    {
        cout<<q1.top()<<" ";
        q1.pop();
    }
    cout<<endl;
ENDT

    heap_queue q2;
    for(int i = 0; i < 10; i++)
    {
        int rnd = rand() % 100;
        q2.push(rnd);
        cout<<rnd<<" ";
    }
    cout<<endl;

BEGINT
    while(!q2.empty())
    {
        cout<<q2.top()<<" ";
        q2.pop();
    }
    cout<<endl;
ENDT

    return 0;
}
