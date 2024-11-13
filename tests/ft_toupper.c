/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:52:25 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/13 02:43:29 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1  */ check(ft_toupper('a') == 'A');
	/* 2  */ check(ft_toupper('a' - 1) == 'a' - 1);
	/* 3  */ check(ft_toupper('A') == 'A');
	/* 4  */ check(ft_toupper('A' - 1) == 'A' - 1);
	/* 5  */ check(ft_toupper('a' + 256) == 'a' + 256);
	/* 6  */ check(ft_toupper('A' + 256) == 'A' + 256);
	/* 7  */ check(ft_toupper('#') == '#');
	/* 8  */ check(ft_toupper('z') == 'Z');
	/* 9  */ check(ft_toupper('z' + 1) == 'z' + 1);
	/* 10 */ check(ft_toupper('Z') == 'Z');
	/* 11 */ check(ft_toupper('Z' + 1) == 'Z' + 1);
	/* 12 */ check(ft_toupper('z' + 256) == 'z' + 256);
	/* 13 */ check(ft_toupper('Z' + 256) == 'Z' + 256);
}
