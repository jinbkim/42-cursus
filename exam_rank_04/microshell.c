#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define SIDE_OUT	0
#define SIDE_IN		1

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_BREAK	2

#ifdef TEST_SH
# define TEST		1
#else
# define TEST		0
#endif

typedef struct	s_list
{
	char			**args;
	int				length;  // 한 명령어가 가지는 인자의 크기
	int				type;
	int				pipes[2];
	struct s_list	*previous;
	struct s_list	*next;
}				t_list;

int ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int show_error(char const *str)
{
	if (str)
		write(STDERR, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int exit_fatal(void)
{
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void *exit_fatal_ptr(void)
{
	exit_fatal();
	exit(EXIT_FAILURE);
	return (NULL);
}

char *ft_strdup(char const *str)
{
	char	*copy;
	int		i;

	if (!(copy = (char*)malloc(sizeof(*copy) * (ft_strlen(str) + 1))))
		return (exit_fatal_ptr());
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

int add_arg(t_list *cmd, char *arg)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!(tmp = (char**)malloc(sizeof(*tmp) * (cmd->length + 2))))
		return (exit_fatal());
	while (i < cmd->length)
	{
		// printf("i : %d, cmd->args[i] : %s\n", i, cmd->args[i]);
		tmp[i] = cmd->args[i];  // temp에 명령어 인자들을 하나씩 담음
		i++;
	}
	if (cmd->length > 0)  // 이미 리스트에 노드들이 존재하면
		free(cmd->args);
	cmd->args = tmp;  // 정보를 다시 담은 tmp 가리키기
	cmd->args[i++] = ft_strdup(arg);  // 새로운 인자 담기
	cmd->args[i] = 0;  // 마지막은 널 가리키기
	cmd->length++;  // 한 명령어의 인자 개수 증가
	return (EXIT_SUCCESS);
}

// 리스트에  arg추가
int list_push(t_list **list, char *arg)
{
	// printf("list!\n");
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (exit_fatal());  // 할당안됬으면 프로그램 종료
	new->args = NULL;
	new->length = 0;
	new->type = TYPE_END;
	new->previous = NULL;
	new->next = NULL;
	if (*list)  // 이미 리스트가 존재하면
	{
		printf("!!!\n");
		// 새로만든 노드와 연결
		(*list)->next = new;
		new->previous = *list;
	}
	*list = new;
	// 위에는 노드를 연결만 한상채
	return (add_arg(new, arg));  // 연결은 했고 노드에 정보 담기
}

// 리스트 맨첨으로 오기
int list_rewind(t_list **list)
{
	while (*list && (*list)->previous)
		*list = (*list)->previous;
	return (EXIT_SUCCESS);
}

int list_clear(t_list **cmds)
{
	t_list	*tmp;
	int		i;

	list_rewind(cmds);
	while (*cmds)
	{
		tmp = (*cmds)->next;
		i = 0;
		while (i < (*cmds)->length)
			free((*cmds)->args[i++]);
		free((*cmds)->args);
		free(*cmds);
		*cmds = tmp;
	}
	*cmds = NULL;
	return (EXIT_SUCCESS);
}

int parse_arg(t_list **cmds, char *arg)
{
	// printf("=============\n");
	int	is_break;

	is_break = (strcmp(";", arg) == 0);
	if (is_break && !*cmds)  // 인자는 ;, list가 비어있으면
		return (EXIT_SUCCESS);
	else if (!is_break && (!*cmds || (*cmds)->type > TYPE_END))  // 인자는 ;가 아니고, list가 비어있거나, TYPE_END가 아니면
	{
		// printf("list\n");
		return (list_push(cmds, arg));  // list에 인자 넣기
	}
	else if (strcmp("|", arg) == 0)  // | 이면
		(*cmds)->type = TYPE_PIPE;  // 그 노드는 파이프타입
	else if (is_break)  // ; 이면
		(*cmds)->type = TYPE_BREAK;  // 그 노드는 ;
	else
	{
		// printf("hi!\n");
		// printf("arg : %s\n", arg);
		return (add_arg(*cmds, arg));  // 리스트의 한노드에 arg추가
	}
	return (EXIT_SUCCESS);
}

int exec_cmd(t_list *cmd, char **env)
{
	pid_t	pid;
	int		ret;
	int		status;
	int		pipe_open;

	ret = EXIT_FAILURE;
	pipe_open = 0;
	if (cmd->type == TYPE_PIPE || (cmd->previous && cmd->previous->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->pipes))
			return (exit_fatal());
	}
	pid = fork();
	if (pid < 0)
		return (exit_fatal());
	else if (pid == 0)
	{
		if (cmd->type == TYPE_PIPE
			&& dup2(cmd->pipes[SIDE_IN], STDOUT) < 0)
			return (exit_fatal());
		if (cmd->previous && cmd->previous->type == TYPE_PIPE
			&& dup2(cmd->previous->pipes[SIDE_OUT], STDIN) < 0)
			return (exit_fatal());
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			show_error("error: cannot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipes[SIDE_IN]);
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->pipes[SIDE_OUT]);
		}
		if (cmd->previous && cmd->previous->type == TYPE_PIPE)
			close(cmd->previous->pipes[SIDE_OUT]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int exec_cmds(t_list **cmds, char **env)
{
	t_list	*crt;
	int		ret;

	ret = EXIT_SUCCESS;
	list_rewind(cmds);
	while (*cmds)
	{
		crt = *cmds;
		// cd 명령어
		if (strcmp("cd", crt->args[0]) == 0)
		{
			ret = EXIT_SUCCESS;
			if (crt->length < 2)  // cd 인자가 1개면
				ret = show_error("error: cd: bad arguments\n");
			else if (chdir(crt->args[1]))
			{
				ret = show_error("error: cd: cannot change directory to ");
				show_error(crt->args[1]);
				show_error("\n");
			}
		}
		else
			ret = exec_cmd(crt, env);
		if (!(*cmds)->next)
			break ;
		*cmds = (*cmds)->next;
	}
	return (ret);
}

int main(int argc, char **argv, char **env)
{
	t_list	*cmds;
	int		i;
	int		ret;

	ret = EXIT_SUCCESS;
	cmds = NULL;
	i = 1;
	while (i < argc)
		parse_arg(&cmds, argv[i++]);
	if (cmds)
		ret = exec_cmds(&cmds, env);
	list_clear(&cmds);
	if (TEST)
		while (1);
	return (ret);
}
