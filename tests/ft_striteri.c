/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:07:49 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 18:11:17 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>

#include "utils.h"

#include "libft.h"


void	addIndex(unsigned int i, char *s)
{
	*s += i;
}

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	{
		char s[] = "";
		ft_striteri(s, addIndex);
		/* 1 */ check(!strcmp(s, ""));
	}

	{
		char s[] = "0";
		ft_striteri(s, addIndex);
		/* 2 */ check(!strcmp(s, "0"));
	}

	{
		char s[] = "0000000000";
		ft_striteri(s, addIndex);
		/* 3 */ check(!strcmp(s, "0123456789"));
	}
}
