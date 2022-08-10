/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:34:26 by schuah            #+#    #+#             */
/*   Updated: 2022/07/13 12:09:59 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcomb(char *dst, char *src)
{
	int		i;
	int		j;
	char	*output;

	if (dst == NULL)
	{
		dst = malloc(sizeof(char) * 1);
		if (dst == NULL || src == NULL)
			return (NULL);
		dst[0] = '\0';
	}
	output = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src) + 1));
	if (output == NULL)
		return (NULL);
	i = -1;
	if (dst)
		while (dst[++i] != '\0')
			output[i] = dst[i];
	j = 0;
	while (src[j] != '\0')
		output[i++] = src[j++];
	output[ft_strlen(dst) + ft_strlen(src)] = '\0';
	free(dst);
	return (output);
}

int	checkend(char c)
{
	return (c != '\0' && c != '\n');
}
