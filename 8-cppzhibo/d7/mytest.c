/*************************************************************************
	> File Name: mytest.c
	> Author: 
	> Mail: 
	> Created Time: Wed 04 May 2022 10:02:56 PM CST
 ************************************************************************/

#include<stdio.h>

struct Base{
    //short b;
    //int c;
    char *p;
    char a;
};

int main()
{
    printf("%ld\n", sizeof(struct Base));

    return 0;
}
