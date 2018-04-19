/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:26:24 by yguaye            #+#    #+#             */
/*   Updated: 2018/04/19 06:13:19 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_INTERNAL_H
# define JSON_INTERNAL_H

# include "json_datatypes.h"

# define JRD_PACKET 128

typedef struct			s_json_str_it_str
{
	char				is_file;
	ssize_t				i;
	char				end;
	char				*str;
}						t_json_str_it_str;

typedef struct			s_json_str_it_file
{
	char				is_file;
	ssize_t				i;
	char				end;
	int					fd;
	ssize_t				data_size;
	char				data[JRD_PACKET];
}						t_json_str_it_file;

typedef union			u_json_str_it
{
	t_json_str_it_str	str;
	t_json_str_it_file	file;
}						t_json_str_it;

t_json_value			*json_make_value(t_json_vtype type);

void					json_init_iterator(t_json_str_it *it, int file,
		char *path_or_str);

char					json_it_next(t_json_str_it *it, t_json_parse_res *res);

void					json_close_file(t_json_str_it *it);

t_json_value			*json_ret_error(t_json_parse_res *res, char *msg);

t_json_value			*json_parse(t_json_str_it *it, char has_parent,
		char is_array, t_json_parse_res *res);

t_json_value			*json_lexing(t_json_str_it *it, t_json_parse_res *res);

void					json_set_error(t_json_parse_res *res, char *msg);

#endif
