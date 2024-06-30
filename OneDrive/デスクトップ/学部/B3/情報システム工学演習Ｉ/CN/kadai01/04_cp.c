//% gcc -ansi -Wall 04_cp.c -o 04_cp

#include "watalab.h"

#define BUFSIZE 1024

int main(int argc, char** argv)
{
    int ret;
    int rfd, wfd;
    char buf[BUFSIZE];

    if(argc != 3) {
        printf("usage: %s [from filename] [to filename]\r\n", argv[0]);
        return -1;
    }

    rfd = open(argv[1], O_RDONLY);
    wfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);

    ret = read(rfd, buf, BUFSIZE);
    while(ret > 0) {
        printf("read %d bytes\r\n", ret);
        write(wfd, buf, ret);
        ret = read(rfd, buf, BUFSIZE);
    }

    close(wfd);
    close(rfd);

    return 0;
}
