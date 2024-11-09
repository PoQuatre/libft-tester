/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 05:22:47 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/09 05:25:30 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1 */ check(!ft_isascii(-1));
	/* 2 */ check(ft_isascii(0));
	/* 3 */ check(!ft_isascii(128));
	/* 4 */ check(ft_isascii(127));
}
