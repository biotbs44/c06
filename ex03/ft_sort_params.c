/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:25:33 by jungyang          #+#    #+#             */
/*   Updated: 2021/09/30 11:43:05 by jungyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *dest, char *src)
{
	while (*dest == *src && *dest != '\0')
	{
		dest++;
		src++;
	}
	if (*dest > *src)
		return (1);
	else if (*dest < *src)
		return (-1);
	else
		return (0);
}

void	ft_print_params(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}	

int	main(int argc, char **argv)
{
	int		i;
	char	*temp;
	int		t_argc;

	t_argc = argc;
	i = 1;
	while (argc >= 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]))
			{	
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
			}
			i++;
		}
		argc--;
	}
	ft_print_params(t_argc, argv);
	return (0);
}
