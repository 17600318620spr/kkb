/*************************************************************************
	> File Name: 1.static.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Apr 2022 03:02:16 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class People{
public:
    People():say_cnt(0){
        People::total_num++;
    }
    ~People(){
        People::total_num--;
        cout<<this<<" destructor"<<endl;
    }

    void say() const{
        cout<<"hahaha,happy"<<endl;
        say_cnt++;
        output();
    }

    void output(){
        cout<<"non-const output"<<endl;
    }
    void output() const{
        cout<<"const output"<<endl;
    }

    static void showNum(){
        cout<<People::total_num<<endl;
    }
private:
    //声明
    static int total_num;
    mutable int say_cnt;
};

//定义 初始化尽量放在构造函数里
int People::total_num = 100;

int main()
{
    People xp, klss;
    People::showNum();
    //xp.showNum();
    //klss.showNum();
    
    {
        People xp, klss;
        People::showNum();
        cout<<">>>>>>>1>>>>>>>>>>"<<endl;
    }
    People::showNum();
    cout<<">>>>>>>2>>>>>>>>>>"<<endl;

    const People xiaok;
    xiaok.say();
    cout<<">>>>>>>3>>>>>>>>>>"<<endl;

    return 0;
}
