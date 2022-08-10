/*************************************************************************
	> File Name: exitThread.c
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Mar 2022 04:11:32 PM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>

void *thr_fn1(void *arg)
{
    printf("thread 1 returning\n");
    return (void *)1;
}
void *thr_fn2(void *arg)
{
    printf("thread 2 exiting\n");
    pthread_exit((void *)2);
    return NULL;
}
void *thr_fn3(void *arg)
{
    while(1)
    {
        printf("thread 3 sleeping\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    void *sts;

    pthread_create(&tid, NULL, thr_fn1, NULL);
    pthread_join(tid, &sts);
    printf("thread 1 exit code %ld\n", (long)sts);

    pthread_create(&tid, NULL, thr_fn2, NULL);
    pthread_join(tid, &sts);
    printf("thread 2 exit code %ld\n", (long)sts);

    pthread_create(&tid, NULL, thr_fn3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &sts);
    printf("thread 3 exit code %ld\n", (long)sts);

    return 0;
}
