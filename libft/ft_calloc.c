/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:46 by akalican          #+#    #+#             */
/*   Updated: 2023/10/13 13:59:55 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;
	size_t	total;

	total = count * size;
	if (count != '\0' && total / count != size)
	{
		return (NULL);
	}
	new = malloc(total);
	if (!new)
	{
		return (NULL);
	}
	ft_memset(new, 0, total);
	return (new);
}
