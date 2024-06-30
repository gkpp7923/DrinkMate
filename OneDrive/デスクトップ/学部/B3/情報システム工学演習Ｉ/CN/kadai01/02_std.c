// % gcc -ansi -Wall 02_std.c -o 02_std

#include "watalab.h"

#define BUFSIZE 1024

int main(int argc, char** argv)
{
    int ret;
    char buf[BUFSIZE];

    ret = read(0, buf, BUFSIZE);
    printf("read %d bytes\r\n", ret);

    ret = write(1, buf, ret);
    printf("write %d bytes\r\n", ret);

    return 0;
}
