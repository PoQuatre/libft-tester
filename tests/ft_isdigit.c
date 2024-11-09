/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 05:15:39 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/09 05:16:22 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1 */ check(!ft_isdigit('0' - 1));
	/* 2 */ check(ft_isdigit('0'));
	/* 3 */ check(!ft_isdigit('9' + 1));
	/* 4 */ check(ft_isdigit('9'));
}
