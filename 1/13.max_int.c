/*************************************************************************
	> File Name: 13.max_int.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Sep 2021 02:38:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<stdarg.h>

int max_int(int n, ...)
{
    int ans = INT32_MIN;
    va_list arg;
    va_start(arg, n);
    while(n--)
    {
        int temp = va_arg(arg, int);//宏
        if(temp > ans)
        {
            ans = temp;
        }
    }
    va_end(arg);
    return ans;
}

int main()
{
    printf("%d\n", max_init(3, 12, 0, -2)); //12
    printf("%d\n", max_init(5, 12, 0, -2, 33, 1)); //33
    printf("%d\n", max_init(3, 12, 0, -2, 33, 1)); //12

    return 0;
}
