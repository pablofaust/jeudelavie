# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaust   <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 14:19:53 by pfaust            #+#    #+#              #
#    Updated: 2018/03/20 18:46:09 by pfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GOL		=	gol

CC			=	gcc
CFLAGS		=   -Wall -Wextra -Werror -g3

_SRCS		=	main.c parse_screen.c parse_coords.c
_LIBFT		=	libft.a
_MLX		= 	libmlx.a

SRCS_DIR	=	.
LIB_DIR		=	libft
MLX_DIR		=	minilibx_macos
SRCS		=	$(addprefix	$(SRCS_DIR)/, $(_SRCS))
LIBFT		=	$(addprefix $(LIB_DIR)/, $(_LIBFT))
MLX			=	$(addprefix $(MLX_DIR)/, $(_MLX))

OBJS		=	$(SRCS:.c=.o)

all:	$(GOL)

$(GOL) : $(LIBFT) $(MLX) $(OBJS) gol.h
	@$(CC) $(CFLAGS) -o $(GOL) $(OBJS) -framework OpenGL -framework AppKit -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -lm -D_REENTRANT -lpthread
	@echo "$(GOL) : $(_GREEN)Done$(_END)"

$(LIBFT):
	@make -C $(LIB_DIR)

$(MLX):
	@make -C $(MLX_DIR)

%.o : %.c gol.h
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

clean:
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(MLX_DIR)
	@/bin/rm -f $(OBJS)
	@echo "GOL clean : $(_GREEN)Done$(_END)"

fclean: clean
	@/bin/rm -f $(GOL)
	@echo "GOL fclean : $(_GREEN)Done$(_END)"

re:
	@make fclean
	@make

.PHONY: all clean fclean re

