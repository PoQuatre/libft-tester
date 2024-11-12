/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:52:12 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/13 00:40:18 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char s[] = {42, 82, 21, 4, 2, 0, 2, 1};

	/* 1 */ check(ft_memchr(s, 42, 0) == NULL);
	/* 2 */ check(ft_memchr(s, 42, 1) == s);
	/* 3 */ check(ft_memchr(s, 21, 3) == s + 2);
	/* 4 */ check(ft_memchr(s, 32, 8) == NULL);
	/* 5 */ check(ft_memchr(s, 42 + 256, 8) == s);
}
