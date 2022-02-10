/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:11:33 by ctardy            #+#    #+#             */
/*   Updated: 2022/02/10 17:17:15 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*charstack;

	charstack = (char *) haystack;
	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return (charstack);
	while (charstack[i] && needle[j])
	{
		if (charstack[i] == needle[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (!(needle[j]) && len >= i)
		return (&charstack[i - j]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*inter;
	size_t	join_size;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	join_size = ft_strlen(s1) + ft_strlen(s2);
	inter = malloc(sizeof(char) * join_size + 1);
	if (inter == NULL)
		return (NULL);
	while (s1[i])
	{
		inter[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		inter[i++] = s2[j++];
	inter[i] = '\0';
	return (inter);
}

static int	nbr_split(char const *s, char c)

{
	char	*inter;
	size_t	i;
	size_t	count;

	i = 0;
	inter = (char *)s;
	count = 0;
	while (inter[i])
	{
		if (inter[i] != c)
		{
			count++;
			while (inter[i] && inter[i] != c)
				i++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	const char	*start;
	int			i;
	int			len;

	i = 0;
	len = 0;
	split = malloc(sizeof(char *) * (nbr_split(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = s;
		len = 0;
		while (*s && *s != c && (int)len++ != -1)
			s++;
		if (*(s - 1) != c)
			split[i++] = ft_substr(start, 0, len);
	}
	split[i] = NULL;
	return (split);
}