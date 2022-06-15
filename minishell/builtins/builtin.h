/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:41:40 by mher              #+#    #+#             */
/*   Updated: 2022/06/10 15:07:12 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../utiles/utiles.h"
# include "../struct/struct.h"

int		ft_pwd(void);
int		ft_cd(char *path, t_env *env_head);
int		ft_env(t_env *env_head);
int		ft_echo(int argc, char *argv[]);
int		ft_exit(t_cmd *cmd);
int		ft_unset(int argc, char *argv[], t_env *env_head);
t_env	*dup_env_list(t_env *cur);
t_env	*sort_env_list(t_env *head);
void	free_env_list(t_env *env);
char	*get_pwd_key_value(const char *key);
void	export_pwd(const char *pwd, t_env *env_head);

int		ft_export(int argc, char *argv[], t_env *env_head);
void	export_key_value(t_env *env_head, char *key_value);
int		check_valid_identifier(int argc, char *argv[]);
int		is_all_digit(char *key_value, char set);
int		is_have_space(char *key_value, char set);
int		is_have_specific_char(char *key_value, char c);

int		init_env_list(t_env *cur, char **envp);
t_env	*new_env(char *key_value);
char	*get_env_key(char *key_value);
char	*get_env_value(char *key_value);
t_env	*compare_env_key(t_env *env_head, char *key);
char	*ft_getenv(t_env *env_head, char *key);

#endif
