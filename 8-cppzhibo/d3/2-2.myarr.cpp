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
    int n, end;
    int *data;
    
public:
    Array(int n){
        this->n = n;
        this->data = new int[n];
    }
    size_t size(){
        return n;
    }

    int &at(int idx){
        return data[idx];
    }
    int &operator[](int idx){
#if 0 //访问越界，异常处理!!!
        if(idx < 0 || idx >= n)
        {
            return end;
        }
#endif
        return data[idx];
    }

    void output(){
        cout<<"Array("<<data<<"):";
        for(int i = 0; i < n; i++){
            i && cout<<",";
            cout<<data[i];
        }
        cout<<endl;
    }
    Array(Array &a){
        this->n = a.n;
        //this->data = a.data; // 浅拷贝 error!!
        this->data = new int[this->n]; // 深拷贝
        for(int i = 0; i < n; i++)
        {
            this->data[i] = a.data[i];
            //this->data[i] = a[i];
        }
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

    //Array brr(arr); //和下行等价
    Array brr = arr;
    brr.output();

    brr[3] = 12345;
    arr.output();
    brr.output();

    return 0;
}
