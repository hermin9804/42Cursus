/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:48:13 by mher              #+#    #+#             */
/*   Updated: 2022/06/10 15:20:27 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

static int	cd_home(char *path, t_env *env_head)
{
	int		exit_code;
	char	*home;
	char	*tmp_pwd;

	exit_code = EXIT_FAILURE;
	home = ft_getenv(env_head, "HOME");
	if (home == NULL)
		print_err2("cd", "home not set");
	else
	{
		tmp_pwd = get_pwd_key_value("OLDPWD=");
		exit_code = chdir(home);
		if (exit_code == -1)
			print_err3("cd", path, strerror(errno));
		else
			export_key_value(env_head, tmp_pwd);
		free(tmp_pwd);
	}
	if (exit_code != -1)
		export_pwd("PWD=", env_head);
	return (exit_code);
}

static int	cd_tilde(t_env *env_head)
{
	int		exit_code;
	char	*home;
	char	*tmp_pwd;

	exit_code = EXIT_FAILURE;
	home = getenv("HOME");
	if (home == NULL)
		print_err2("cd", "home not set");
	else
	{
		tmp_pwd = get_pwd_key_value("OLDPWD=");
		exit_code = chdir(home);
		if (exit_code == -1)
			print_err3("cd", home, strerror(errno));
		else
			export_key_value(env_head, tmp_pwd);
		free(tmp_pwd);
	}
	if (exit_code != -1)
		export_pwd("PWD=", env_head);
	return (exit_code);
}

static int	cd_tilde_path(char *path, t_env *env_head)
{
	int		exit_code;
	char	*home;
	char	*tmp_pwd;
	char	*home_path;

	exit_code = EXIT_FAILURE;
	home = getenv("HOME");
	if (home == NULL)
		print_err2("cd", "home not set");
	else
	{
		tmp_pwd = get_pwd_key_value("OLDPWD=");
		home_path = ft_strjoin(home, path + 1);
		exit_code = chdir(home_path);
		if (exit_code == -1)
			print_err3("cd", home_path, strerror(errno));
		else
			export_key_value(env_head, tmp_pwd);
		free(home_path);
		free(tmp_pwd);
	}
	if (exit_code != -1)
		export_pwd("PWD=", env_head);
	return (exit_code);
}

static int	cd_path(char *path, t_env *env_head)
{
	int		exit_code;
	char	*tmp_pwd;

	exit_code = EXIT_FAILURE;
	tmp_pwd = get_pwd_key_value("OLDPWD=");
	exit_code = chdir(path);
	if (exit_code == -1)
		print_err3("cd", path, strerror(errno));
	else
		export_key_value(env_head, tmp_pwd);
	free(tmp_pwd);
	if (exit_code != -1)
		export_pwd("PWD=", env_head);
	return (exit_code);
}

int	ft_cd(char *path, t_env *env_head)
{
	if (path == NULL)
		return (cd_home(path, env_head));
	else if (!ft_strcmp("~", path))
		return (cd_tilde(env_head));
	else if (!ft_strncmp("~/", path, 2))
		return (cd_tilde_path(path, env_head));
	else
		return (cd_path(path, env_head));
}
