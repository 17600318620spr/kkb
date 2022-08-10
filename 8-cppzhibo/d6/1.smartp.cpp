/*************************************************************************
	> File Name: 1.smartp.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Apr 2022 03:57:52 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
using namespace std;

class A{
public:
    A(){
        cout<<this<<":constructor"<<endl;
    }
    ~A(){
        cout<<this<<":destructor"<<endl;
    }
    void func()
    {
        cout<<"A func"<<endl;
    }
};

int main()
{
    //A *p = new A;
    //p = nullptr;

    shared_ptr<A> shp(new A);
    shp = nullptr;

    shared_ptr<A> lsp(new A);
    shared_ptr<A> lsp2 = lsp;
    cout<<lsp.use_count()<<endl;

    lsp->func();
    (*lsp).func();

    lsp2 = nullptr;
    cout<<lsp.use_count()<<endl;

    lsp2 = lsp;
    cout<<lsp.use_count()<<endl;

    return 0;
}
