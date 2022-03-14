/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:47:30 by yliao             #+#    #+#             */
/*   Updated: 2022/03/14 19:30:13 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFFER_SIZE	128

char	*ft_read(int fd, char *stash);
char	*get_line(char *s);
char	*remove_line(char *s, size_t size_line);
char	*get_next_line(int fd);
#endif
