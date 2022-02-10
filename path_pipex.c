/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:07:10 by ctardy            #+#    #+#             */
/*   Updated: 2022/02/10 18:53:50 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *cmd_path(char *cmd, char **envp)
{
    char    **all_paths;
    char    *select_path;
    char    *final_path;
    int     i;

    i = 0;
    while (ft_strnstr(envp[i], "PATH", 4) == 0)
        {
            i++;
        }
    all_paths = ft_split(envp[i] + 5, ':');
    i = 0;
    while (all_paths[i])
    {
        select_path = ft_strjoin(all_paths[i], "/");
        final_path = ft_strjoin(select_path, cmd);
        free(select_path);
        if (access(final_path, F_OK) == 0)
            return (final_path);
        free(final_path);
        i++;
    }
    i = -1;
    while (all_paths[++i])
        free(all_paths[i]);
    free(all_paths);
    return (0);
}

void    pipexec(char *argv, char **envp)
{
    char    **cmd;
    char    *path;
    int     i;

    i = 0;
    cmd = ft_split(argv, ' ');
    path = cmd_path(cmd[0], envp);
    if (!path)
    {
        while (cmd[++i])
            free(cmd[i]);
        free(cmd);
        msg_error();
    }
    if (execve(path, cmd, envp) == -1)
        msg_error();
}
