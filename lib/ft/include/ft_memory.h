/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:38:48 by iwordes           #+#    #+#             */
/*   Updated: 2016/11/26 17:39:24 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

void	ft_bzero(void *pointer, size_t bytecount);
void	*ft_memccpy(void *dest, const void *src, int ch, size_t bytecount);
void	*ft_memchr(const void *memory, int character, size_t bytecount);
int		ft_memcmp(const void *memory1, const void *memory2, size_t bytecount);
void	*ft_memcpy(void *dest, const void *source, size_t bytecount);
void	*ft_memmove(void *dest, const void *source, size_t bytecount);
void	*ft_memset(void *memory, int value, size_t bytecount);

void	*ft_memalloc(size_t bytecount);
void	ft_memdel(void **memory);

void	*ft_realloc(void *memory, size_t target, size_t original);
void	*ft_drealloc(void *memory, size_t target, size_t original);

/*
**void	*ft_malloc(size_t bytes);
**void	*ft_realloc(void *memory, size_t target, size_t original);
**void	ft_free(void *memory);
**
**void	*ft_realloc(void *memory, size_t target);
*/

size_t	ft_memuntil(const void *memory, t_byte find, size_t limit);

#endif
