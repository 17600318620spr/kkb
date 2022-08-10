/*************************************************************************
	> File Name: fileopt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Feb 2022 08:19:31 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("usage:cmd + filename\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(!fp) //0
    {
        perror("open file");
        return 1;
    }

    char c;
    while(~(c = fgetc(fp))) //-1
    {
        printf("%c", c);
    }

#if 0
    while((c = fgetc(fp)) != EOF)
    {
        printf("%c\n", c);
        //printf("123\n");
    }
//#else
    while(c = fgetc(fp) != EOF)
    {
        printf("%c\n", c);
        printf("%d\n", c);
    }
#endif

    fclose(fp);
    return 0;
}
