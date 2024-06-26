/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sequence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:44:26 by plang             #+#    #+#             */
/*   Updated: 2024/06/25 17:27:02 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_skip_quotes(char **str)
{
	char	c;

	c = **str;
	(*str)++;
	while (**str && **str != c)
	{
		(*str)++;
	}
}

int	valid_sequence(char *str, char a, char b, char c)
{
	while (*str != '\0')
	{
		if (*str == '"' || *str == '\'')
			ft_skip_quotes(&str);
		if (!*str)
			break ;
		if (*str == a || *str == b)
		{
			str++;
			ft_skip_chars(&str, ' ');
			if (*str == c)
				return (5);
		}
		str++;
	}
	return (0);
}
