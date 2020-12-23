#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#define ERR1	"Error: argument"
#define	ERR2	"Error: Operation file corrupted"

char	zone[302][302];
char	back_c, mode, c;
int		zone_w, zone_h;
float	center_x, center_y, r;

int		put_str_newline(char *s)
{
	int		idx=0;

	while(s[idx])
		idx++;
	write(1, s, idx);
	write(1, "\n", 1);
	return (1);
}

float	get_dis(float x1, float y1, float x2, float y2)
{
	return (sqrtf(powf(x1-x2, 2) + powf(y1-y2, 2)));
}

void	draw_circle(void)
{
	int		x, y;
	float	dis;

	y = center_y-r-1;
	while (++y <= center_y+r+1)
	{
		x = center_x-r-1;
		while (++x <= center_x+r+1)
		{
			if (x<0 || y<0 || zone_w<=x || zone_h<=y)
				continue ;
			dis = get_dis(x, y, center_x, center_y);
			if ((mode=='C' && dis<=r) || (0<=r-dis && r-dis<1))
				zone[y][x] = c;
		}
	}
}

int		main(int argc, char **argv)
{
	FILE	*file;
	int		ret, i=-1;

	if (argc != 2)
		return (put_str_newline(ERR1));
	if (!(file = fopen(argv[1], "r")) ||
		(fscanf(file, "%d %d %c\n", &zone_w, &zone_h, &back_c) != 3) ||
		(zone_w<=0 || 300<zone_w || zone_h<=0 || 300<zone_h))
		return (put_str_newline(ERR2));
	memset(zone, back_c, sizeof(zone));
	while (0 <= (ret = fscanf(file ,"%c %f %f %f %c\n", &mode, &center_x, &center_y, &r, &c)))
	{
		if ((mode!='c' && mode!='C') || r<=0 || ret!=5)
			return ((put_str_newline(ERR2)));
		draw_circle();
	}
	while(++i < zone_h)
	{
		zone[i][zone_w] = '\0';
		put_str_newline(zone[i]);
	}
	fclose(file);
	return (0);
}