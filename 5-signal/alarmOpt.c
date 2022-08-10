/*************************************************************************
	> File Name: alarmOpt.c
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Mar 2022 02:02:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

int main1()
{
    alarm(5);
    sleep(3);
    unsigned int left = alarm(5);
    printf("left = %d\n", left);

    while(1)
    {
        printf("sleep 1 sec\n");
        sleep(1);
    }

    return 0;
}

int main()
{
    alarm(5);
    sleep(3);
    unsigned int left = alarm(3);
    printf("left = %d\n", left);

    char i;
    //int i;
    for(i = 0; i > -1; i++)
    {
        //usleep(1000000);
        printf("i = %d\n", i);
    }
    printf("i = %d\n", i);

    return 0;
}
