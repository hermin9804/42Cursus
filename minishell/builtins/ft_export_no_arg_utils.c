/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_no_arg_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:12:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/08 17:27:00 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	swap_env(t_env *env1, t_env *env2)
{
	char	*tmp_k;
	char	*tmp_v;

	tmp_k = env1->key;
	tmp_v = env1->value;
	env1->key = env2->key;
	env1->value = env2->value;
	env2->key = tmp_k;
	env2->value = tmp_v;
}

static t_env	*dup_env(t_env *cur)
{
	t_env	*new;

	new = (t_env *)ft_malloc(sizeof(t_env), 1);
	if (cur == NULL)
	{
		new->key = NULL;
		new->value = NULL;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->key = ft_strdup(cur->key);
		new->value = ft_strdup(cur->value);
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

t_env	*dup_env_list(t_env *cur)
{
	t_env	*ret;
	t_env	*new;
	t_env	*tmp;

	ret = dup_env(cur);
	tmp = ret;
	cur = cur->next;
	while (cur->key)
	{
		new = dup_env(cur);
		tmp->next = new;
		new->prev = tmp;
		tmp = new;
		cur = cur->next;
	}
	new = dup_env(NULL);
	tmp->next = new;
	new->prev = tmp;
	return (ret);
}

t_env	*sort_env_list(t_env *head)
{
	t_env	*cur;

	cur = head;
	while (cur->next->key)
	{
		if (ft_strcmp(cur->key, cur->next->key) > 0)
		{
			swap_env(cur, cur->next);
			cur = head;
		}
		else
			cur = cur->next;
	}
	return (head);
}

void	free_env_list(t_env *env)
{
	t_env	*next;

	while (env->key)
	{
		next = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = next;
	}
	free(env->key);
	free(env->value);
	free(env);
}
