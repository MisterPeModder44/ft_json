/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:56:49 by yguaye            #+#    #+#             */
/*   Updated: 2018/04/24 09:53:37 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <libft.h>

int						main(int argc, char **argv)
{
	t_json_parse_res	*res;
	char				*str;

	if (argc != 2)
		return (42);
	res = json_from_str(argv[1], 1);
	if (!res || !res->obj)
	{
		if (res)
		{
			ft_putendl(res->err ? res->err : "CRITICAL FAILURE");
			json_release_file(&res, 1);
		}
		return (43);
	}
	ft_putstr(str = json_to_str(res->obj));
	if (!str)
		ft_putendl("(null)\nSomething went wrong!");
	else
		free(str);
	json_release_file(&res, 1);
	return (0);
}
