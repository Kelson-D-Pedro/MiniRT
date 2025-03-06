/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:06:23 by kpedro            #+#    #+#             */
/*   Updated: 2024/07/13 12:07:54 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*read_and_append(int fd, char *str)
{
	char	*aux_str;
	int		bytes_read;

	aux_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux_str)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read)
	{
		bytes_read = read(fd, aux_str, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(aux_str);
			return (NULL);
		}
		aux_str[bytes_read] = '\0';
		str = gnl_strjoin(str, aux_str);
	}
	free(aux_str);
	return (str);
}

static char	*extract_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[1] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*save_remaind(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_and_append(fd, str);
	if (!str)
		return (NULL);
	line = extract_line(str);
	str = save_remaind(str);
	return (line);
}
/*int	main(void)
{
	int		fd1;
	char	*c;

	fd1 = open("big", O_RDONLY);
	c = get_next_line(fd1);
	printf("%s", c);
	c = get_next_line(fd1);
	printf("%s", c);
	c = get_next_line(fd1);
	printf("%s", c);
	c = get_next_line(fd1);
	printf("%s", c);
	close(fd1);
	return (0);
}*/
