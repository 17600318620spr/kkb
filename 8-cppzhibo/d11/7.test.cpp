/*************************************************************************
	> File Name: 7.test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 May 2022 09:47:30 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//1.
template <int N>
struct sum{
    static constexpr int r = sum<N-1>::r + N;
};
template <>
struct sum<1>{
    static constexpr int r = 1;
};

//2.
template <int N>
struct is_even{
    static constexpr const char *r = is_even<N%2>::r;
};
template <>
struct is_even<0>{
    static constexpr const char *r = "yes";
};
template <>
struct is_even<1>{
    static constexpr const char *r = "no";
};

//3.
template <int N>
struct GOOD_OR_BAD{
    static constexpr const char *r = "bad";
};
template <>
struct GOOD_OR_BAD<1>{
    static constexpr const char *r = "good";
};

template <int N>
struct score_judge{
    static constexpr const char *r = GOOD_OR_BAD<(N>=60)>::r;
};

//4.
template <int i, int N>
struct getnext{
    static constexpr int r = (N%i)?i+1:0;
};

template <int i, int N>
struct test_prime{
    static constexpr const char *r = (i*i>N)?"yes":test_prime<getnext<i,N>::r,N>::r;
};
template <int N>
struct test_prime<0, N>{
    static constexpr const char *r = "no";
};

template <int N>
struct is_prime{
    static constexpr const char *r = test_prime<2, N>::r;
};

int main()
{
    //1.累加和
    cout<<sum<4>::r<<endl;      //10
    cout<<sum<100>::r<<endl;    //5050
    //2.判断奇偶
    cout<<is_even<5>::r<<endl;  //no
    cout<<is_even<6>::r<<endl;  //yes
    //3.判断是否合格
    cout<<score_judge<60>::r<<endl; //good
    cout<<score_judge<5>::r<<endl; //bad
#if 1
    //4.素数
    cout<<is_prime<2>::r<<endl; //yes
    cout<<is_prime<3>::r<<endl; //yes
    cout<<is_prime<5>::r<<endl; //yes
    cout<<is_prime<10>::r<<endl; //no
    //cout<<is_prime<9973>::r<<endl; //no
#endif

    return 0;
}
