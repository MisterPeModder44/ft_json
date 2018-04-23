/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_from.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 01:26:18 by yguaye            #+#    #+#             */
/*   Updated: 2018/04/24 01:55:34 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_base/character.h>
#include "json.h"

static t_json_parse_res	*json_check_after_main(t_json_parse_res *res,
		t_json_str_it *it)
{
	while (!it->str.end)
		if (!ft_isspace(json_it_next(it, res)))
		{
			json_release_value(&res->obj);
			json_set_error(res, "Non-whitespace characters are not allowed"
					" after main object");
			return (res);
		}
	return (res);
}

t_json_parse_res		*json_from_str(const char *src)
{
	t_json_str_it		it;
	t_json_parse_res	*res;
	t_json_value		*obj;

	if (!(res = (t_json_parse_res *)malloc(sizeof(t_json_parse_res))))
		return (NULL);
	json_init_iterator(&it, 0, src);
	res->err = NULL;
	res->line = 1;
	res->col = 0;
	res->obj = NULL;
	obj = json_parse(&it, 0, 0, res);

	if (obj)
		res->obj = obj;
	return (json_check_after_main(res, &it));
}
