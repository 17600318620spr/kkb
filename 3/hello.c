/*************************************************************************
	> File Name: hello.c
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Feb 2022 04:34:04 PM CST
 ************************************************************************/

#include<stdio.h>

int main1()
{
#if 0
    fputc('A', stdout);
    fputc('B', stdout);
    fputc('\n', stdout);
#else
    fputc('A', stderr);
    fputc('B', stderr);
#endif
    while(1)
    {
        ;
    }

    return 0;
}

int main()
{
    for(int i = 0; i < 1025; i++)
        fputc('B', stdout);

    while(1)
    {
        ;
    }

    return 0;
}
