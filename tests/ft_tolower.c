/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:52:25 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/13 02:44:31 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1  */ check(ft_tolower('a') == 'a');
	/* 2  */ check(ft_tolower('a' - 1) == 'a' - 1);
	/* 3  */ check(ft_tolower('A') == 'a');
	/* 4  */ check(ft_tolower('A' - 1) == 'A' - 1);
	/* 5  */ check(ft_tolower('a' + 256) == 'a' + 256);
	/* 6  */ check(ft_tolower('A' + 256) == 'A' + 256);
	/* 7  */ check(ft_tolower('#') == '#');
	/* 8  */ check(ft_tolower('z') == 'z');
	/* 9  */ check(ft_tolower('z' + 1) == 'z' + 1);
	/* 10 */ check(ft_tolower('Z') == 'z');
	/* 11 */ check(ft_tolower('Z' + 1) == 'Z' + 1);
	/* 12 */ check(ft_tolower('z' + 256) == 'z' + 256);
	/* 13 */ check(ft_tolower('Z' + 256) == 'Z' + 256);
}
