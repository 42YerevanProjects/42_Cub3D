/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:34:11 by shovsepy          #+#    #+#             */
/*   Updated: 2022/03/29 07:34:19 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

int	get_next_line(int fd, char **line)
{
	int		i;
	int		n;
	char	c;
	char	*str;

	i = 0;
	if (fd < 0)
		return (-1);
	str = (char *)malloc(1000 + 1);
	if (!str)
		return (-1);
	n = read(fd, &c, 1);
	while (n && c != '\n' && c != '\0')
	{
		str[i++] = c;
		n = read(fd, &c, 1);
	}
	str[i] = '\0';
	*line = str;
	if (ft_strlen(*line) != 0 && n == 0)
		map.gnl = 1;
	return (n);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * sign);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		idx;
	char	*modified_s;

	modified_s = malloc(sizeof(char) * (len + 1));
	if (!s || !modified_s)
		return (NULL);
	idx = 0;
	while (start < ft_strlen((char *)s) && s[start + idx] && idx < len)
	{
		modified_s[idx] = s[start + idx];
		idx++;
	}
	modified_s[idx] = '\0';
	return (modified_s);
}
