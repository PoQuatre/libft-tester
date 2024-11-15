/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:39:14 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/15 08:49:21 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

#include "utils.h"

#include "libft.h"

void	free_list(t_list *l)
{
	if (l)
		free_list(l->next);
	free(l);
}

void	*increment(void *p)
{
	int *ret = malloc (sizeof(int));
	*ret = *(int *)p + 1;
	return (ret);
}

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	int	tab[] = {0, 1, 2, 3};
	t_list *l = ft_lstnew(tab);
	for (int i = 1; i < 4; i++)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	t_list *m = ft_lstmap(l, increment, free);
	t_list *cur = l;
	/* 1 2 3 4 */ for (int i = 0; i < 4; i++)
	{
		check(*(int *)cur->content == i);
		cur = cur->next;
	}
	/* 5 */ check(!cur);
	cur = m;
	/* 6 7 8 9 */ for (int i = 0; i < 4; i++)
	{
		check(*(int *)cur->content == i + 1);
		cur = cur->next;
	}
	/* 10 */ check(!cur);
	free_list(l);
	ft_lstclear(&m, free);
}
