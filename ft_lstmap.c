/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:46:48 by mher              #+#    #+#             */
/*   Updated: 2021/11/25 19:25:02 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cur;

	if (!lst || !f || !del)
		return (0);
	ret = ft_lstnew(f(lst->content));
	if (!ret)
		return (0);
	lst = lst->next;
	cur = ret;
	while (lst)
	{
		cur->next = ft_lstnew(f(lst->content));
		if (!cur)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		cur = cur->next;
		lst = lst->next;
	}
	return (ret);
}
