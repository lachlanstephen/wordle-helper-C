/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 05:09:31 by darkwater         #+#    #+#             */
/*   Updated: 2023/07/19 18:01:23 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <stdbool.h>

void			wordle_solver(unsigned char **word_list, char *str,
					char *contains, char *invalid);

unsigned char	**read_file(char *file_name);

#endif
