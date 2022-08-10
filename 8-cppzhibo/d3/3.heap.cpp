/*************************************************************************
	> File Name: 3.heap.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Apr 2022 09:58:22 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A{
    int x;
public:
    A(){
        cout<<this<<" constructor A"<<endl;
    }
    ~A(){
        cout<<this<<" destructor A"<<endl;
    }
};

int main()
{
    int n = 10;

    cout<<"malloc int"<<endl;
    int *p = (int *)malloc(sizeof(int) * 10);
    free(p);

    cout<<"new int"<<endl;
    int *q = new int[10];
    delete[] q;

    cout<<"malloc A"<<endl;
    A *k = (A *)malloc(sizeof(A) * n);
#if 0
    //原地构造
    for(int i = 0; i < n; i++)
    {
        new(k+i) A(); //也可以使用其他类的构造 高手自己维护
    }
#endif
    free(k);

    cout<<"new A"<<endl;
    A *s = new A[10];
    delete[] s;

    return 0;
}
