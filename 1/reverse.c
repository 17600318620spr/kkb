/*************************************************************************
> File Name: reverse.c
> https://blog.csdn.net/aiwangtingyun/article/details/79568657?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-5.no_search_link&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-5.no_search_link
> Created Time: Sun 12 Sep 2021 09:08:22 PM CST
************************************************************************/

#include<stdio.h>
#include<string.h>

void reverseWords(char *str); // 单词逆转函数声明

int main(void)
{
    char str[100] = "hello world! this will be reverse!";//{0};
    //scanf("%s",str);

    fprintf(stdout, "src str: \n\t%s\n",str);
    fprintf(stdout, "after reverse: \n\t");
#if 0
    reverseWords(str);
#else
    char *ptrArr[100];
    char *ret;
    int idx = -1;

    ret = strtok(str, " ");
    while(ret != NULL)
    {
        idx++;
        ptrArr[idx] = ret;
        ret = strtok(NULL, " ");
    }

    while(idx >= 0)
    {
        fprintf(stdout, "%s ", ptrArr[idx]);
        idx--;
    }
    putchar('\n');
#endif

    return 0;
}

void reverseWords(char *str)
{
    char *ret;

    ret = strtok(str, " ");
    if(ret == NULL)
    {
        return ;
    }
    else
    {
        reverseWords(NULL);
    }

    fprintf(stdout, "%s ", ret);
}
