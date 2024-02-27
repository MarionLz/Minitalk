/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:24:34 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:52:12 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strmapi : applies the function ’f’ to each character of the string ’s’,
and passing its index as first argument to create a new string (malloc)
resulting from successive applications of ’f’.
Return value : the string created or NULL if malloc failed.*/

/*static char	ft_to_upper(unsigned int i, char c)
{
	char	c_new;

	(void) i;
	if (c >= 97 && c <= 122)
		c_new = c - 32;
	else
		c_new = c;
	return (c_new);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str_result;

	i = 0;
	str_result = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!str_result)
		return (NULL);
	while (s[i])
	{
		str_result[i] = (*f)(i, s[i]);
		i++;
	}
	str_result[i] = '\0';
	return (str_result);
}

/*#include <stdio.h>

int	main(void)
{
	char (*ptr_to_upper)(unsigned int, char);
	ptr_to_upper = ft_to_upper;
	printf("%s", ft_strmapi("Hello World", ptr_to_upper));
}*/