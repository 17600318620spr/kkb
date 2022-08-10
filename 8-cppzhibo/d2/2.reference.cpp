/*************************************************************************
	> File Name: 2.reference.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Apr 2022 03:19:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#if 0
int test(int b)
{
    b = 444;
}

int main()
{
    int a = 333;

    test(a);
    cout << a << endl; //333

    return 0;
}
#endif

#if 0
int test(int *b)
{
    *b = 444;
}

int main()
{
    int a = 333;

    test(&a);
    cout << a << endl; //444

    return 0;
}
#endif

#if 0
int test(int &b)
{
    b = 444;
}

int main()
{
    int a = 333;

    test(a);
    cout << a << endl; //444

    return 0;
}
#endif

#if 0
int *test(int *b)
{
    *b = 444;

    return b;
}

int main()
{
    int a = 333;

    //*test(&a) = 555;
    //cout << a << endl; //555
    cout<<*test(&a)<<endl; //444

    return 0;
}
#endif

#if 1
int &test(int &b)
{
    b = 444;

    return b;
}

int main()
{
    int a = 333;

    test(a) = 555;
    cout << a << endl;

    return 0;
}
#endif
