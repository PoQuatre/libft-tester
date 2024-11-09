/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 05:26:25 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/09 05:27:34 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	/* 1 */ check(!ft_isprint(' ' - 1));
	/* 2 */ check(ft_isprint(' '));
	/* 3 */ check(!ft_isprint('~' + 1));
	/* 4 */ check(ft_isprint('~'));
}
