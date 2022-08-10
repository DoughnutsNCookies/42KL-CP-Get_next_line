/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:11:36 by schuah            #+#    #+#             */
/*   Updated: 2022/07/15 10:48:17 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		check_is_nl(char *str);
char	*savepoint(char *input);
char	*get_read(char *input);
char	*get_next_nl(int fd, char *output);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strcomb(char *dst, char *src);
int		checkend(char c);

#endif