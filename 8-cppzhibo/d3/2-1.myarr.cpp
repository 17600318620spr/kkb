/*************************************************************************
	> File Name: 2.myarr.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Apr 2022 05:12:03 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Array{
private:
    int n;
    int *data;
    
public:
    Array(int n){
        this->n = n;
        this->data = new int[n];
    }
    size_t size(){
        return n;
    }
    //int at(int idx){
    int &at(int idx){
        return data[idx];
    }
    int &operator[](int idx){
        return data[idx];
    }
    void output(){
        cout<<"Array("<<data<<"):";
        for(int i = 0; i < n; i++)
        {
            i && cout<<",";
            cout<<data[i];
        }
        cout<<endl;
    }
    ~Array(){
        delete[] data;
    }
};

int main()
{
    Array arr(10);

    for(int i = 0; i < arr.size(); i++)
    {
        //arr.at(i) = rand() % 100;
        arr[i] = rand() % 100;
    }
    arr.output();

    return 0;
}
