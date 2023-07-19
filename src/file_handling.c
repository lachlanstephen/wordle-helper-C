/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 04:50:08 by darkwater         #+#    #+#             */
/*   Updated: 2023/07/20 02:00:05 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

unsigned char	**get_chars(int fd, unsigned char **buffer)
{
	unsigned char	temp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (read(fd, &temp, 1) != 0)
	{
		if (temp != '\n')
		{
			buffer[j][i] = temp;
			i++;
		}
		else
		{
			buffer[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	return (buffer);
}

int	get_line_amnt(char *file_name)
{
	unsigned char	temp;
	int				count;
	int				fd;

	count = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &temp, 1) != 0)
	{
		if (temp == '\n')
			count++;
	}
	close(fd);
	return (count);
}

unsigned char	**read_file(char *file_name)
{
	int				fd;
	int				lines_read;
	unsigned char	**buffer;
	int				i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines_read = get_line_amnt(file_name);
	buffer = (unsigned char **)malloc(sizeof(char *) * (lines_read + 1));
	if (buffer == NULL)
		return (NULL);
	while (i < lines_read)
	{
		(buffer)[i] = malloc(sizeof(unsigned char) * 6);
		if (buffer[i] == NULL)
			return (NULL);
		i++;
	}
	buffer = get_chars(fd, buffer);
	buffer[lines_read] = NULL;
	close(fd);
	return (buffer);
}
