/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:46:48 by youjeon           #+#    #+#             */
/*   Updated: 2022/06/10 18:20:50 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../struct/struct.h"
# include "../utiles/utiles.h"
# include "../builtins/builtin.h"

char	**ft_split_argc(char const *s, char c, int *argc);
char	*ft_strjoin_char(char *s1, char s2);
int		parse_set_quotes(char line, int quotes, t_cmd *cmd);
void	parse(char *line, t_cmd *cmd);
void	replace(t_cmd *cmd, t_env *head);
void	delete_argv(t_cmd *cmd, int *i);
void	argc_checker(t_cmd **cmd);
void	argv_change(t_cmd *cmd, char *new, int i);
char	*ft_strjoin_free(char *s1, char *s2);

#endif
