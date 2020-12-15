
#include <stdio.h>
#include "ft.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    
    int i = 1;
    if(argc > 1)
    {
        while(i <= argc)
        {
            
            t_list *map;
            printf("main");
            //map = malloc(sizeof(t_list));
            //read_file(argv[i]);
            if(!(map = verify_map(read_file(argv[i]))))
            {
                printf("main2");
                find_solution(verify_map(read_file(argv[i])));
                ft_putchar('\n');
            }
            else
                ft_putstr("map error\n");
            i++;
        }
    }
    ft_putchar('\n');
    return 0;
}
