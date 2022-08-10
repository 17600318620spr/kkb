/*************************************************************************
	> File Name: elecdict.c
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Mar 2022 10:04:20 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
    char *word;
    char *trans;
    struct Node *next;
}Node;

Node *loadDict(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        perror("fopen");
        return NULL;
    }

    char buff[1024] = {0};
    Node *head = NULL;
    while(fgets(buff, sizeof(buff), fp))
    {
        Node *node = (Node *)malloc(sizeof(Node));

        node->word = (char *)malloc(sizeof(char) * strlen(buff));
        strcpy(node->word, buff + 1); //不拷贝#
        //printf("strlen(node->word)=%d\n", strlen(node->word));
        //printf("node->word=%s\n", node->word);
        node->word[strlen(node->word) - 1] = '\0';

        fgets(buff, sizeof(buff), fp);
        node->trans = (char *)malloc(sizeof(char) * (strlen(buff) - 5));
        strcpy(node->trans, buff + 6); //不拷贝#
        node->trans[strlen(node->trans) - 1] = '\0';

        node->next = head;
        head = node;
    //printf(">>>>>>>>>>>3>>>>>>>>>>>>>\n");
    }

    fclose(fp);
    return head;
}

void test(Node *head)
{
    int cnt = 1;
    while(head && cnt <= 100)
    {
        printf("cnt = [%d] word = [%s] trans = [%s]\n", cnt++, head->word, head->trans);
        head = head->next;
    }
}

Node *findNode(Node *head, char *word)
{
    while(head && strcmp(word, head->word))
    {
        head = head->next;
    }

    return head;
}
void splitTrans(char *trans)
{
    printf("翻译：\n");
    char *buff = (char *)malloc(sizeof(char) * (strlen(trans) + 1));
    strcpy(buff, trans);
    char *token = strtok(buff, "@");
    while(token)
    {
        printf("%s\n", token);
        token = strtok(NULL, "@");
    }

    free(buff);
    return ;
}
void findWord(Node *head)
{
    char inputword[20] = {0};
    while(1)
    {
        printf("please input a word:");
        scanf("%s", inputword);
        if(!strcmp(inputword, "q!"))
        {
            break;
        }
        else
        {
            Node *fd = findNode(head, inputword);
            if(fd)
            {
                //printf("翻译：%s\n", fd->trans);
                splitTrans(fd->trans);
            }
            else
            {
                printf("没有找到！\n");
            }
        }
    }
    printf("再见！\n");
}

void freeDict(Node *head)
{
    Node *temp;
    while(head)
    {
        temp = head;
        head = head->next;
        free(temp->word);
        free(temp->trans);
        free(temp);
    }

    return ;
}

int main()
{
    //把词典文件加载到内存
    Node *node;
    char filename[50] = "dict.txt";
    printf(">>>>>>>>1>>>>>>>>\n");
    node = loadDict(filename);
    printf(">>>>>>>>2>>>>>>>>\n");
    if(NULL == node)
    {
        perror("loadDict");
    }
    //test(node);

    //启动词典，支持反复查询
    findWord(node);

    //释放内存，关闭词典
    freeDict(node);

    return 0;
}
