#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define	ERR1	"error: cd: bad arguments\n"
#define ERR2	"error: cd: cannot change directory to "
#define	ERR3	"error: fatal\n"
#define ERR4	"error: cannot execute "

// "|"가 있으면 1반환, 아니면 0반환
int		is_pipe(char **argv)
{
	int i=-1;

	while (argv[++i])
	{
		if (!strncmp(argv[i], "|", 2))  // "|"가 있으면
		{
			argv[i] = NULL;  // "|" 자리에 널문자를 넣어줌
			return (1);  // "|"가 있으면 1반환
		}
		else if (!strncmp(argv[i], ";", 2))  // ";"가 있으면
		{
			argv[i] = NULL;  // ";" 자리에 널문자를 넣어줌
			return (0);
		}
	}
	return (0);
}

int		ft_strlen(char *s)
{
	int	i=0;

	while (s[i])
		i++;
	return (i);
}

// stderr에 문자열을 출력
int		put_error(char *s)
{
	write(2, s, ft_strlen(s));
	return (0);
}

// argv 개수세기
int		ft_argvlen(char **argv)
{
	int i=0;

	while(argv[i])
		i++;
	return (i);
}

void	ft_cd(char **argv)
{
	int	i = ft_argvlen(argv);  // argv 개수세기

	// argv[0] : "cd"
	// argv[1] : cd의 인자
	if (i != 2)  // cd의 인자가 한개가 아니면
		put_error(ERR1);
	else if (chdir(argv[1]) < 0)
	{
		 // 디렉토리 변경함수 에러시
		put_error(ERR2);
		put_error(argv[1]);
		put_error("\n");
	}
}

void	cmd(int argc, char **argv, char **envp, int prev, int *fd_prev)
{
	pid_t	pid;
	int		fd_next[2];
	int		next, status, i;

	if (argc <= 0)  // 인자가 0개면
		return ;
	next = is_pipe(argv);  // "|"가 있으면 1, 아니면 0
	if (next && pipe(fd_next)<0)  // "|"가 있을때 pipe 해줌
		exit(put_error(ERR3));
	if (!strncmp(argv[0], "cd", 3))
		ft_cd(argv);  // cd 명령어 처리
	else if ((pid = fork()) < 0)  // cd가 아닐때 fork 해주고 프로세스 하나 더만듬
		exit(put_error(ERR3));
	else if (!pid)  // 자식 프로세스 일때
	{
		if (prev && dup2(fd_prev[0], 0)<0)  // fd_prev[0]이 stdin 역할을 함
			exit(put_error(ERR3));
		if (next && dup2(fd_next[1], 1)<0)  // fd_next[1]이 stdout 역할을 함
			exit(put_error(ERR3));
		if (execve(argv[0], argv, envp) < 0)  // execve함수로 명령어 실행
		{
			// execve 에러시
			put_error(ERR4);
			put_error(argv[0]);
			put_error("\n");
			exit(0);
		}
	}
	else  // 부모 프로세스 일때
	{
		if (waitpid(pid, &status, 0) < 0)  // 자식프로세스를 기다림
			exit(put_error(ERR3));
		// 안쓰는 파이프 close
		if (prev)
			close(fd_prev[0]);
		if (next)
			close(fd_next[1]);
	}
	i = ft_argvlen(argv);  // argv 개수세기
	// 인자는 i+1만큼 줄고, argv는 i+1만큼 넘어가고, next(파이프가 있는지 없는지), fd_next(파이프가 있으면 pipe된 배열)을 넣어줌
	cmd(argc-i-1, argv+i+1, envp, next, fd_next);
}

int		main(int argc, char **argv, char **envp)
{
	int	fd_prev[2];

	cmd(argc-1, argv+1, envp, 0, fd_prev);
	return (0);
}