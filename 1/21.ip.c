/*************************************************************************
	> File Name: 21.ip.c
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Jan 2022 02:54:21 PM CST
 ************************************************************************/

#include<stdio.h>

union IP
{
    struct
    {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    }ip;
    unsigned int num;
};

int is_little()
{
    int num = 1;
    return ((char *)(&num))[0];
}

int main()
{
    printf("%d\n", is_little());

    char str[100] = {0};
    char arr[4] = {0};
    union IP p;
 
    while(~scanf("%s", str))
    {
        sscanf(str, "%d.%d.%d.%d", &arr[0], &arr[1], &arr[2], &arr[3]);
#if 0
        p.ip.a1 = arr[0];
        p.ip.a2 = arr[1];
        p.ip.a3 = arr[2];
        p.ip.a4 = arr[3];
#else
        p.ip.a1 = arr[3];
        p.ip.a2 = arr[2];
        p.ip.a3 = arr[1];
        p.ip.a4 = arr[0];
#endif
        printf("%u\n", p.num);
    }

    return 0;
}
