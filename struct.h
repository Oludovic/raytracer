/*
** struct.h for qsd in /home/ovsepi_l/CoursTP/Igraph/Raytracer/tp1
** 
** Made by Ovsepian Ludovic
** Login   <ovsepi_l@epitech.net>
** 
** Started on  Thu Jun 12 14:52:51 2014 Ovsepian Ludovic
** Last update Fri Jun 13 15:23:35 2014 Ovsepian Ludovic
*/

#ifndef STRUCT_H_
# define STRUCT_H_

struct	s_rt
{
  void	*mlx_ptr;
  void	*win_ptr;
  void	*img_ptr;
  int	bpp;
  int	sizeline;
  int	endian;
  char	*data;
  float	xoeil;
  float	yoeil;
  float	zoeil;
  float	vx;
  float	vy;
  float	vz;
  float	a;
  float	b;
  float	c;
  float	delta;
  float	k;
  float	k2;
  float	equ;
};

struct s_pixel
{
  float	x;
  float	y;
  int	size;
  int	color;
};

typedef struct s_rt t_rt;
typedef struct s_pixel t_pixel;
#endif
