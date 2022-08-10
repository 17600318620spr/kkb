/*************************************************************************
	> File Name: 7.struct_program.c
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Sep 2021 12:56:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //printf("%ld\n", time(0));
    //return 0;
    srand(time(0));
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int val = rand() % 100;
        i && printf(" ");
        printf("%d", val);
        //if(val % 2)
#if 0
        if(val & 1)
            cnt++;
#else
        cnt += (val & 1); //(val & 1) == 0 or 1
#endif
    }
    printf("\n");
    printf("cnt=%d\n", cnt);

    return 0;
}
