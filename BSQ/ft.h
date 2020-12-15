#ifndef FT_H
#define FT_H

typedef struct s_list
{
  int ln_count;
  int ln_length;
  char empty_char;
  char obs_char;
  char fillin_char;
  char **tab;
} t_list;

typedef struct n_list
{
  int i;
  int j;
  int size;
  
} k_list;

t_list *verify_map(t_list *map);
t_list *read_file(char *argv);
int	ft_strlen(char *str);
void find_solution(t_list *map);
void ft_putchar(char c);
void ft_putstr(char *str);


#endif


