#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *ft_space(char *str)
{
    int i = 0;
    char *new_str;
    int j = 0;
    int len = strlen(str);
    new_str = malloc(sizeof(char) * 10);
    while(i < (10 - len))
    {
        new_str[i] = ' ';
        i++;
    }
    while(i < 10)
    {
        new_str[i] = str[j];
        i++;
        j++;
    }
    return new_str;
}




int main()
{
    int i = 0;
    char *str;
    str = ft_space("yousra");
    printf("%s\n", str);
}