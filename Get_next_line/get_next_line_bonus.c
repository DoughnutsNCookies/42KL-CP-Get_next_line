/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:32:08 by schuah            #+#    #+#             */
/*   Updated: 2022/07/14 16:28:11 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_is_nl(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = -1;
	while (str[++i] != '\0')
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*savepoint(char *input)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	while (checkend(input[i]))
		i++;
	if (input[i] == '\0')
	{
		free(input);
		return (NULL);
	}
	output = malloc(sizeof(char) * (ft_strlen(input) - i++ + 1));
	if (output == NULL)
		return (NULL);
	j = 0;
	while (input[i] != '\0')
		output[j++] = input[i++];
	output[j] = '\0';
	free(input);
	return (output);
}

char	*get_read(char *input)
{
	int		i;
	char	*output;

	if (input[0] == '\0')
		return (NULL);
	i = 0;
	while (checkend(input[i]))
		i++;
	output = malloc(sizeof(char) * (i + 1 + (input[i] == '\n')));
	if (output == NULL)
		return (NULL);
	i = -1;
	while (checkend(input[++i]))
		output[i] = input[i];
	if (input[i] == '\n')
	{
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*get_next_nl(int fd, char *output)
{
	char	*buf;
	int		i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	i = 1;
	while (check_is_nl(output) == 0 && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		output = ft_strcomb(output, buf);
	}
	free(buf);
	return (output);
}

char	*get_next_line(int fd)
{
	char			*output;
	static char		*history[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	history[fd] = get_next_nl(fd, history[fd]);
	if (history[fd] == NULL)
		return (NULL);
	output = get_read(history[fd]);
	history[fd] = savepoint(history[fd]);
	return (output);
}
