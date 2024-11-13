/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:28:19 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/13 01:35:30 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char s1[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	/* 1 */ check(!ft_memcmp(s1, s1, 4));
	/* 2 */ check(!ft_memcmp(s1, s2, 0));
	/* 3 */ check(ft_memcmp(s1, s2, 1) > 0);
	/* 4 */ check(ft_memcmp(s2, s1, 1) < 0);
	/* 5 */ check(ft_memcmp(s2, s3, 4));
}
