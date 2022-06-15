/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:17:22 by mher              #+#    #+#             */
/*   Updated: 2022/06/09 19:41:27 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

static void	remove_env(t_env *env)
{
	t_env	*next;
	t_env	*prev;

	next = env->next;
	prev = env->prev;
	prev->next = env->next;
	next->prev = env->prev;
	free(env->key);
	free(env->value);
	free(env);
}

static int	check_valid_key_identifier(int argc, char *argv[])
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (++i < argc)
	{
		if (argv[i] == NULL)
		{
			print_quote_err3("unset", "", "not a valid identifier");
			return (-1);
		}
		if (is_have_specific_char(argv[i], '='))
			ret = -1;
		else if (is_have_space(argv[i], '\0'))
			ret = -1;
		else if (is_all_digit(argv[i], '\0'))
			ret = -1;
		if (ret == -1)
		{
			print_quote_err3("unset", argv[i], "not a valid identifier");
			return (ret);
		}
	}
	return (0);
}

static void	unset(t_env *env_head, char *key)
{
	t_env	*env;

	env = compare_env_key(env_head, key);
	if (env->key == NULL)
		return ;
	else
		remove_env(env);
}

int	ft_unset(int argc, char *argv[], t_env *env_head)
{
	int	i;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (check_valid_key_identifier(argc, argv) == -1)
		return (EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		unset(env_head, argv[i]);
		++i;
	}
	return (EXIT_SUCCESS);
}
