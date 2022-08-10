/*************************************************************************
	> File Name: popenOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Feb 2022 04:13:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    FILE *fp = popen("cat ./hello.txt", "r");
    if(!fp)
    {
        perror("popen");
        exit(1);
    }

    int c;
    while(~(c = fgetc(fp)))
    {
        putchar(toupper(c));
    }

    fclose(fp);
    return 0;
}

int main1()
{
    FILE *fp = popen("./upper", "w");
    if(!fp)
    {
        perror("popen");
        exit(1);
    }

    fprintf(fp, "hello world 3 \n ttt goood attt\n");

    fclose(fp);
    return 0;
}
