/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:22:34 by cleibeng          #+#    #+#             */
/*   Updated: 2022/04/28 14:29:17 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strjoin(char *str1, const char *str2)
{
	size_t	len;
	char	*str3;
	int		i;
	int		j;

	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	i = 0;
	j = 0;
	str3 = malloc(sizeof(char) * len);
	if (!str3)
		return (NULL);
	while (str1[i])
	{
		str3[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str3[i + j] = str2[j];
		j++;
	}
	str3[i + j] = '\0';
	return (str3);
}

char	*ft_split_end(char *str, int n)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = malloc(sizeof(char) * (n + 1));
	if (!str2)
		return (NULL);
	while (i <= n)
	{
		str2[i] = str[i];
		i++;
	}
	free(str);
	str = NULL;
	return (str2);
}

void	ft_clean(char *str)
{
	free(str);
	str = NULL;
}
