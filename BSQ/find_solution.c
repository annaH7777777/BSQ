#include "ft.h"
#include <stdlib.h>


int min(int a, int b, int c)
{
    int min;
    
    min = 0;
    if (a <= b && a <= c)
        min = a;
    else if (b <= c && b <= a)
        min = b;
    else
        min = c;
    return (min);
}

int **int_matrix(t_list *map)
{
    int i;
    int j;
    int **matrix;
    
    i = 0;
    j = 0;
    matrix = malloc(sizeof(int*)*(*map).ln_count);
    while(i < (*map).ln_count)
    {
        matrix[i] = malloc(sizeof(int)*(*map).ln_length);
        ++i;
    }
    i = 0;
    while(i < (*map).ln_count)
    {
        while(j < (*map).ln_length)
        {
            if ((*map).tab[i][j] == (*map).obs_char) 
                matrix[i][j] = 0;
            else if ((*map).tab[i][j] == (*map).empty_char) 
                matrix[i][j] = 1;
            ++j;
        }
        ++i;
    }
    return (matrix);
}

int **count_solution(t_list *map)
{
    int i;
    int j;
    int **s_matrix;
    int **matrix;
    
    i = 0;
    j = 0;
    matrix = int_matrix(map);
    s_matrix = malloc(sizeof(int*)*(*map).ln_count);
    while(i < (*map).ln_count)
    {
        s_matrix[i] = malloc(sizeof(int)*(*map).ln_length);
        ++i;
    }
    i = 0;
    while(i < (*map).ln_count)
    {
        while(j < (*map).ln_length)
        {
            if(i == 0 || j == 0 || matrix[i][j] == 0)
                s_matrix[i][j] = matrix[i][j];
            else 
                s_matrix[i][j] = min(s_matrix[i][j-1], s_matrix[i-1][j], s_matrix[i-1][j-1]) + matrix[i][j];
            ++j;
        }
        ++i;
    }
    return s_matrix;
}
k_list *find_max(t_list *map)
{
    k_list *maxvalues;
    int i;
    int j;
    int **s_matrix;

    i = 0;
    j = 0;
    s_matrix = count_solution(map);
    maxvalues = malloc(sizeof(k_list));
    (*maxvalues).size = s_matrix[i][j];
    while(i < (*map).ln_count)
    {
        while(j < (*map).ln_length)
        {
            if(s_matrix[i][j] > (*maxvalues).size)
            {
                (*maxvalues).size = s_matrix[i][j];
                (*maxvalues).i = i;
                (*maxvalues).j = j; 
            }
            ++j;
        }
        ++i;
    }
    return maxvalues;
}
void find_solution(t_list *map)
{
    int i;
    int j;
    k_list *maxvalues;

    i = 0;
    j = 0;
    maxvalues = find_max(map);
    while(i < (*map).ln_count)
    {
        while(j < (*map).ln_length)
        {
            if(i > (maxvalues->i - maxvalues->size) && i < (maxvalues->i + 1) && j > (maxvalues->j - maxvalues->size) && j < (maxvalues->j + 1))
            {
                ft_putchar(map->fillin_char);
            }
            else 
                ft_putchar(map->tab[i][j]);
            ++j;
        }
    }
}
