/*************************************************************************
	> File Name: myls.c
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Mar 2022 03:21:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>

void ls_la(char *dpath)
{
    DIR *dir = opendir(dpath);
    if(dir == NULL)
    {
        perror("opendir");
        closedir(dir);
        exit(1);
    }

    struct dirent *dirent;
    struct stat statbuf;
    while((dirent = readdir(dir)) != NULL)
    {
        stat(dirent->d_name, &statbuf);
        char mode = '-';
        switch(statbuf.st_mode & S_IFSOCK)
        {
            case S_IFSOCK:
                mode = 's';
                break;
            case S_IFLNK:
                mode = 'l';
                break;
            case S_IFREG:
                mode = '-';
                break;
            case S_IFDIR:
                mode = 'd';
                break;
            case S_IFIFO:
                mode = 'p';
                break;
            case S_IFCHR:
                mode = 'c';
                break;
            case S_IFBLK:
                mode = 'b';
                break;
            default:
                mode = 'u';
                break;
        }
        char permission[10] = "---------\0";
        permission[0] = statbuf.st_mode & S_IRUSR ? 'r' : '-';
        permission[1] = statbuf.st_mode & S_IWUSR ? 'w' : '-';
        permission[2] = statbuf.st_mode & S_IXUSR ? 'x' : '-';
        permission[3] = statbuf.st_mode & S_IRGRP ? 'r' : '-';
        permission[4] = statbuf.st_mode & S_IWGRP ? 'w' : '-';
        permission[5] = statbuf.st_mode & S_IXGRP ? 'x' : '-';
        permission[6] = statbuf.st_mode & S_IROTH ? 'r' : '-';
        permission[7] = statbuf.st_mode & S_IWOTH ? 'w' : '-';
        permission[8] = statbuf.st_mode & S_IXOTH ? 'x' : '-';

        struct tm *time = localtime(&statbuf.st_ctime);
        struct passwd *pwd = getpwuid(statbuf.st_uid);
        struct group *grp = getgrgid(statbuf.st_gid);

        printf("%c%s %ld %s %s %7ld %d:%02d %s\n", 
               mode,
               permission,
               statbuf.st_nlink,
               pwd->pw_name,
               grp->gr_name,
               statbuf.st_size,
               time->tm_hour,
               time->tm_min,
               dirent->d_name);
    }

    closedir(dir);
    return ;
}

int main(int argc, char **argv)
{
    // ./myls dpath
    char *dpath = NULL;
    if(argc == 1)
    {
        dpath = ".";
    }
    else if(argc == 2)
    {
        dpath = argv[1];
    }
    else
    {
        fprintf(stderr, "Usage:%s dpath\n", argv[0]);
        exit(1);
    }

    ls_la(dpath);

    return 0;
}
