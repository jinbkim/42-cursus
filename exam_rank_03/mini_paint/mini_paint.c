#include <unistd.h>  // write
#include <stdio.h>  // fscanf, fopen, fclose
#include <string.h>  // memset
#include <math.h>  // sqrtf, powf
#define ERR1	"Error: argument"  // 에러코드1 매크로
#define ERR2	"Error: Operation file corrupted"  // 에러코드2 매크로

char	zone[302][302];  // 출력할 직사각형
char	back_c;  // 기본으로 채워질 배경
char	mode;  // 텅빈 직사각형인지 꽉찬 직사각형인지
char	c;  // 그려질 문자

int		zone_w;  // 직사각형 너비
int		zone_h;  // 직사각형 높이

float	center_x;  // 그려질 원의 중심의 x좌표
float	center_y;  // 그려질 원의 중심의 y좌표
float	r;  // 그려질 원의 반지름

// 문자열과 개행을 출력하고 항상 1을 반환
int		put_str_newline(char *s)
{
	int		idx=0;

	while (s[idx])
		idx++;
	write(1, s, idx);
	write(1, "\n", 1);
	return (1);  // 에러처리를 위해 항상 1을 반환
}

// 실수 v가 c=='u' 이면 올림, c=='d' 이면 내림
int		rounds(float v, char c)
{
	// 올림과 내림이 필요없을때, ex)-300000000 or 4.00000000
	if ((v>=0 && v-(int)v<0.001) || (v<0 && (int)v-v<0.001))
		return (v);
	else if (0<=v && c=='u')  // 양수의 올림
		return (v+1);
	else if ((0<=v && c=='d') || (v<0 && c=='u'))  // 양수의 내림 또는 음수의 올림
		return (v);
	else if (v<0 && c=='d')  // 음수의 내림
		return (v-1);
	return (v);
}

// 2차원에서 두점사이의 거리를 구하는 공식
float	get_dis(float x, float y, float cen_x, float cen_y)
{
	return (sqrtf(powf(cen_x-x, 2)+powf(cen_y-y, 2)));
}

void	draw_circle(void)  // 원에 문자 채우기
{
	int		x, y, x_start, y_start, x_end, y_end;
	float	dis;

	x_start = rounds(center_x-r, 'd');  // 문자가 채워지는 x좌표의 시작지점-1
	y_start = rounds(center_y-r, 'd');  // 문자가 채워지는 y좌표의 시작지점-1
	x_end = rounds(center_x+r, 'd');  // 문자가 채워지는 x좌표의 끝지점
	y_end = rounds(center_y+r, 'd');  // 문자가 채워지는 y좌표의 끝지점
	y = y_start;
	while (++y <= y_end)
	{
		x = x_start;
		while (++x <= x_end)
		{
			if (x<0 || y<0 || zone_w<=x || zone_h<=y)  // 출력할 직사각형의 범위를 넘어가면
				continue ;
			dis = get_dis(x, y, center_x, center_y);  // 원의 중심에서의 거리
			// 꽉찬 원일때, 원의 중심에서의 거리가 반지름보다 작거나 같을때나
			// 빈원일때, 반지름 - 원의 중심에서의 거리가 0이상 1미만 일때
			if ((mode=='C' && dis<=r) || (0<=r-dis && r-dis<1))
				zone[y][x] = c;  // 문자 채우기
		}
	}
}

int		main(int argc, char **argv)
{
	FILE	*file;
	int		ret, i=-1;

	if (argc != 2)  // main함수의 인자가 2가 아니면,
		return (put_str_newline(ERR1));  // 에러코드1과 개행을 출력하고, 1을 반환하며 프로그램 종료
	if (!(file = fopen(argv[1], "r")) ||  // 읽기모드로 파일오픈
		// 출력될 직사각형의 너비, 높이, 기본으로 채워지는 문자 읽기
		(fscanf(file, "%d %d %c\n", &zone_w, &zone_h, &back_c) != 3) ||
		(zone_w<0 || 300<zone_w || zone_h<0 || 300<zone_h))
		// 파일 오픈에 실패하거나,
		// 너비,높이,기본으로 채워지는 문자 총3개를 읽지 못하거나,
		// 출력될 직사각형의 범위가 잘못 되었다면
		return (put_str_newline(ERR2));  // 에러코드2와 개행을 출력하고, 1을 반환하며 프로그램 종료
	memset(zone, back_c, sizeof(zone));  // 직사각형에 배경이될 문자를 채우기
	// 그려질 원의 정보 읽기
	while (0 < (ret = fscanf(file, "%c %f %f %f %c\n", &mode, &center_x, &center_y, &r, &c)))
	{
		// 약속된 mode('c' or 'C') 가 아니거나,
		// 그려질 원의 반지름이 음수거나,
		// 5개 정보를 다읽지 못한다면
		if ((mode!='c' && mode!='C') || r<0 || ret!=5)
			return (put_str_newline(ERR2));  // 에러코드2와 개행을 출력하고, 1을 반환하며 프로그램 종료
		draw_circle();  // 읽은 정보를 바탕으로 원에 문자 채우기
	}
	while (++i < zone_h)
	{
		zone[i][zone_w] = '\0';  // 각문자열 끝에 널문자 채우기
		put_str_newline(zone[i]);  // 한줄과 개행출력
	}
	fclose(file);  // 파일 닫기
	return (0);
}