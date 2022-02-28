/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:59:47 by ctardy            #+#    #+#             */
/*   Updated: 2022/02/28 10:40:11 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

void	msg_error(void);
void	child_fork(char **argv, char **envp, int *fd);
void	parent_proces(char **argv, char **envp, int *fd);
char	*cmd_path(char *cmd, char **envp);
void	pipexec(char *argv, char **envp);

#endif