/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:23:04 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/27 14:49:57 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../src/cub3d.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_putstr(char *s);
void				ft_bzero(void *s, size_t n);

char				*ft_strdup(const char *s);
char				*ft_strjoin2(char *buff, char *temp);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);

int					get_next_line(int fd, char **line);
int					ft_strlen(const char *s);
int					is_space(char c);
int					char_to_deci(char *s, int idx);
int					ft_isdigit(char c);
int					ft_isprint(char c);
int					word_size(char *s, int idx);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_lstsize(t_list *lst);

#endif
