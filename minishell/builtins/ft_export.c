/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:05:45 by mher              #+#    #+#             */
/*   Updated: 2022/06/10 14:18:28 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

static void	append_env(t_env *env, char *key, char *value)
{
	t_env	*new;

	new = new_env(NULL);
	new->prev = env;
	env->next = new;
	env->key = key;
	env->value = value;
	return ;
}

static void	change_env(t_env *env, char *key, char *value)
{
	free(env->value);
	free(key);
	env->value = value;
	return ;
}

static int	export_no_arg(t_env *env_head)
{
	t_env	*tmp;
	t_env	*sorted_env;
	t_env	*cur;

	tmp = dup_env_list(env_head);
	sorted_env = sort_env_list(tmp);
	cur = sorted_env;
	while (cur->key)
	{
		ft_write(STDOUT_FILENO, "declare -x ", 11);
		ft_write(STDOUT_FILENO, cur->key, ft_strlen(cur->key));
		ft_write(STDOUT_FILENO, "=\"", 2);
		ft_write(STDOUT_FILENO, cur->value, ft_strlen(cur->value));
		ft_write(STDOUT_FILENO, "\"\n", 2);
		cur = cur->next;
	}
	free_env_list(sorted_env);
	return (EXIT_SUCCESS);
}

void	export_key_value(t_env *env_head, char *key_value)
{
	t_env	*env;
	char	*key;
	char	*value;

	key = get_env_key(key_value);
	value = get_env_value(key_value);
	env = compare_env_key(env_head, key);
	if (env->key != NULL)
		change_env(env, key, value);
	else
		append_env(env, key, value);
	return ;
}

int	ft_export(int argc, char *argv[], t_env *env_head)
{
	int	i;
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (check_valid_identifier(argc, argv) == -1)
		exit_code = EXIT_FAILURE;
	else if (argc == 1)
		exit_code = export_no_arg(env_head);
	else
	{
		i = 1;
		while (i < argc)
		{
			export_key_value(env_head, argv[i]);
			++i;
		}
	}
	return (exit_code);
}
