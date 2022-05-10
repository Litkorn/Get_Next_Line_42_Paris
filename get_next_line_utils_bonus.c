/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils _utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:22:34 by cleibeng          #+#    #+#             */
/*   Updated: 2022/05/10 17:16:27 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	void	*str2;
	size_t	nb;

	nb = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (nb < count * size)
	{
		str[nb] = '\0';
		nb++;
	}
	str2 = (void *) str;
	return (str2);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strjoin(char *str_static, const char *bufread, int k)
{
	char	*str3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str3 = malloc(sizeof(char)
			* (ft_strlen(str_static) + ft_strlen(bufread) + 1));
	if (!str3)
		return (ft_clean(&str3));
	while (str_static[i])
	{
		str3[i] = str_static[i];
		i++;
	}
	while (bufread[j] && j < k)
	{
		str3[i + j] = bufread[j];
		j++;
	}
	str3[i + j] = '\0';
	free(str_static);
	return (str3);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		n;
	char	*s2;

	i = 0;
	n = ft_strlen(s1) + 1;
	s2 = malloc(n * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_clean(char **str)
{
	free(*str);
	(*str) = NULL;
	return (NULL);
}
