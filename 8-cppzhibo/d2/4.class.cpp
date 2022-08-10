/*************************************************************************
> File Name: 4.class.cpp
> Author: 
> Mail: 
> Created Time: Fri 08 Apr 2022 05:26:14 PM CST
************************************************************************/

#include <iostream>
using std::cout;
using std::endl;
using std::string;

#if 0
class Washer{
public:
    string brand;
    int vol;

    void getBrand();
    void wash();
};

void Washer::getBrand(){
    cout << this->brand << endl;
    cout << this <<endl;
}

int main()
{
    Washer ddy;
    ddy.brand = "大地鸭";
    ddy.getBrand();
    cout << &ddy << endl;

    return 0;
}
#endif

#if 1
namespace kkb{
    class Washer{
    public:
        std::string brand;
        int vol;

        void getBrand();
        void wash();
    };
    void Washer::getBrand(){
        std::cout << this << std::endl;
        std::cout << this->brand << std::endl;
    }
}

void getBrand(kkb::Washer *const self)
{
    std::cout << self << std::endl;
    std::cout << self->brand << std::endl;
}

int main()
{
    kkb::Washer ddy;
    ddy.brand = "大地鸭";
    ddy.getBrand();
    std::cout << &ddy << std::endl;

    std::cout << "------1---------" << std::endl;

    kkb::Washer xmz;
    xmz.brand = "西门子";
    xmz.getBrand();
    std::cout << &xmz << std::endl;

    std::cout << "------2---------" << std::endl;

    getBrand(&ddy);
    getBrand(&xmz);

    return 0;
}
#endif
