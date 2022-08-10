/*************************************************************************
	> File Name: 2.class.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 May 2022 03:29:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//template <typename T>
class PRINT{
public:
    template <typename T>
    PRINT &operator()(T t)
    {
        cout<<t<<endl;
        return *this;
    }
};

int main()
{
#if 0
    PRINT<int> pint;
    pint(3)(234)(456);
    PRINT<string> pstr;
    pstr("kkb")("haha")("good");
#else
    PRINT pt;
    pt(3)(234)(456)("kkb")("haha")("good");
#endif
    return 0;
}
