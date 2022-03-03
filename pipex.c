/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:02:46 by ctardy            #+#    #+#             */
/*   Updated: 2022/03/03 13:41:43 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	child_fork(char **argv, char **envp, int *fd)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY, 0777);
	if (file1 == -1)
		msg_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(fd[0]);
	pipexec(argv[2], envp);
}

void	parent_fork(char **argv, char **envp, int *fd)
{
	int	file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file2 == -1)
		msg_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[1]);
	pipexec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	p_id;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			msg_error();
		p_id = fork();
		if (p_id == -1)
			msg_error();
		if (p_id == 0)
			child_fork(argv, envp, fd);
		waitpid(p_id, NULL, 0);
		parent_fork(argv, envp, fd);
	}
	else
		perror("Bad arguments, respect the format please\n");
	return (0);
}
