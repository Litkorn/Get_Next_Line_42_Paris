/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:22:38 by cleibeng          #+#    #+#             */
/*   Updated: 2022/04/30 17:49:28 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_split_end(char **buf, char **buf_gnl, int n)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (n + 1)));
		return (0);
	while (*buf[i] && *buf_gnl[i] && i < n)
	{
		*buf[i] = *buf_gnl[i];
		i++;
	}
	*buf[i] = '\0';
	*buf_gnl = ft_strdup(buf_gnl[i]); // <-  a verifier
	return (1);
}

char	*ft_return(char *buf_gnl)
{
	char	*buf;
	int		i;

	i = 0;
	if (ft_buf_read(buf_gnl) == 0)
		return(NULL);
	if (ft_buf_read(buf_gnl) == 1)
	{
		while (buf_gnl[i] != '\n')
			i++;
		if (buf_gnl[i + 1] != '\0')
			ft_split_end(&buf, &buf_gnl, (i));
		return (buf);
	}
// a completer pour == 2
}
int	ft_split_end(char **buf, char **buf_gnl, int n)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (n + 1)));
		return (0);
	while (*buf[i] && *buf_gnl[i] && i < n)
	{
		*buf[i] = *buf_gnl[i];
		i++;
	}
	*buf[i] = '\0';
	*buf_gnl = ft_strdup(buf_gnl[i]); // <-  a verifier
	return (1);
}

/* lit le buffer: si un \n -> renvoie 1, si pas de buf-> renvoie 0,
si pas de \n mais buf != \0 -> renvoie 2 */
int	ft_read_buf(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] || buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	if (!buf)
		return (0);
	return (2);
}

char	*get_next_line(int fd)
{
	static char	*buf_gnl;
	char		*bufread;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf_gnl)
		buf_gnl = NULL;
	else if (ft_read_buf(buf_gnl) > 0)
		return (ft_return(buf_gnl));
	if (!(bufread = malloc(sizeof(char) * (BUFFER_SIZE + 1))
		return (NULL);
	while (read(fd, bufread, BUFFER_SIZE) > 0)
	{
		bufread[BUFFER_SIZE + 1] = '\0';
		buf_gnl = ft_strjoin(buf_gnl, bufread);
	}
	ft_clean(bufread);
	if (buf_gnl != NULL)
		return (ft_return(buf_gnl));
	return (NULL);
}
