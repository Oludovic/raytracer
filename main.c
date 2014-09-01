/*
** main.c for qsd in /home/ovsepi_l/CoursTP/Igraph/Raytracer/tp1
** 
** Made by Ovsepian Ludovic
** Login   <ovsepi_l@epitech.net>
** 
** Started on  Thu Jun 12 14:52:17 2014 Ovsepian Ludovic
** Last update Fri Jun 20 17:10:14 2014 Ludovic Ovsepian
*/

#include <stdio.h>
#include "struct.h"
#include "mlx.h"
#include "math.h"
#include <stdlib.h>

int	gere_expose(t_rt *rt)
{
  mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr , rt->img_ptr, 0, 0);
}

int	calc(t_pixel *pixel, t_rt *rt)
{
  rt->vx = 100;
  rt->vy = 200 - pixel->x;
  rt->vz = 200 - pixel->y;
  rt->xoeil = - 300;
  rt->zoeil = 100;
  rt->yoeil = 0;
  inter_sphere(pixel, rt);
  inter_plan(pixel, rt);
  //  inter_cylindre(pixel, rt);
  //inter_cone(pixel, rt);
}

int	inter_sphere(t_pixel *pixel, t_rt *rt)
{
    rt->a = rt->vx * rt->vx + rt->vy * rt->vy + rt->vz * rt->vz;
  rt->b = 2 * (rt->xoeil * rt->vx + rt->yoeil * rt->vy + rt->zoeil * rt->vz);
  rt->c = rt->xoeil * rt->xoeil + rt->yoeil * rt->yoeil + rt->zoeil * rt->zoeil - 225 * 225;
  rt->delta = rt->b * rt->b - 4 * rt->a * rt->c;
  rt->k = (- rt->b - sqrt(rt->delta)) / (2 * rt->a);
  rt->k2 = (- rt->b + sqrt(rt->delta)) / (2 * rt->a);
  rt->equ = rt->a * rt->k * rt->k + rt->b * rt->k + rt->c;
  if (rt->delta > 0.1)
    pixel->color = rt->k * 350 + pixel->x / 2 * 255;
  else
    pixel->color = 0;
}

int	inter_cylindre(t_pixel *pixel, t_rt *rt)
{
  if (rt->vy * rt->vy < 100 * 100 && rt->vz > -150 && rt->vz < 150)
    pixel->color = 0x00FF00;
}

int	inter_cone(t_pixel *pixel, t_rt *rt)
{
  if (rt->vy * rt->vy < rt->vz * rt->vz * tan(1) * tan(1) && rt->vz > -150 && rt->vz < 150)
    pixel->color = 0x0000FF;
}

int	inter_plan(t_pixel *pixel, t_rt *rt)
{
  float	k_plan;
  float	v_plan;

  v_plan = rt->vz;
  k_plan = (-rt->zoeil / v_plan);  
  if ((((v_plan > -0.1 && v_plan < 0.1 && rt->zoeil == 0 && rt->yoeil == 0) || ((k_plan > 0 && rt->k < 0 && rt->k2 < 0) || (k_plan < rt->k && rt->k2 < 0 && rt->k > 0) || (k_plan < rt->k2 && rt->k < 0 && rt->k2 > 0) || (k_plan < rt->k && k_plan < rt->k2 && k_plan > 0))) || (v_plan < 0.1 && v_plan > -0.1 && pixel->color == 0)) || (pixel->color == 0 && (rt->zoeil != 0 || rt->yoeil != 0)) && pixel->y > 200 - rt->zoeil)
    pixel->color = 0xFF0000;
}

int		remplis_image(t_rt *rt)
{
  t_pixel	pixel;

  pixel.x = 0;
  pixel.y = 0;
  pixel.size = 400;
  while (pixel.y <= 400)
    {
      while (pixel.x <= 400)
        {
	  calc(&pixel, rt);
	  my_pixel_put_to_image(&pixel, rt);
	  //printf("x:%d   y:%d\n", pixel.x, pixel.y);
          pixel.x = pixel.x + 1;
        }
      pixel.x = 0;
      pixel.y = pixel.y + 1;
    }
}

int	my_pixel_put_to_image(t_pixel *pixel, t_rt *rt)
{
  int	i;

  i = pixel->size * pixel->y * 4;
  rt->data[i + 4 * (int)pixel->x] = pixel->color & 0xFF;
  rt->data[i + 4 * (int)pixel->x + 1] = pixel->color >> 8;
  rt->data[i + 4 * (int)pixel->x + 2] = pixel->color >> 16;
  //(*data)[i + 4 * (int)pixel->x + 3] = 0;
}

int	main(int ac, char **av)
{
  t_rt	rt;

  rt.mlx_ptr = mlx_init();
  rt.win_ptr = mlx_new_window(rt.mlx_ptr , 400 , 400 , "My first window");
  rt.img_ptr = mlx_new_image(rt.mlx_ptr, 400, 400);
  rt.data = mlx_get_data_addr(rt.img_ptr, &rt.bpp, &rt.sizeline, &rt.endian);
  remplis_image(&rt);
  mlx_put_image_to_window(rt.mlx_ptr, rt.win_ptr , rt.img_ptr, 0, 0);
  mlx_expose_hook(rt.win_ptr, gere_expose, &rt);
  mlx_loop(rt.mlx_ptr);
}
