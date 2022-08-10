/*************************************************************************
	> File Name: 17.array.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jan 2022 10:29:27 AM CST
 ************************************************************************/

#include<stdio.h>

#if 0
void func(int *p)
{
    printf("func: ");
    p[0] = 1;

    return ;
}

int main()
{
    int arr[100] = {0};
    func(arr);
    printf("arr[0]=%d\n", arr[0]);

    return 0;
}
#else
void func(int (*p)[4])
{
    printf("func: ");
    printf("p=%p, p+1=%p\n", p, p+1);
}

int main()
{
    int arr[100][4] = {0};
    printf("arr=%p, &arr[0]=%p\n", arr, &arr[0]);
    printf("arr+1=%p\n", arr+1);
    func(arr);

    return 0;
}
#endif
