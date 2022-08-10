/*************************************************************************
	> File Name: mmap.c
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Feb 2022 03:56:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main()
{
    int fd = open("test.txt", O_RDWR);
    if(fd < 0)
    {
        perror("open file");
        exit(1);
    }

    int *p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    p[0] = 0x30313233;
    munmap(p, 6);

    return 0;
}
