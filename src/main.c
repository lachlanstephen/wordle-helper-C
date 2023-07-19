/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 05:17:02 by darkwater         #+#    #+#             */
/*   Updated: 2023/07/19 18:04:39 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <fcntl.h>

int	arg_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	unsigned char	**word_list;

	if (argc != 5)
	{
		printf("Wrong argument amount!\n");
		return (0);
	}
	else if (arg_length(argv[2]) != 5)
	{
		printf("Must be 5 characters!\n");
		return (0);
	}
	else
	{
		word_list = read_file(argv[1]);
		if (word_list == NULL)
			printf("Please input valid dictionary");
		wordle_solver(word_list, argv[2], argv[3], argv[4]);
	}
	return (0);
}
