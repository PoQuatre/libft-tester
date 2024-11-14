/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:18:37 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 16:34:54 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1 */ check(!ft_isinset('A', "abc"));
	/* 2 */ check(ft_isinset('a', "abc"));
	/* 3 */ check(!ft_isinset(0, "abc"));
	/* 4 */ check(!ft_isinset('A', ""));
}
