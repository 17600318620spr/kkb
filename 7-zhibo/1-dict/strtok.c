/*************************************************************************
	> File Name: strtok.c
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Mar 2022 02:16:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main()
{
    char buff[1024] = {0};
    scanf("%s", buff); //1@12@123@1234
    printf("%s\n", strtok(buff, "@"));

    char *token;
    while(token = strtok(NULL, "@"))
    {
        printf("%s\n", token);
    }

    return 0;
}

int main1()
{
    char a[1024] = {0};
    strcpy(a, "world");
    printf("%s\n", a);

    return 0;
}
