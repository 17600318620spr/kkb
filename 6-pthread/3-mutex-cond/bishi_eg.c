#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h>   
#include <unistd.h>  
#include <string.h>    

#define NUM 3  

int n=0; 
pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER;   //互斥锁
pthread_cond_t qready=PTHREAD_COND_INITIALIZER;     //条件变量 


void *thread_func(void *arg) 
{
    int param=(int)arg; 
    char c='A'+param; 
    int ret,i=0; 
    for (; i < 10; i++) 
    {
        pthread_mutex_lock(&mylock); 
        while (param != n)                  //刚运行时，n = 0，param = 0,条件不成立，所以直接打印A；然后是B和C
        {  
            ret = pthread_cond_wait(&qready, &mylock); 
        } 

        printf("%c ",c);                    //打印A、B、C 
        n=(n+1)%NUM;                        //n变成了1、然后是2、3、4
        pthread_mutex_unlock(&mylock);  
        pthread_cond_broadcast(&qready); 
    }     
    return (void *)0; 
} 

int main(int argc, char** argv) 
{
    int i;
    int err; 
    pthread_t tid[NUM]; 
    void *tret; 
    for(i = 0 ; i < NUM; i++) 
    {
        err=pthread_create(&tid[i],NULL,thread_func,(void *)i); 
        if(err != 0) 
        {
            printf("thread_create error:%s\n",strerror(err)); 
            exit(-1); 
        } 
    } 
    for (i = 0; i < NUM; i++) 
    {
        err = pthread_join(tid[i], &tret); 
        if (err != 0) 
        {
            printf("can not join with thread %d:%s\n", i,strerror(err)); 
            exit(-1); 
        } 
    } 
    printf("\n"); 
    return 0; 
} 
