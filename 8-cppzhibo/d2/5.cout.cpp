/*************************************************************************
	> File Name: 5.cout.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 08:13:34 PM CST
 ************************************************************************/

#include <iostream>
#define BEGINS(x) namespace x{
#define ENDS(x) }

#if 0
BEGINS(kkb)

class Ostream{
public:
    Ostream &operator<<(int x){
        printf("%d", x);
        return *this; //返回cout!!
    }
    Ostream &operator<<(const char *x){
        printf("%s", x);
        return *this;
    }
};

Ostream cout;

ENDS(kkb)

int main()
{
    int n = 333;
    
    std::cout << n << " " << 111;
    std::cout << std::endl; //
    kkb::cout << n << " " << 111;;
    std::cout << std::endl; //

    return 0;
}
#endif


#if 1
BEGINS(kkb)

class Ostream{
public:
#if 1
    Ostream &operator<<(int x){
        printf("%d", x);
        return *this;
    }
    Ostream &operator<<(const char *x){
        printf("%s", x);
        return *this;
    }
#else
    Ostream *operator<<(int x){
        printf("%d", x);
        return this;
    }
    Ostream *operator<<(const char *x){
        printf("%s", x);
        return this;
    }
#endif
};

Ostream cout;

ENDS(kkb)

int main()
{
    int n = 333;

    std::cout << n << " " << 111;
    std::cout << std::endl;
#if 1
    kkb::cout << n << " " << 111;
    std::cout << std::endl;
#else
    *(*(kkb::cout << n) << " ") << 111;;
    std::cout << std::endl;
#endif
    return 0;
}
#endif
