/*************************************************************************
	> File Name: 2.multiInherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 03 May 2022 09:36:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal{
public:
    int age;
    Animal():age(1){}
};

class Horse:public Animal{
public:
    Horse(){
        cout<<"Horse constructor"<<endl;
    }
    void setAge(int a){
        cout<<"set &age"<<&age<<endl;
        age = a;
    }
    ~Horse(){
        cout<<"Horse destructor"<<endl;
    }
};

class Donkey:public Animal{
public:
    Donkey(){
        cout<<"Donkey constructor"<<endl;
    }
    int getAge(){
        cout<<"get &age"<<&age<<endl;
        return age;
    }
    ~Donkey(){
        cout<<"Donkey destructor"<<endl;
    }
};

class Mule:public Horse, public Donkey{
public:
    Mule(){
        cout<<"Mule constructor"<<endl;
    }
    ~Mule(){
        cout<<"Mule desstructor"<<endl;
    }
};

int main()
{
    Mule m;
    m.setAge(18);
    cout<<m.getAge()<<endl;

    return 0;
}
