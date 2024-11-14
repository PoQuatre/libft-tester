/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-flem <mle-flem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:18:37 by mle-flem          #+#    #+#             */
/*   Updated: 2024/11/14 17:30:16 by mle-flem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

int	main(void)
{
	signal(SIGSEGV, handle_segv);

	char *str = strdup("abc");
	char *s = ft_strrev(str);
	/* 1 */ check(!strcmp(s, "cba"));
	free(str);

	str = strdup("abcd");
	s = ft_strrev(str);
	/* 2 */ check(!strcmp(s, "dcba"));
	free(str);

	str = strdup("");
	s = ft_strrev(str);
	/* 3 */ check(!strcmp(s, ""));
	free(str);
}
