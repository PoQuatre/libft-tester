/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:57:28 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 22:01:38 by mle-flem         ###   ########.fr       */
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

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	t_list *l = NULL;
	ft_lstadd_front(&l, ft_lstnew((void *) 1));
	/* 1 */ check(l->content == (void *) 1);
	/* 2 */ check(!l->next);

	ft_lstadd_front(&l, ft_lstnew((void *) 2));
	/* 3 */ check(l->content == (void *) 2);
	/* 4 */ check(l->next->content == (void *) 1);
	/* 5 */ check(!l->next->next);
	free_list(l);
}
