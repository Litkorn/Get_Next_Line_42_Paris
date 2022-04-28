/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:22:38 by cleibeng          #+#    #+#             */
/*   Updated: 2022/04/28 14:29:16 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*buf_gnl;
	char		*bufread;
	char		*buf2;

	if ( fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf_gnl)
		buf_gnl = ft_malloc();
	if (read_buf(buf_gnl) == 1)
		return (ft_return(buf_gnl,buf2));
	bufread = ft_malloc();
	while (read_buf(buf_gnl) != 1)
	{
		read(fd, bufread, BUFFER_SIZE);
		ft_strjoin(buf_gnl, bufread);
	}
	ft_clean(bufread);
	if (buf2)
		return (ft_return(buf2));
	return(NULL);
}



/*
int	main()
{
	printf("%s", get_next_line(-1));
	printf("%s", get_next_line(1022));
	return (1);
}
*/
