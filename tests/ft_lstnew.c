/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 05:31:37 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 21:50:46 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	t_list *l = ft_lstnew((void *) 42);
	/* 1 */ check(l->content == (void *) 42);
	/* 2 */ check(!l->next);
	/* 3 */ mcheck(l, sizeof(t_list));
	free(l);
}
