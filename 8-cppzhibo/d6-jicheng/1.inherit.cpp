/*************************************************************************
	> File Name: 1.inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 02 May 2022 03:13:36 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal{
protected:
    string name;
public:
    Animal(string n = "animal"):name(n){ //默认构造
        cout<<"Animal constructor"<<endl;
    }
    Animal(const Animal &a){ //拷贝构造
        cout<<"Animal copy constructor"<<endl;
    }
    ~Animal(){
        cout<<"Animal destructor"<<endl;
    }
    void animalTell(){
        cout<<"Animal:name is "<<name<<endl;
    }

    Animal &operator=(const Animal &a){
        cout<<"Animal operator = overload"<<endl;
    }
};

class Cat:public Animal{
//class Cat:private Animal{
    string color;
public:
    Cat():Animal("big cat"),color("yellow"){ //默认构造
        cout<<"Cat constructor"<<endl;
    }
    Cat(const Cat &c):Animal(c),color(c.color){ //拷贝构造
        cout<<"Cat copy constructor"<<endl;
    }
    ~Cat(){
        cout<<"Cat destructor"<<endl;
    }
    void catTell(){
        cout<<"Cat:name is "<<name<<endl;
    }

    Cat &operator=(const Cat &c){
        //调用父类的赋值运算符重载
        Animal::operator=(c);
        color = c.color;
        cout<<"Cat operator = overload"<<endl;
    }
};

class Tiger:public Cat{
public:
    void tigerTell(){
        cout<<"Tiger:name is "<<name<<endl;
    }
};

#if 0
void Tell(){
    Cat c;
    cout<<"Tiger:name is "<<c.name<<endl;
}
#endif

int main()
{
    cout<<sizeof(Animal)<<endl;
    cout<<sizeof(Cat)<<endl;

    Cat c;
    c.catTell();

#if 0
    Animal a;
    Cat *k = &a;
#endif

#if 0
    Animal *p = &c;
    p->animalTell();
#endif
    cout<<"======================"<<endl;
    Cat d(c);
    c = d;
    cout<<"======================"<<endl;

    return 0;
}
