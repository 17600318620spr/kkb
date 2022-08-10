/*************************************************************************
	> File Name: envOpt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Feb 2022 01:29:09 PM CST
 ************************************************************************/

#include<stdio.h>

int main()
{
    extern char **environ;

    for(int i = 0; environ[i]; i++)
    {
        printf("%s\n", environ[i]);
    }

    return 0;
}
