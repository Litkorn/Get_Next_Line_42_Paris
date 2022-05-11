/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:22:38 by cleibeng          #+#    #+#             */
/*   Updated: 2022/05/11 15:15:26 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_cut_end(char **buf, char **buf_static, int n)
{
	int		i;

	i = 0;
	(*buf) = malloc(sizeof(char) * (n + 2));
	if (!(*buf))
		return (0);
	while (i <= n && *buf_static)
	{
		(*buf)[i] = (*buf_static)[i];
		i++;
	}
	(*buf)[i] = '\0';
	return (n + 1);
}

/* lit le buffer: si un \n -> renvoie 1,
	si pas de \n mais buf != \0 -> renvoie 2 */
static int	ft_buf_read(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (2);
}

static char	*ft_return(char **buf_static)
{
	char	*buf;
	char	*temp;
	int		i;

	i = 0;
	buf = NULL;
	if (ft_buf_read(*buf_static) == 1)
	{
		while ((*buf_static)[i] != '\n')
			i++;
		if ((*buf_static)[i + 1] != '\0')
		{
			i = ft_cut_end(&buf, buf_static, (i));
			temp = *buf_static;
			*buf_static = ft_strdup(&(*buf_static)[i]);
			free(temp);
			return (buf);
		}
	}
	buf = ft_strdup(*buf_static);
	ft_clean(buf_static);
	if (*buf == '\0')
		ft_clean(&buf);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf_static[1024];
	char		*bufread;
	int			i;

	i = BUFFER_SIZE;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf_static[fd])
		buf_static[fd] = ft_strdup("\0");
	if (ft_buf_read(buf_static[fd]) == 1)
		return (ft_return(&buf_static[fd]));
	bufread = ft_calloc(sizeof(char), (size_t)(BUFFER_SIZE + 1));
	if (!bufread)
		return (NULL);
	while (i == BUFFER_SIZE && ft_buf_read(bufread) != 1)
	{
		i = read(fd, bufread, BUFFER_SIZE);
		buf_static[fd] = ft_strjoin(buf_static[fd], bufread, i);
		if (i != -1)
			bufread[i] = '\0';
	}
	ft_clean(&bufread);
	return (ft_return(&buf_static[fd]));
}
/*
int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char *str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("new line %s", str);
		free(str);
		str = get_next_line(fd);
	}
	printf("%s", str);
	free(str);
	close(fd);
	return (0);
}*/
