/*************************************************************************
	> File Name: 1.smartp.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Apr 2022 03:57:52 PM CST
 ************************************************************************/

#include <iostream>
//#include <memory>
//using namespace std;
using std::cout;
using std::endl;

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

class shared_ptr{
    A *obj;
    int *cnt;
public:
    shared_ptr():obj(nullptr),cnt(nullptr){} //默认构造
    shared_ptr(A *obj):obj(obj),cnt(new int(1)){} //转换构造
    int use_count()
    {
        return *cnt;
    }

    A *operator->()
    {
        return obj;
    }
    A &operator*()
    {
        return *obj;
    }

    ~shared_ptr()
    {
        if(cnt != nullptr)
        {
            *cnt -= 1;
            if(*cnt == 0)
            {
                delete obj;
                delete cnt;
            }
        }
        obj = nullptr;
        cnt = nullptr;
    }

    //计数器cnt何时会变多？ //86行拷贝构造时数据没有增加（没有实现拷贝构造）
    shared_ptr(const shared_ptr &p):obj(p.obj),cnt(p.cnt) //拷贝构造
    {
        if(cnt != nullptr)
            *cnt += 1;
    }

    shared_ptr &operator=(const shared_ptr &p) //赋值运算符重载
    {
        //if(this->obj != p.obj)
        if(this->obj != p.obj)
        {
            //处理好原来指向的那块空间 cnt--
            if(cnt != nullptr)
            {
                *cnt -= 1;
                if(*cnt == 0)
                {
                    delete obj;
                    delete cnt;
                }
            }
            //指向新的空间和计数器
            cnt = p.cnt;
            obj = p.obj;
            if(cnt != nullptr)
            {
                *cnt += 1;
            }
        }

        return *this;
    }
};

int main()
{
    //A *p = new A;
    //p = nullptr;

    shared_ptr shp(new A);
    shp = nullptr;
    shared_ptr ppp; //默认构造

    shared_ptr lsp(new A); //转换构造
    shared_ptr lsp2 = lsp; //拷贝构造
    cout<<lsp.use_count()<<endl; //2

    lsp->func();
    (*lsp).func();

    lsp2 = nullptr;
    cout<<lsp.use_count()<<endl; //1

    lsp2 = lsp;
    cout<<lsp.use_count()<<endl; //2

    return 0;
}
