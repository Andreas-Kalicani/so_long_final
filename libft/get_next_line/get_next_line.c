/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:18:56 by akalican          #+#    #+#             */
/*   Updated: 2024/04/30 11:27:34 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft.h"

char	*ft_read_str(int fd, char *lft_str)
{
	char	*buff;
	ssize_t	read_byt;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_byt = 1;
	while (!ft_strchr_chr(lft_str, '\n') && read_byt != 0)
	{
		read_byt = read(fd, buff, BUFFER_SIZE);
		if (read_byt == -1)
		{
			free(buff);
			buff = NULL;
			if (lft_str)
				free(lft_str);
			return (NULL);
		}
		buff[read_byt] = 0;
		lft_str = ft_strjoin_join(lft_str, buff);
	}
	free(buff);
	return (lft_str);
}

char	*ft_new_line(char *lft_str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (lft_str[i] && lft_str[i] != '\n')
		i++;
	if (!lft_str[i])
	{
		free(lft_str);
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen_len(lft_str) - i + 1));
	if (!result)
	{
		free(lft_str);
		return (NULL);
	}
	i++;
	j = 0;
	while (lft_str[i])
		result[j++] = lft_str[i++];
	result[j] = '\0';
	free(lft_str);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_str(fd, left_str);
	if (!left_str)
	{
		free(left_str);
		return (NULL);
	}
	line = ft_get_line(left_str);
	left_str = ft_new_line(left_str);
	return (line);
}

/*int	main(void)
{
   int fd1 = open("tests/hello.txt", O_RDONLY);
   int i = 1;
   while (i < 4)
   {
		char *line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
   }
   close(fd1);
} */
