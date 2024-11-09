/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:10:55 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/08 20:00:08 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1 */ check(!ft_isalpha('a' - 1));
	/* 2 */ check(ft_isalpha('a'));
	/* 3 */ check(!ft_isalpha('z' + 1));
	/* 4 */ check(ft_isalpha('z'));
	/* 5 */ check(!ft_isalpha('A' - 1));
	/* 6 */ check(ft_isalpha('A'));
	/* 7 */ check(!ft_isalpha('Z' + 1));
	/* 8 */ check(ft_isalpha('Z'));
}
