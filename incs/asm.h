/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:23:10 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/10 19:00:40 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include <fcntl.h>
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define T_REG					1
# define T_DIR					2
# define T_IND					4

typedef struct		s_op
{
	char	*name;
	int		nb_params;
	int		type_param[4];
	int		op_code;
	int		to_encode;
	int		dir_size;
}					t_op;

typedef struct			s_asm
{
	char				*output_name;
	char				comment[COMMENT_LENGTH + 1];
	char				prog_name[PROG_NAME_LENGTH + 1];
	int					magic;
	int					fd;
	t_list				*label_list;
	int					addr;
	t_op				op[17];
}						t_asm;

typedef struct			s_label
{
	int					addr;
	char				*name;
}						t_label;

typedef struct			s_instruction
{
	char				*name;
	int					addr;
	t_op				*op;
}						t_instruction;


int					asm_error(int err);
int					malloc_error(void);
int					check_file(char *file_name, t_asm *asm_h);
char				*asm_strnext(char *str);
int					parse(t_asm *asm_h);
int					is_a_label(char *line);
int					add_label(char **line, t_asm *asm_h);
int					init_op_tab(t_asm *asm_h);
int					get_instructions(t_asm *asm_h, char **line);

#endif
