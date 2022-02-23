/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:12:10 by amenadue          #+#    #+#             */
/*   Updated: 2022/02/24 10:07:44 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

char	*get_next_line(int fd);
int		has_return(char *str);
size_t	ft_strlen(const char *s);
char	*join_str(const char *s1, const char *s2);

#endif
