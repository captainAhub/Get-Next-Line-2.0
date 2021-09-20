/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleon-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:01:47 by bleon-ba          #+#    #+#             */
/*   Updated: 2021/09/20 16:01:53 by bleon-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	ans = (char *)malloc(sizeof(char) * len + 1);
	if (ans == NULL)
	{
		free (ans);
		return (NULL);
	}
	while (i < len && start < ft_strlen(s))
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[i] = '\0';
	free((char *)s);
	return (ans);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	ans = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (ans == NULL)
		return (NULL);
	while (*(s1 + i) != '\0')
	{
		*(ans + i) = *(s1 + i);
		i++;
	}
	while (*s2 != '\0')
	{
		*(ans + i) = *s2;
		i++;
		s2++;
	}
	ans[i] = '\0';
	free((char *)s1);
	return (ans);
}

char	*ft_strdup(const char *s1)
{
	char	*aux;
	size_t	i;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	aux = (char *)malloc((size + 1) * sizeof(char));
	if (aux == NULL)
	{
		free (aux);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		*(aux + i) = *(s1 + i);
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char	*ft_buffer_cache(char *str)
{
	int				i;
	unsigned int	buf_len;

	if (!str)
		return (NULL);
	buf_len = ft_strlen(str);
	i = ft_is_new_line(str);
	if ((i == -1) || ((buf_len - i) == 1))
	{
		free(str);
		return (NULL);
	}
	str = ft_substr(str, (i + 1), (buf_len - i - 1));
	return (str);
}
