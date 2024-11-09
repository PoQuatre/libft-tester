/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 05:17:29 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/09 05:23:38 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1  */ check(!ft_isalnum('a' - 1));
	/* 2  */ check(ft_isalnum('a'));
	/* 3  */ check(!ft_isalnum('z' + 1));
	/* 4  */ check(ft_isalnum('z'));
	/* 5  */ check(!ft_isalnum('A' - 1));
	/* 6  */ check(ft_isalnum('A'));
	/* 7  */ check(!ft_isalnum('Z' + 1));
	/* 8  */ check(ft_isalnum('Z'));
	/* 9  */ check(!ft_isalnum('0' - 1));
	/* 10 */ check(ft_isalnum('0'));
	/* 11 */ check(!ft_isalnum('9' + 1));
	/* 12 */ check(ft_isalnum('9'));
}
