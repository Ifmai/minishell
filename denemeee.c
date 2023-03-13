#include "includes/ifmai.h"

int main()
{
    int fd;
    fd = open("burcak",O_RDONLY);
    printf("%d",read(fd,NULL,12));
}