//dup2函数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd1 = open(argv[1], O_RDWR|O_CREAT, 0644);   // 3
    if(fd1 < 0)
    {
        perror("open error");
        exit(1);
    }

    int fd2 = open(argv[2], O_RDWR|O_CREAT, 0644);   // 4
    if(fd2 < 0)
    {
        perror("open error");
        exit(1);
    }

    int newfd = dup2(fd1, fd2);                 // 返回 新文件描述符fd2
    printf("newfd = %d\n", newfd);

    int ret = write(fd2, "1234567", 7);         // 写入fd1指向的文件
    printf("ret = %d\n", ret);

    dup2(fd1, STDOUT_FILENO);                   // 将屏幕输入重定向给fd1所指向的文件
    printf("-------------------\n");

    close(fd1);
    close(newfd);
    return 0;
}