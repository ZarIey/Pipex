/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:02:46 by ctardy            #+#    #+#             */
/*   Updated: 2022/02/10 18:14:03 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    msg_error(void)
{
    printf("Error");
    return ;
}

void    child_fork(char **argv, char **envp, int *fd)
{
    int file1;

    file1 = open(argv[1], O_RDONLY);
    if (file1 == -1)
        msg_error();
    dup2(fd[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(fd[0]);
	pipexec(argv[2], envp);
}

void    parent_fork(char **argv, char **envp, int *fd)
{
    int file2;

    file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
    if (file2 == -1)
        msg_error();
    dup2(fd[1], STDOUT_FILENO);
	dup2(file2, STDIN_FILENO);
	close(fd[1]);
	pipexec(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    pid_t p_id;

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
        printf("Bad arguments, respect the format please/n");
    return (0);
}