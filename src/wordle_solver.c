/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:57:29 by darkwater         #+#    #+#             */
/*   Updated: 2023/11/13 23:22:29 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_letter_frequency(char *valid_guess, char *str, char *contains)
{
	int	i;
	int	j;
	int	max;
	int	count;
	int	arr[26];
	char	unique[5] = {0, 0, 0, 0, 0};

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
	printf("\nThe most frequently occurring letters: ");
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
				printf("%c", i + 'a');
				j = 0;
				while (str[j] != 0)
				{
					if (i + 'a' == str[j] || i + 'a' == contains[j])
					{
						break ;
					}
					else if (j == 4)
					{
						unique[count] = i + 'a';
						count++;
					}
					j++;
				}
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
	printf("\n\nMost frequently occurring letters not already checked: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%c", unique[i]);
	}
	printf("\n");
}

void	check_contains(unsigned char **word_list, char *contains, int pos, char *valid, unsigned int *step)
{
	int					i;
	int					j;
	bool				exists;

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
		valid[*step] = word_list[pos][j];
		j++;
		*step = *step + 1;
	}
}

void	invalid_rmv(unsigned char **word_list, char *invalid,
int pos, char *contains, char *valid, unsigned int *step)
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
	unsigned int	step;
	char			valid[1500000];

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
			invalid_rmv(word_list, invalid, i, contains, valid, &step);
		i++;
	}
	printf("\nNumber of potential solutions: %u\n", step/5);
	ft_letter_frequency(valid, str, contains);
}
