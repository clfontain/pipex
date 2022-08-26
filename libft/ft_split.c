/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:06:28 by cfontain          #+#    #+#             */
/*   Updated: 2022/05/11 09:40:06 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstr(char const *s, char c)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	j = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] != 0 && s[i] == c)
		{
			i++;
		}	
		while (s[i] != 0 && s[i] != c)
		{	
			i++;
			j++;
		}
		if (j > 0)
		{	
			count++;
			j = 0;
		}
	}
	return (count);
}

static char	*ft_initstr2(char *str, int len)
{
	str = (char *)malloc(sizeof(char) * (len) + sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_memset(str, 0, len + 1);
	return (str);
}

static char	*ft_initstr(char const *s, char c, char *str, int *j)
{
	int		i;
	int		k;

	k = 0;
	i = *j;
	while (s[i] != 0 && s[i] == c)
	{
		i++;
	}
	while (s[i] != 0 && s[i] != c)
	{
		str[k] = s[i];
		i++;
		k++;
	}
	*j = i;
	return (str);
}

static int	ft_strlenght(char const *s, char c, int *j)
{
	int		i;
	int		k;

	k = 0;
	i = *j;
	while (s[i] != 0 && s[i] == c)
	{
		i++;
	}
	while (s[i] != 0 && s[i] != c)
	{
		i++;
		k++;
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**str;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	count = (ft_countstr(s, c));
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (str == NULL)
		return (NULL);
	while (i < count)
	{
		str[i] = 0;
		len = ft_strlenght(s, c, &j);
		str[i] = ft_initstr2(str[i], len);
		str[i] = ft_initstr(s, c, str[i], &j);
		i++;
	}
	str[i] = 0;
	return (str);
}

/*
void freeTab(char * * tab)
{
	for (int i = 0; tab[i] != NULL; ++i)
		free(tab[i]);
	free(tab);
}

int main(void)
{
		char * * tab = ft_split("  tripouille  42  ", ' ');
		printf("%s\n", tab[0]);

		printf("%ld\n", ft_strlen(tab[0]));
		freeTab(tab);
				
}*/