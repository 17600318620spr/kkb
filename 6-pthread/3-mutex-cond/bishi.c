/*************************************************************************
	> File Name: bishi.c
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Mar 2022 01:50:57 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

int n = 0;
pthread_mutex_t Idlock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;

void *thread_handler(void *arg)
{
    //int n = 0; //error!!!
    int param = (int)arg;
    char ch = 'A' + param;
    for(int i = 0; i < 10; i++)
    {
//printf(">>>>>>>>>1>>>>>>>>>\n");
        pthread_mutex_lock(&Idlock);
        //if(param != n) //error!!!
        while(param != n)
            pthread_cond_wait(&qready, &Idlock);
        printf("%c", ch);
        n = (n + 1) % 3;
        pthread_mutex_unlock(&Idlock);
        pthread_cond_broadcast(&qready);
    }
}

int main()
{
    pthread_t tid[3];
    int err;
    void *tret;
    for(int i = 0; i < 3; i++)
    {
        err = pthread_create(&tid[i], NULL, thread_handler, (void *)i);
        if(err != 0)
        {
            printf("thread create error:%s\n", strerror(err));
            exit(-1);
        }
    }

    for(int i = 0; i < 3; i++)
    {
        err = pthread_join(tid[i], &tret);
        if(err != 0)
        {
            printf("cannot join with thread %d:%s\n", i, strerror(err));
            exit(-1);
        }
    }

    putchar(10);
    return 0;
}
