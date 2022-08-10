/*************************************************************************
> File Name: 4.exception.cpp
> Author: 
> Mail: 
> Created Time: Wed 18 May 2022 04:40:59 PM CST
************************************************************************/

#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
using namespace std;

class ZeroDivException:public runtime_error{
public:
    ZeroDivException(const string &msg = "zero div"):runtime_error(msg){}
    const char *what()const noexcept override
    {
        return "__what__zero__div";
    }
};

#if 0
int suml2r(int l, int r, vector<int> v)throw(out_of_range, int, exception)
{
    int sum = 0;
    for(int i = l; i < r; i++)
    {
        sum+=v.at(i);
    }
    return sum;
}
#else
int suml2r(int l, int r, vector<int> v)noexcept
{
    int sum = 0;
    for(int i = l; i < r; i++)
    {
        sum+=v[i];
    }
    return sum;
}
#endif

int main()
{
    try{
        try{
#if 0
            vector<int> arr(10);
            for(int i = 0; i < 10; i++)
            {
                arr[i] = rand();
            }

            //suml2r(-1, 100, arr);

            cout<<arr[-1]<<endl;
            cout<<arr.at(-1)<<endl;
            cout<<"check point 1"<<endl;
#endif
            int n;
            cin>>n;
            if(n == 0)
                throw(ZeroDivException());
                //throw(string("zero div"));
                //throw("zero div");
            cout<<10/n<<endl;

        }catch(out_of_range &e){
            cout<<"out_of_range:"<<e.what()<<endl;
            throw(e);
        }catch(ZeroDivException &e){
            cout<<"zde:"<<e.what()<<endl;
        }catch(exception &e){
            cout<<"exception:"<<e.what()<<endl;
        }/*catch(...){
            cout<<"catch an obj"<<endl;
        }*/
 
    }catch(int &e){
        cout<<"int:"<<e<<endl;
    //}catch(const char *&e){
    }catch(string &e){
        cout<<"string:"<<e<<endl;
    }catch(...){
        cout<<"catch an object"<<endl;
    }

    cout<<"keep going"<<endl;

    return 0;
}
