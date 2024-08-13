/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:30:53 by akalican          #+#    #+#             */
/*   Updated: 2024/06/04 18:14:40 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

size_t	ft_strlen_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_chr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen_len(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_join(char *lft_str, char *buff)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!lft_str)
	{
		lft_str = (char *)malloc(1 * sizeof(char));
		lft_str[0] = '\0';
		if (!lft_str || !buff)
			return (NULL);
	}
	res = malloc(sizeof(char) * ((ft_strlen_len(lft_str)
					+ ft_strlen_len(buff) + 1)));
	if (res == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (lft_str)
		while (lft_str[++i] != '\0')
			res[i] = lft_str[i];
	while (buff[j] != '\0')
			res[i++] = buff[j++];
	res[ft_strlen_len(lft_str) + ft_strlen_len(buff)] = '\0';
	free(lft_str);
	return (res);
}

char	*ft_get_line(char *lft_str)
{
	int		i;
	char	*result;

	i = 0;
	if (!lft_str[i])
		return (NULL);
	while (lft_str[i] && lft_str[i] != '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (lft_str[i] && lft_str[i] != '\n')
	{
		result[i] = lft_str[i];
		i++;
	}
	if (lft_str[i] == '\n')
	{
		result[i] = lft_str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
