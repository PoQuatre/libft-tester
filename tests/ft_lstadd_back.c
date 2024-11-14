/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:43:32 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 22:58:32 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

#include "utils.h"

#include "libft.h"

void	free_list(t_list *l)
{
	if (l)
		free(l->next);
	free(l);
}

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	t_list *l = NULL;
	ft_lstadd_back(&l, ft_lstnew((void *) 1));
	/* 1 */ check(l->content == (void *) 1);
	/* 2 */ check(!l->next);

	ft_lstadd_back(&l, ft_lstnew((void *) 2));
	/* 3 */ check(l->content == (void *) 1);
	/* 4 */ check(l->next->content == (void *) 2);
	/* 5 */ check(!l->next->next);

	t_list *l2 = NULL;
	ft_lstadd_back(&l2, ft_lstnew((void *) 3));
	ft_lstadd_back(&l2, ft_lstnew((void *) 4));
	ft_lstadd_back(&l, l2);
	/* 6  */ check(l->content == (void *) 1);
	/* 7  */ check(l->next->content == (void *) 2);
	/* 8  */ check(l->next->next->content == (void *) 3);
	/* 9  */ check(l->next->next->next->content == (void *) 4);
	/* 10 */ check(!l->next->next->next->next);
	free_list(l);
}
