/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:42:50 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/13 19:12:43 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <signal.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	void *ptr = ft_calloc(4, 2);
	char buf[8] = {0};

	/* 1 */ check(ptr && !memcmp(ptr, buf, 8));
	/* 2 */ mcheck(ptr, 8);
	free(ptr);

	ptr = ft_calloc(SIZE_MAX, SIZE_MAX);
	/* 3 */ check(!ptr);
	free(ptr);

	ptr = ft_calloc(INT_MAX, INT_MAX);
	/* 4 */ check(!ptr);
	free(ptr);

	ptr = ft_calloc(INT_MIN, INT_MIN);
	/* 5 */ check(!ptr);
	free(ptr);

	ptr = ft_calloc(0, 0);
	/* 6 */ check(ptr);
	free(ptr);

	ptr = ft_calloc(0, 5);
	/* 7 */ check(ptr);
	free(ptr);

	ptr = ft_calloc(5, 0);
	/* 8 */ check(ptr);
	free(ptr);

	ptr = ft_calloc(-5, -5);
	/* 9 */ check(!ptr);
	free(ptr);

	ptr = ft_calloc(0, -5);
	/* 10 */ check(ptr);
	free(ptr);

	ptr = ft_calloc(-5, 0);
	/* 11 */ check(ptr);
	free(ptr);

	ptr = ft_calloc(3, -5);
	/* 12 */ check(!ptr);
	free(ptr);

	ptr = ft_calloc(-5, 3);
	/* 13 */ check(!ptr);
	free(ptr);
}
