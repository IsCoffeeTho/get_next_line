/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:54:12 by amenadue          #+#    #+#             */
/*   Updated: 2021/09/28 10:17:46 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_safe(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!rtn)
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*save;
	int				reader;

	reader = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!has_return(save) && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[reader] = '\0';
		save = join_str(save, buff);
	}
	free(buff);
	save = get_safe(save);
	if (reader == 0)
		return (NULL);
	return (save);
}
