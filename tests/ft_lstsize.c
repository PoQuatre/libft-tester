/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:08:20 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 22:14:16 by mle-flem         ###   ########.fr       */
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
	/* 1 */ check(ft_lstsize(l) == 0);
	ft_lstadd_front(&l, ft_lstnew((void *) 1));
	/* 2 */ check(ft_lstsize(l) == 1);
	ft_lstadd_front(&l, ft_lstnew((void *) 2));
	/* 3 */ check(ft_lstsize(l) == 2);
	free_list(l);
}
