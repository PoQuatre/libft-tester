/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:17:23 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/13 20:14:11 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <limits.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1  */ check(ft_atoi("\t\n\v\f\r1") == 1);
	/* 2  */ check(ft_atoi("\t\n\v\f\ra1") == 0);
	/* 3  */ check(ft_atoi("\t\n\v\f\r--1") == 0);
	/* 4  */ check(ft_atoi("\t\n\v\f\r++1") == 0);
	/* 5  */ check(ft_atoi("\t\n\v\f\r+1") == 1);
	/* 6  */ check(ft_atoi("\t\n\v\f\r-1") == -1);
	/* 7  */ check(ft_atoi("\t\n\v\f\r0") == 0);
	/* 8  */ check(ft_atoi("\t\n\v\f\r+42paris") == 42);
	/* 9  */ check(ft_atoi("\t\n\v\f\r+101") == 101);
	/* 10 */ check(ft_atoi("\t\n\v\f\r2147483647") == 2147483647);
	/* 11 */ check(ft_atoi("\t\n\v\f\r-2147483648") == -2147483648);
	/* 12 */ check(ft_atoi("-+42") == 0);
	/* 13 */ check(ft_atoi("+-42") == 0);
	/* 14 */ check(ft_atoi("+\t\n\v\f\r42") == 0);
	/* 15 */ check(ft_atoi("-\t\n\v\f\r42") == 0);
	/* 16 */ check(ft_atoi("1\t\n\v\f\r42") == 1);
	/* 17 */ check(ft_atoi("-1\t\n\v\f\r42") == -1);
	/* 18 */ check(ft_atoi("10") == 10);
	/* 19 */ check(ft_atoi("-10") == -10);
}
