/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:31:09 by akalican          #+#    #+#             */
/*   Updated: 2023/10/17 14:44:04 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	if (size < start + len && size > start)
		len = size - start;
	else if (size <= start)
	{
		len = 0;
		start = 0;
	}
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[start] && len)
	{
		len--;
		result[i++] = s[start++];
	}
	result[i] = '\0';
	return (result);
}
