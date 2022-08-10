/*************************************************************************
	> File Name: 1.friend.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 20 Apr 2022 03:07:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class People{
    int money;
public:
    People():money(1000000){}
    void cost()
    {
        money -= 10000;
    }

    void show()
    {
        cout<<money<<endl;
    }

    friend void useOthersMoney(People &a);
};

void useOthersMoney(People &a)
{
    a.money -= 100000;
}

int main()
{
    People xiaok;

    xiaok.show();
    useOthersMoney(xiaok);
    xiaok.show();

    return 0;
}
