/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Feb 2022 07:33:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
    int a = 3/0;

    while(1)
    {
        sleep(1);
    }

    return 0;
}
