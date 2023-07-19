/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:57:29 by darkwater         #+#    #+#             */
/*   Updated: 2023/07/12 15:09:03 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <fcntl.h>

/*
char	*prn_guess(void)
{
	char	*best_guess[5];
	int		i;

	i = 0;
}
*/

void	ft_letter_frequency(char *valid_guess)
{
	int	i;
	int	max;
	int	count;
	int	arr[26];

	i = 0;
	max = 0;
	count = 0;

	while (i < 26)
	{
		arr[i] = 0;
		i++;
	}
	i = 0;
	while (valid_guess[i] != 0)
	{
		arr[(valid_guess[i]) - 'a'] += 1;
		i++;
	}
	i = 0;
	while (i < 26)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
		i++;
	}
	i = 0;	
	while (count < 5)
	{
		while (i < 26)
		{
			if (count == 5)
			{
				break ;
			}
			if (arr[i] == max)
			{
				count++;
				printf("%c", i + 'a');
			}
			i++;
		}
		i = 0;
		max--;
		if (max == 0)
		{
			break ;
		}
	}
}

void	check_contains(unsigned char **word_list, char *contains, int pos, char *valid, int step)
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
	j = 0;
	while (j < 5)
	{
		valid[step] = word_list[pos][j];
		j++;
		step++;
	}
}

void	invalid_rmv(unsigned char **word_list, char *invalid,
int pos, char *contains, char *valid, int step)
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
	check_contains(word_list, contains, pos, valid, step);
}

void	wordle_solver(unsigned char **word_list, char *str,
char *contains, char *invalid)
{
	int				i;
	int				j;
	int				step;
	char	valid[10000];

	i = 0;
	step = 0;
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
			invalid_rmv(word_list, invalid, i, contains, valid, step);
		i++;
	}
	ft_letter_frequency(valid);
	//printf("%s\n", prn_guess());
}
