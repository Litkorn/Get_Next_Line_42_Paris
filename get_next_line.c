/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:22:38 by cleibeng          #+#    #+#             */
/*   Updated: 2022/05/09 15:42:34 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_cut_end(char **buf, char **buf_static, int n)
{
	int		i;

	i = 0;
	printf("%d", n);
	(*buf) = malloc(sizeof(char) * (n + 1));
	if (!buf)
		return (0);
	while (i != n && *buf_static)
	{
		(*buf)[i] = (*buf_static)[i];
		printf("buf = %s & buf_static = %s et n = %d\n", *buf, *buf_static, n);
		i++;
	}
	(*buf)[i] = '\0';
	(*buf_static) = ft_strdup(buf_static[i]);
	return (i);
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
	if (!buf_static)
		return (NULL);
	if (ft_buf_read(buf_static) == 1)
	{
		while (buf_static[i] != '\n')
			i++;
		if (buf_static[i + 1] != '\0')
			ft_cut_end(&buf, &buf_static, (i));
		return (buf);
	}
	ft_clean(buf_static);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf_static;
	char		*bufread;
	int			i;

	i = 1;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf_static)
		buf_static = "\0";
	else
		return (ft_return(buf_static));
	bufread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bufread)
		return (NULL);
	// peut faire une fonction pour le while a part
	while (i > 0 && ft_buf_read(bufread) != 1)
	{
		i = read(fd, bufread, BUFFER_SIZE);
		buf_static = ft_strjoin(buf_static, bufread, i);
		bufread[i] = '\0';
		if (i != BUFFER_SIZE)
			i = 0;
	}
	ft_clean(bufread);
	printf("buf_static gnl = %s\n", buf_static);
	if (ft_buf_read(buf_static) == 1)
		return (ft_return(buf_static));
	return (NULL);
}

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char *str;

	str = get_next_line(fd);
	/*while (str != NULL)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}*/
	printf("%s", str);
	close(fd);
	return (0);
}
