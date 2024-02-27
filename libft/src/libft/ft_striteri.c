/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:12:41 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:51:49 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_striteri : applies the function ’f’ on each character of the string passed
as argument, passing its index as first argument. Each character is passed by
address to ’f’ to be modified if necessary.*/

/*static void	ft_to_upper(unsigned int i, char *s)
{
	if (s[i] >= 97 && s[i] <= 122)
		s[i] = s[i] - 32;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>

int	main(void)
{
	char	*str = "Hello World";
	ft_striteri(str, ft_to_upper);
	printf("%s", str);
}*/