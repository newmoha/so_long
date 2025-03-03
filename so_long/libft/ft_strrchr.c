/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:28:21 by maskour           #+#    #+#             */
/*   Updated: 2025/02/28 14:49:51 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	lent;
	size_t	i;

	lent = ft_strlen(str);
	i = lent;
	while (i > 0)
	{
		i--;
		if (str[i] == (char )c)
			return ((char *)(i + str));
	}
	if ((char )c == '\0')
		return ((char *)(str + lent));
	return (NULL);
}
