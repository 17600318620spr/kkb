/*************************************************************************
	> File Name: 19.log.c
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Jan 2022 11:13:04 AM CST
 ************************************************************************/

#include<stdio.h>
//#define DEBUG

#ifdef DEBUG
#define log(frm, args...){ \
    printf("[%s:%s:%d]", __FILE__, __func__, __LINE__); \
    printf(frm, ##args); \
    printf("\n"); \
}
#else
#define log(frm, args...)
#endif

#define contact(a, b) a##b

int main()
{
    int a = 123, b = 345, abcdef = 0;
    log("%d", a);
    log("%d", b);
    //printf("hello world\n");
    log("hello world\n");

    contact(abc, def) = 112233;
    log("%d", abcdef);

    return 0;
}
