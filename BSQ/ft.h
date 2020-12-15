#ifndef FT_H
#define FT_H

typedef struct s_list
{
  int ln_count;
  char empty_char;
  char obs_char;
  char fillin_char;
  char **tab;
} t_list;

t_list *verify_map(t_list *map);
t_list *read_file(char *argv);
int	ft_strlen(char *str);


#endif


