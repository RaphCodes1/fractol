#include "../fractol.h"

int ft_strncmp(char *s1, char *s2, int len)
{
    int i;

    i = 0;
    if(!s1 || !s2 || len <= 0)
        return (0);
    while(s1[i] == s2[i] && s1[i] != '\0' && i < (len - 1))
        i++;
    return (s1[i] - s2[i]);
}