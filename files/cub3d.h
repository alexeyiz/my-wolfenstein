/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:13:36 by ichariss          #+#    #+#             */
/*   Updated: 2021/03/19 19:56:07 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 32

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../mlxopengl/mlx.h"
# include <string.h>

typedef struct	s_prov
{
	int	resolution;
	int	north;
	int	south;
	int	west;
	int east;
	int	sprite;
	int floor;
	int	vverh;
	int	map;
	int	position;
}				t_prov;

typedef struct	s_info
{
	int			x;
	int			y;
	char		*north;
	char		*souse;
	char		*west;
	char		*east;
	char		*sprite;
	int			floor;
	int			vverh;
	char		direction;
	char		*line;
	int			save;
	char		**tochka;
	char		**trans;
	char		**space;
}				t_info;

typedef struct	s_position
{
	double		camera_x;
	double		camera_y;
	double		direction_x;
	double		direction_y;
	double		plane_x;
	double		plane_y;
	double		masshtab;
	double		angle;
}				t_position;

typedef struct	s_process
{
	void		*mlx;
	void		*win;
}				t_process;

typedef struct	s_dda
{
	double		cam_x;
	int			screen_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		walldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			sign;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wallx;
	int			tex_x;
	int			tex_y;
	double		step;
	double		textpos;
}				t_dda;

typedef struct	s_klava
{
	int esc;
	int w;
	int s;
	int a;
	int d;
	int left;
	int right;
	int space;
}				t_klava;

typedef struct	s_pain
{
	void		*process;
	char		*adress;
	int			x;
	int			y;
	int			bpp;
	int			dlina;
	int			endian;
}				t_pain;

typedef	struct	s_data
{
	int			col;
	double		*buffer;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		a;
	int			screen_x;
	int			spriteheight;
	int			draw_y;
	int			end_y;
	int			sprite_x;
	int			draw_x;
	int			end_x;
	int			stripe;
	int			d;
	int			tex_x;
	int			tex_y;
}				t_data;

typedef	struct	s_sprite
{
	int			x;
	int			y;
	double		dlina;
}				t_sprite;

typedef struct	s_all
{
	t_prov		*prov;
	t_klava		klava;
	t_info		*info;
	t_position	*position;
	t_process	*process;
	t_pain		**pain;
	t_dda		*dda;
	t_data		*data;
	t_sprite	**sprite;
}				t_all;

void			move(t_all *all, int key);
int				keys(int key, t_all *all);
void			pusk(t_all *all);
void			init(t_all *all);
int				main(int a, char **b);
void			up(t_all *all);
void			down(t_all *all);
void			povorot(t_all *all, int key, double x, double x1);
void			pov_left(double x, double x1, t_all *all);
void			pov_right(double x, double x1, t_all *all);
void			start_raycasting(t_all *all);
int				starting(t_all *all);
void			move_right(t_all *all);
void			move_left(t_all *all);
void			move_side(t_all *all, int key);
void			choose_sign(t_all *all);
int				wall(t_all *all, int y);
void			floors(t_all *all, int i);
int				vverh(t_all *all, int i);
void			printing(t_all *all);
void			rass(t_all *all);
void			math(t_all *all);
void			colors(t_all *all, int i);
void			create_sprite(t_all *all);
void			sprites(t_all *all);
void			work_sprite(t_all *all, int i);
unsigned char	*bitmap_info(int y, int x);
void			bmpfile(t_all *all, int fd, char *cub);
void			check_riht(t_all *all);
void			where_side(t_all *all);
void			where_sprite(t_all *all);
void			ft_bzero(void *s, size_t n);
void			init6(t_all *all);
void			pech(t_all *all, int fd);
unsigned char	*bitmap_header(int y, int x);
void			init2(t_all *all);
void			color_texture(t_all *all, int y);
void			init5(t_all *all);
int				press_somethink(int key, void *a);
int				do_somethink(int key, void *a);
void			parcer(t_all *all);
void			how_many_sprite(t_all *all);
void			tochka(char **tochka);
void			check_res(t_all *all);
void			line_vverh(char *line, t_all *all, int j);
void			next_line(char *line, t_all *all);
void			cheker2(char **tochka, t_all *all);
void			checker(char **tochka);
void			texture(t_all *all, int i, char *a);
void			sign(t_all *all, char c);
int				side(char c);
void			initkeys(t_all *all);
void			init4(t_all *all);
void			tochka_cheker(int i, int j, char **tochka);
int				provim1(char *a, char *b);
void			create_bmp(t_all *all, int fd);
char			**check_map1(char **a);
char			**write_map(char **a, char **tochka);
int				shirina1(char **arr);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_putstr_fd(char *str, int fd);
void			error_cheker(char *a);
int				provim(char *a, char *b);
int				ft_exit(void);
int				use_key(t_all *all, int key, int i);
int				dlina1(char **arr);
char			**trans_map(char **tochka);
char			**check_map(char **tochka);
int				analise(char *a, int len);
char			*error_gnl(char *a);
void			init3(t_all *all);
int				check_color(t_all *all);
void			checker_sprite(t_all *all);
void			prov_line(int fd, t_all *all, int c);
int				ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			tex(char *line, t_all *all, char *c, int i);
void			rgb(char *line, int *rgb, char c, t_all *all);
void			transform_objects(char *line, t_all *all, int b);
void			checker_objects(t_all *all);
void			checker_distant(t_all *a);
int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
void			init7(t_all *all);
void			resolution(char *line, t_all *all);
void			write_route(char **tochka, char *line);
char			*put_word(char *str, char c);
char			**ft_split(char const *s, char c);
int				check_line_break(char *str);
char			*push_line(char *line);
char			*cut_next_line(char *line);
int				check_set(char ch, char *set);
void			check_line(char **tochka);
void			prov_map_y(char *line, t_all *all);
void			look_map(int fd, char *line, t_all *all);
int				count_words(char *str, char c);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				spaces(char *line, int *i);
#endif
