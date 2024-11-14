/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:18:37 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 16:36:00 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1 */ check(!ft_isspace('A'));
	/* 2 */ check(ft_isspace(' '));
	/* 3 */ check(ft_isspace('\t'));
	/* 4 */ check(ft_isspace('\n'));
	/* 5 */ check(ft_isspace('\v'));
	/* 6 */ check(ft_isspace('\f'));
	/* 7 */ check(ft_isspace('\r'));
}
