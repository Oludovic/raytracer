##
## Makefile for zelkfnlzekf in /home/ovsepi_l/rendu/Piscine-C-lib/my
## 
## Made by Ludovic Ovsepian
## Login   <ovsepi_l@epitech.net>
## 
## Started on  Mon Oct 21 09:02:43 2013 Ludovic Ovsepian
## Last update Thu Jun 12 17:17:57 2014 Ovsepian Ludovic
##

SRCS	= main.c

OBJS	= $(SRCS:.c=.o)

NAME	= rt1

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME) -L/usr/lib64 -lmlx_$$HOSTTYPE -L/usr/lib64/X11 -lXext -lX11 -lm

clean:
	rm -rf $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
