/*************************************************************************
	> File Name: EP45.c
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Sep 2021 05:17:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int64_t Triangle(int64_t n)
{
    return n * (n + 1) / 2;
}

int64_t Pentagonal(int64_t n)
{
    return n * (3 * n - 1) / 2;
}

int64_t Hexagonal(int64_t n)
{
    return n * (2 * n - 1);
}

int binary_search(int64_t (*arr)(int64_t), int n, int x)
{
    int64_t head = 1, tail = n, mid;
    while(head <= tail)
    {
        mid = (head + tail) >> 1;
        if(mid < 0) printf("error\n");
        if(arr(mid) == x)
            return mid;
        if(arr(mid) < x)
            head = mid + 1;
        else
            tail = mid - 1;
    }

    return 0;
}

int main()
{
    int n = 143;
    while(1)
    {
        n++;
        int64_t temp = Hexagonal(n);
#if 0
        if(binary_search(Triangle, temp, temp) != 0)
        {
            if(binary_search(Pentagonal, temp, temp) != 0)
            {
                printf("%"PRId64"\n", temp);
                break;
            }
        }
#else
        //if(binary_search(Triangle, temp, temp) == 0)
        //    continue;
        if(binary_search(Pentagonal, temp, temp) == 0)
            continue;
        printf("%"PRId64"\n", temp);
        break;
#endif
    }

    return 0;
}
