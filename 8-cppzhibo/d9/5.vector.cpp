/*************************************************************************
	> File Name: 5.vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 May 2022 04:47:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define KKBB namespace kkb{
#define KKBE }

KKBB
class vector{
    int __size;
    int *data;
public:
    vector(int n = 10):__size(n), data(new int[n]){}
    ~vector()
    {
        delete[] data;
        data = nullptr;
        __size = 0;
    }

    vector(const vector &v):__size(v.__size), data(new int[v.__size])
    {
        cout<<"deep constructor"<<endl;
        for(int i = 0; i < __size; i++)
        {
            data[i] = v[i];
        }
    }

    vector(vector &&v):__size(v.__size), data(v.data)
    {
        cout<<"move constructor"<<endl;
        v.__size = 0;
        v.data = nullptr;
    }

    vector operator+(const vector &v)
    {
        vector ret(this->__size + v.__size);
        for(int i = 0; i < this->__size; i++)
        {
            ret[i] = (*this)[i];
        }
        for(int i = this->__size; i < ret.__size; i++)
        {
            ret[i] = v[i - this->__size];
        }
        return ret;
    }

    int &operator[](int idx)const
    {
        return this->data[idx];
    }

    int size() const
    {
        return __size;
    }
};
KKBE

ostream &operator<<(ostream &out, const kkb::vector &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        i && cout<<",";
        cout<<v[i];
    }
    return out;
}

int main()
{
    kkb::vector v1, v2;
    for(int i = 0; i < v1.size(); i++)
    {
        v1[i] = rand() % 100;
    }
    for(int i = 0; i < v2.size(); i++)
    {
        v2[i] = rand() % 100;
    }

    kkb::vector v3 = v1 + v2;
    cout<<v1<<endl;
    cout<<v2<<endl;
    cout<<v3<<endl;

    //kkb::vector v4(v3);
    //kkb::vector v4(move(v3));
    //kkb::vector v4(forward<kkb::vector &&>(v3));
    kkb::vector v4(forward<const kkb::vector &>(v3));
    cout<<v3<<endl;
    cout<<v4<<endl;

    return 0;
}
