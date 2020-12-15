#include <unistd.h>
#include <fcntl.h>
#include "ft.h"

t_list *read_file(char *argv) //reading map parameters 
{
    int i;
    int j;
    char *buf;
    int fd;
    int sum;
    t_list *map;
    
    i = 0;
    j = 0;
    sum = 0;
    if((fd = open(argv, O_RDONLY)) != -1)
    {
        if(!(buf = malloc(sizeof(char)*80)))
        {
            exit(1);
        }
        while(read(fd, &buf[i], 1))
        {
            if(buf[i] == '\n')
                break;
            i++;
        }
        (*map).fillin_char = buf[i-1];
        (*map).obs_char = buf[i-2];
        (*map).empty_char = buf[i-3];
        int k;
        k = 0;
        while(k < j - 3)
        {
            if(buf[k] >= '0' && buf[k] <= '9')
                sum = sum * 10 + buf[k] - '0';
            else
                exit(1);
            k++;
        }
        (*map).ln_count = sum;
        if(!((*map).tab = malloc(sizeof(char)*(*map).ln_count)))
        while(argv)
        {
            if(!((*map).tab[j] = malloc(sizeof(char)*4096)))
            {
                read(fd, &(*map).tab[j][i], 1);
                i++;
                if((*map).tab[j][i] == '\n')
                {
                    j++;
                    i = 0;
                }
            }
        }
        close(fd);
        return (map);
    }
    else
        exit(1);
}


t_list *verify_map(t_list *map)
{
    if(verify_line_length(map) && verify_chars(map) && verify_first_line(map))
        return map;
    exit(1);
}
int verify_line_length(t_list *map)
{
    int i;
    int j;
    i = 0;
    j = 0;
    int *ft_;
    while((*map).tab[j])
    {
        j++;
    }
    if(map.ln_count != j)
        return (0);
    while(j-2 >= 0)
    {
        if((ft_strlen(map.tab[j-1]) != ft_strlen(map.tab[j-2]) || ft_strlen(map.tab[j-1]) == 0))
            return (0);
        j--;
    }
    return (1);
}
int verify_chars(t_list *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while((*map).tab[j])
    {
        while(map.tab[j][i])
        {
            if(!(map.tab[j][i] == map.empty_char || map.tab[j][i] == map.fillin_char || map.tab[j][i] == map.obs_char))
                return (0);
            i++;
        }   
        j++;  
    }
    return (1);
}
int verify_first_line(t_list *map)
{
    if((*map).empty_char == '\0' || (*map).fillin_char == '\0' || (*map).obs_char == '\0' || (*map).empty_char == (*map).fillin_char || (*map).empty_char == (*map).obs_char || (*map).fillin_char == (*map).obs_char)
        return (0);
}

int secont_line(char *argv) //finding second line index
{
    int i;
    int j;
    char *buf;
    int fd;
    
    i = 0;
    j = 0;
    if(fd = open(argv, O_RDONLY) != 1)
    {
        if(!(buf = malloc(sizeof(char)*80)))
        {
            return (0);
        }
        while(read(fd, &buf[i], 1))
        {
            if(buf[i] == '\n')
                break;
            i++;
        }
        free(buf);
        close(fd);
        return (i);
    }
    return (0);
}