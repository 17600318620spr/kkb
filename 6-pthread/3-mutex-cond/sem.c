/*************************************************************************
	> File Name: sem.c
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Mar 2022 08:29:16 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include<semaphore.h>

#define NUM 5

int q[NUM];
sem_t blank_number, goods_number;

void *producer(void *arg)
{
    int i = 0;
    while(1)
    { //减少1个空位，多了1个商品
        sem_wait(&blank_number);
        q[i] = rand() % 100 + 1;
        printf("produce %d\n", q[i]);
        sem_post(&goods_number);
        i = (i + 1) % NUM;
        sleep(rand() % 3);
    }
}

void *consumer(void *arg)
{
    int i = 0;
    while(1)
    { //减少1个商品，多了1个空位
        sem_wait(&goods_number);
        printf("consume %d\n", q[i]);
        q[i] = 0;
        sem_post(&blank_number);
        i = (i + 1) % NUM;
        sleep(rand() % 3);
    }
}

int main()
{
    srand(time(NULL));

    sem_init(&blank_number, 0, NUM);
    sem_init(&goods_number, 0, 0);

    pthread_t pid, cid;
    
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    return 0;
}
