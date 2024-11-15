/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:18:51 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/15 08:27:45 by mle-flem         ###   ########.fr       */
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

void	increment(void *p)
{
	(*(int *)p)++;
}

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	int	tab[] = {0, 1, 2, 3};
	t_list *l = ft_lstnew(tab);
	for (int i = 1; i < 4; i++)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	ft_lstiter(l, increment);
	t_list *cur = l;
	/* 1 2 3 4 */ for (int i = 0; i < 4; i++)
	{
		check(*(int *)cur->content == i + 1);
		cur = cur->next;
	}
	free_list(l);
}
