/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:06:25 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/18 12:56:30 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	length;
	int		i;

	length = ft_strlen((char *)s);
	dest = malloc(sizeof(char) * (length + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strlen;
	size_t	end;
	char	*substr;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	end = 0;
	if (start >= strlen)
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start < strlen)
		end = strlen - start;
	if (end > len)
		end = len;
	substr = malloc(sizeof(char) * (end + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, end + 1);
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dest = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, s1len + 1);
	ft_strlcpy(dest + s1len, s2, s2len + 1);
	return (dest);
}
