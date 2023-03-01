/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:10:05 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 21:10:06 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(unsigned long int n)
{
	int		i;
	int		j;
	char	nbr1[19];
	char	*nbr2;

	i = 0;
	j = 0;
	while (n > 9)
	{
		nbr1[i++] = '0' + (n % 10);
		n = n / 10;
	}
	nbr1[i++] = '0' + n;
	if ((nbr2 = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	nbr2[i] = '\0';
	while (i--)
		nbr2[i] = nbr1[j++];
	return (nbr2);
}
