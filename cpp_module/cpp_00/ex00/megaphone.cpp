// 소문자가 있으면 대문자로 바꿔 출력하는 과제

#include <iostream>

char	to_upper(char c)  // 소문자를 대문자로 반환 하는 함수
{
	if ('a'<=c && c<='z')
		return (c+'A'-'a');
	else
		return (c);
}

int		main(int argc, char **argv)
{
	if (argc == 1)  // 인자가 없으면
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i=1; i<argc ; i++)  // 인자의 수대로 반복
		{
			for (int j=0; argv[i][j]; j++)  // 소문자를 대문자로 반환해 한글자씩 출력
				std::cout<<to_upper(argv[i][j]);
			std::cout<<' ';
		}
		std::cout<<'\n';
	}
	return (0);
}