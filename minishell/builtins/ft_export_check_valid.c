/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_check_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:09:05 by mher              #+#    #+#             */
/*   Updated: 2022/06/08 17:26:05 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	is_all_digit(char *key_value, char set)
{
	while (*key_value && *key_value != set)
	{
		if (!ft_isdigit(*key_value))
			break ;
		++key_value;
	}
	if (*key_value == set)
		return (1);
	return (0);
}

int	is_have_space(char *key_value, char set)
{
	while (*key_value && *key_value != set)
	{
		if (ft_isspace(*key_value))
			break ;
		++key_value;
	}
	if (*key_value == set)
		return (0);
	return (1);
}

int	is_have_specific_char(char *key_value, char c)
{
	while (*key_value)
	{
		if (*key_value == c)
			break ;
		++key_value;
	}
	if (*key_value == '\0')
		return (0);
	return (1);
}

int	check_valid_identifier(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_have_specific_char(argv[i], '='))
		{
			print_quote_err3("export", argv[i], "not a valid identifier");
			return (-1);
		}
		if (is_have_space(argv[i], '='))
		{
			print_quote_err3("export", argv[i], "not a valid identifier");
			return (-1);
		}
		if (is_all_digit(argv[i], '='))
		{
			print_quote_err3("export", argv[i], "not a valid identifier");
			return (-1);
		}
		i++;
	}
	return (0);
}
