/*************************************************************************
	> File Name: 5.reference.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 May 2022 08:22:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define KKBB namespace kkb{
#define KKBE }

KKBB
template <typename T>
void swap(T &&a, T &&b)
//void swap(T &a, T &b)
{
    //auto c = a;
    typename remove_reference<T>::type c = a;
    a = b;
    b = c;
    return ;
}
KKBE

int main()
{
    int m = 3, n = 4;
    kkb::swap(m, n);
    cout<<m<<","<<n<<endl;

    kkb::swap(123, 345);
    //kkb::swap(123, m);

    return 0;
}
