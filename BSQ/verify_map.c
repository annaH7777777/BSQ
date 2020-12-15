#include <unistd.h>
#include <fcntl.h>
#include "ft.h"
#include <stdlib.h>
#include <stdio.h>

t_list *read_file(char *argv) //reading map parameters 
{
    int t;
    int i;
    int j;
    char *buf;
    int fd;
    int sum;
    t_list *map;
    
    t = 0;
    i = 0;
    j = 0;
    sum = 0;
    if(((fd = open(argv, O_RDONLY)) == -1) || !(map = malloc(sizeof(t_list))))
    {
        printf("exit");
        exit(1);
    }
    if(!(buf = malloc(sizeof(char)*4096)))
        exit(1);
    while(read(fd, &buf[t], 1))
    {
        if(buf[t] == '\n')
            break;
        t++;
    }
    (*map).fillin_char = buf[t-1]; //changes
    (*map).obs_char = buf[t-2];
    (*map).empty_char = buf[t-3];
    int k;
    k = 0;
    while(k < t - 3)
    {
        if(buf[k] >= '0' && buf[k] <= '9')
            sum = sum * 10 + buf[k] - '0';
        else
            exit(1);
        k++;
    }
    (*map).ln_count = sum;
    if(!((*map).tab = malloc(sizeof(char*)*(*map).ln_count)))
        exit(1);
    while(read(fd, &buf[t], 1))
    {
        if(!((*map).tab[j] = malloc(sizeof(char)*4096)))
            exit(1); 
        (*map).tab[i][j] = buf[t];
        t++;
        j++;
        if((*map).tab[i][j] == '\n')
        {
            i++;
            (*map).ln_length = j;
            j = 0;
        }
    }
    free(buf); //maybe wrong
    close(fd);
    return (map);
}



int verify_line_length(t_list *map)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while((*map).tab[j])
    {
        j++;
    }
    if((*map).ln_count != j)
        return (0);
    while(j-2 >= 0)
    {
        if((ft_strlen((*map).tab[j-1]) != ft_strlen((*map).tab[j-2]) || ft_strlen((*map).tab[j-1]) == 0))
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
        while((*map).tab[j][i])
        {
            if(!((*map).tab[j][i] == (*map).empty_char || (*map).tab[j][i] == (*map).fillin_char || (*map).tab[j][i] == (*map).obs_char))
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
    return(1);
}


t_list *verify_map(t_list *map)
{
    if(verify_line_length(map) && verify_chars(map) && verify_first_line(map))
        return map;
    else
        return 0;
    
}