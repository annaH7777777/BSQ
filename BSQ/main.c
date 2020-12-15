
#include <stdio.h>
#include "ft.h"

int main(int argc, char **argv)
{
    int i = 1;
    if(argc > 1)
    {
        while(i < argc)
        {
            t_list *map;
            if(map = verify_map(read_file(argv[i])))
            {
                found_solution(map);
                ft_putchar('\n');
            }
            ft_putstr("map error\n");
            i++;
        }
    }
    ft_putchar('\n');
    return 0;
}
