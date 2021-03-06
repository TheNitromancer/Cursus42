/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:01:07 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/13 16:56:05 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	firstchild(t_piper *piper, char **argv, char **envp)
{
	if (piper->inflag)
		exit(1);
	piper->cmdpath = commander(piper, argv,
			piper->currchildpos + piper->hereflag + 2);
	if (!piper->cmdpath)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[piper->currchildpos + piper->hereflag + 2], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	close(piper->fd[0]);
	dup2(piper->fd[1], 1);
	close(piper->fd[1]);
	dup2(piper->infd, 0);
	close(piper->infd);
	if (execve(piper->cmdpath, piper->currcmd, envp) < 0)
		errxit("Execve error: command not found.\n");
}

void	middlechild(t_piper *piper, char **argv, char **envp)
{
	waitpid(piper->childid[piper->currchildpos - 1], NULL, 0);
	piper->cmdpath = commander(piper, argv,
			piper->currchildpos + piper->hereflag + 2);
	if (!piper->cmdpath)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[piper->currchildpos + piper->hereflag + 2], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	close(piper->fd[0]);
	dup2(piper->oldpipe, 0);
	close(piper->oldpipe);
	dup2(piper->fd[1], 1);
	close(piper->fd[1]);
	if (execve(piper->cmdpath, piper->currcmd, envp) < 0)
		errxit("Execve error: command not found.\n");
}

void	lastchild(t_piper *piper, char **argv, char **envp)
{
	waitpid(piper->childid[piper->currchildpos - 1], NULL, 0);
	piper->cmdpath = commander(piper, argv,
			piper->currchildpos + piper->hereflag + 2);
	if (!piper->cmdpath)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[piper->currchildpos + piper->hereflag + 2], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	close(piper->fd[1]);
	dup2(piper->fd[0], 0);
	close(piper->fd[0]);
	dup2(piper->outfd, 1);
	close(piper->outfd);
	if (execve(piper->cmdpath, piper->currcmd, envp) < 0)
		errxit("Execve error: command not found.\n");
}
