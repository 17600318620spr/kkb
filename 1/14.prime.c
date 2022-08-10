/*************************************************************************
	> File Name: 14.prime.c
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jan 2022 03:02:17 PM CST
 ************************************************************************/

#include<stdio.h>

#if 0
#define MAX_N 100
int prime[MAX_N + 5] = {0};

void init()
{
    for(int i = 2; i < MAX_N; i++)
    {
        if(prime[i] == 0)
        {
            for(int j = 2 * i; j <= MAX_N; j += i)
            {
                prime[j] = 1;
            }
        }
    }

    //return ;
}

int main()
{
    init();
    for(int i = 2; i <= MAX_N; i++)
    {
        if(prime[i] == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
#else
#define MAX_N 100000
int prime[MAX_N + 5] = {0};

void init()
{
    for(int i = 2; i < MAX_N; i++)
    {
        if(prime[i]) continue;
        prime[++prime[0]] = i;
        for(int j = i; j <= MAX_N / i; j++)
        {
            prime[j * i] = 1;
        }
    }
}

int main()
{
    init();
#if 1
    printf("%d\n", prime[0]);
#else
    for(int i = 1; i <= prime[0]; i++)
    {
        printf("%d\n", prime[i]);
    }
#endif
    return 0;
}
#endif
