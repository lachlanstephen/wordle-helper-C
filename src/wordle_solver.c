/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:57:29 by darkwater         #+#    #+#             */
/*   Updated: 2023/06/17 06:49:14 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <fcntl.h>

void	check_contains(unsigned char **word_list, char *contains, int pos)
{
	int		i;
	int		j;
	bool	exists;

	i = 0;
	j = 0;
	exists = false;
	while (contains[i] != 0)
	{
		j = 0;
		while (word_list[pos][j] != 0)
		{
			if (word_list[pos][j] == contains[i])
			{
				exists = true;
				break ;
			}
			exists = false;
			j++;
		}
		if (exists == false)
			return ;
		i++;
	}
	printf("%s\n", word_list[pos]);
}

void	invalid_rmv(unsigned char **word_list, char *invalid,
int pos, char *contains)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (word_list[pos][j] != 0)
	{
		i = 0;
		while (invalid[i] != 0)
		{
			if (word_list[pos][j] == invalid[i])
			{
				return ;
			}
			i++;
		}
		j++;
	}
	check_contains(word_list, contains, pos);
}

void	wordle_solver(unsigned char **word_list, char *str,
char *contains, char *invalid)
{
	int				i;
	int				j;

	i = 0;
	while (word_list[i] != 0)
	{
		j = 0;
		while (str[j] != 0 && word_list[i][j] != 0)
		{
			if (str[j] == '.')
			{
				j++;
				continue ;
			}
			if (word_list[i][j] != str[j])
				break ;
			j++;
		}
		if (j == 5)
			invalid_rmv(word_list, invalid, i, contains);
		i++;
	}
}
