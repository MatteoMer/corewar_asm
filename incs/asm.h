/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:23:10 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/18 15:06:11 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include <fcntl.h>
# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define REG_NUMBER				16

typedef struct		s_op
{
	char			*name;
	int				nb_params;
	int				type_param[4];
	int				op_code;
	int				to_encode;
	int				dir_size;
}					t_op;

typedef struct		s_asm
{
	char			*output_name;
	char			comment[COMMENT_LENGTH + 1];
	char			prog_name[PROG_NAME_LENGTH + 1];
	int				magic;
	int				fd;
	t_list			*label_list;
	t_list			*list_instruction;
	int				addr;
	t_op			op[17];
}					t_asm;

typedef struct		s_label
{
	int				addr;
	char			*name;
}					t_label;

typedef struct		s_params
{
	int				type;
	char			*content;
	int				is_label;
	int				label_addr;
	int				size;
	struct s_params	*next;
}					t_params;

typedef struct		s_instruction
{
	char			*name;
	int				addr;
	t_op			*op;
	t_params		*params;
}					t_instruction;

int					asm_error(t_asm *asm_h, int err);
int					malloc_error(void);
int					check_file(char *file_name, t_asm *asm_h);
char				*asm_strnext(char *str);
int					parse(t_asm *asm_h);
int					is_a_label(char *line);
int					add_label(char **line, t_asm *asm_h);
int					init_op_tab(t_asm *asm_h);
int					get_instructions(t_asm *asm_h, char **line);
int					new_instruction(t_asm *asm_h, char **line);
int					parse_labels(t_asm *asm_h);
int					writing(t_asm *asm_h);
int					write_instructions(t_asm *asm_h);
t_list				*reverse_list(t_list *lst);
t_params			*reverse_params(t_params *list);
char				*asm_get_lastspace(char *str);
int					write_uint(int fd, int size, int nb);
char				*asm_strtrim(char *line);
int					get_size_param(t_instruction *i, t_params *param);
int					get_type_param(char *param);
int					check_type_args(t_asm *asm_h, char **param_tab, t_instruction *new);
int					free_and_ret_err(void *to_free1, void *to_free2, \
		char **tab_to_free, int ret);
int					op_exist(char *name, t_asm *asm_h, t_instruction *new);
int					get_type_param(char *param);
int					get_size_param(t_instruction *i, t_params *param);
int					check_label_and_size(t_instruction *i,\
		t_params **param);
uint16_t			rev_endian16(uint16_t i);
void				free_asm(t_asm *asm_h);

#endif
