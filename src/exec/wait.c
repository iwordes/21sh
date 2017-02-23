/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:19:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/22 16:12:59 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static char	*g_sigmsg[32] =
{
	"Hangup: 1\n",
	"",
	"Quit: 3\n",
	"Illegal instruction: 4\n",
	"Trace/BPT trap: 5\n",
	"Abort trap: 6\n",
	"EMT trap: 7\n",
	"Floating point exception: 8\n",
	"Killed: 9\n",
	"Bus error: 10\n",
	"Segmentation fault: 11\n",
	"Bad system call: 12",
	"",
	"Alarm clock: 14\n",
	"Terminated: 15\n",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"Cputime limit exceeded: 24\n",
	"Filesize limit exceeded: 25\n",
	"Virtual timer expired: 26\n",
	"Profiling timer expired: 27\n",
	"",
	"",
	"User defined signal 1: 30\n",
	"User defined signal 2: 31\n"
};

int		exec_wait(pid_t pid)
{
	int		state;

	if (pid == -1)
		return (-1);
	waitpid(pid, &state, 0);
	if (WIFSIGNALED(state))
		ft_eprintf("[%jd] %s\n", pid, g_sigmsg[WTERMSIG(status)]);
	state = WEXITSTATUS(state);
	return (state);
}
