#include "../fractol.h"

void putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    if(!s || fd < 0 || s[i] == '\0')
        return ;
    while(s[i])
        write(fd,&s[i++],1);
}