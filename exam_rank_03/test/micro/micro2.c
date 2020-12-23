#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define	ERR1	"Error: argument"
#define	ERR2	"Error: Operation file corrupted"

char	zone[302][302];
char	back_c, mode, c;
int		zone_w, zone_h;
float	corner_x, corner_y, rec_w, rec_h;

int		put_str_newline(char *s)
{
	int		idx=0;

	while (s[idx])
		idx++;
	write(1, s, idx);
	write(1, "\n", 1);
	return (1);
}

int		rounds(float v, char set)
{
	if ((0<=v && v-(int)v<0.001) || (v<0 && (int)v-v<0.001))
		return (v);
	if (0<=v && set=='u')
		return (v+1);
	if (0<=v && set=='d')
		return (v);
	if (v<0 && set=='u')
		return (v);
	return(v-1);
}

void	draw_rec(void)
{
	int		x_start, y_start, x_end, y_end, x, y;

	x_start = rounds(corner_x, 'u')-1;
	y_start = rounds(corner_y, 'u')-1;
	x_end = rounds(corner_x+rec_w, 'd');
	y_end = rounds(corner_y+rec_h, 'd');
	y = y_start;
	while(++y <= y_end)
	{
		x = x_start;
		while (++x <= x_end)
		{
			if (x<0 || y<0 || zone_w<=x || zone_h<=y)
				continue ;
			if (mode=='R' || x==x_start+1 || x==x_end || y==y_start+1 || y==y_end)
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
	while (0 <= (ret = fscanf(file, "%c %f %f %f %f %c\n", &mode, &corner_x, &corner_y, &rec_w, &rec_h, &c)))
	{
		if ((mode!='R' && mode!='r') || rec_w<=0 || rec_h<=0 || ret!=6)
			return (put_str_newline(ERR2));
		draw_rec();
	}
	while(++i < zone_h)
	{
		zone[i][zone_w] = '\0';
		put_str_newline(zone[i]);
	}
	fclose(file);
	return(0);
}