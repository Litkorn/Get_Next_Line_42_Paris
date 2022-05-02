/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:22:38 by cleibeng          #+#    #+#             */
/*   Updated: 2022/05/02 17:30:19 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_split_end(char **buf, char **buf_static, int n)
{
	int		i;

	i = 0;
	buf = malloc(sizeof(char) * (n + 1));
	if (!buf)
		return (0);
	while (*buf[i] && *buf_static[i] && i < n)
	{
		*buf[i] = *buf_static[i];
		i++;
	}
	*buf[i] = '\0';
	*buf_static = ft_strdup(buf_static[i]);
	return (1);
}

/* lit le buffer: si un \n -> renvoie 1, si pas de buf-> renvoie 0,
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

static char	*ft_return(char *buf_static)
{
	char	*buf;
	int		i;

	i = 0;
	buf = NULL;
	if (ft_buf_read(buf_static) == 0)
		return (NULL);
	if (ft_buf_read(buf_static) == 1)
	{
		while (buf_static[i] != '\n')
			i++;
		if (buf_static[i + 1] != '\0')
			ft_split_end(&buf, &buf_static, (i));
		return (buf);
	}
	buf = ft_strdup(buf_static);
	return (ft_clean(buf_static), buf);
}

char	*get_next_line(int fd)
{
	static char	*buf_static;
	char		*bufread;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf_static)
		buf_static = NULL;
	else if (ft_buf_read(buf_static) > 0)
		return (ft_return(buf_static));
	bufread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bufread)
		return (NULL);
	while (read(fd, bufread, BUFFER_SIZE) > 0)
	{
		printf("ok");
		bufread[BUFFER_SIZE + 1] = '\0';
		buf_static = ft_strjoin(buf_static, bufread);
	}
	ft_clean(bufread);
	if (buf_static != NULL)
		return (ft_return(buf_static));
	return (NULL);
}

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char *str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
