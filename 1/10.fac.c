/*************************************************************************
	> File Name: 10.fac.c
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Sep 2021 04:33:46 PM CST
 ************************************************************************/

#include<stdio.h>

int fac(int n)
{
    if(n == 1)
        return 1;
    return n * fac(n-1);
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        printf("fac(%d)=%d\n", n, fac(n));
    }

    return 0;
}
