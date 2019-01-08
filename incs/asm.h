/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:23:10 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/08 15:19:43 by mmervoye         ###   ########.fr       */
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


typedef struct			s_asm
{
	char				*output_name;
	char				comment[COMMENT_LENGTH + 1];
	char				prog_name[PROG_NAME_LENGTH + 1];
	int					magic;
	int					fd;
}						t_asm;

int					asm_error(int err);
int					malloc_error(void);
int					check_file(char *file_name, t_asm *asm_h);
char				*asm_strnext(char *str);
int					parse(t_asm *asm_h);
int					is_a_label(char *line);
int					add_label(char **line, t_asm *asm_h);

#endif
