NAME			=	cub3D

LIBFT			=	libft.a 

MLX				=	libmlx_Linux.a libmlx.a

DIR_SRCS		=	srcs

# DIR_BONUS		=	bonus

DIR_OBJS		=	objs

SRCS_NAMES		=	main.c \
				    parsing/parse_file.c \
				    parsing/parsing_map.c \
					parsing/parse_direction.c \
					exec/init_game.c \
					exec/draw_pixel.c \
					exec/key_log.c \
					exec/dda.c \


OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

# OBJS_NAMES_B	=	${BONUS:.c=.o}

DEPS			=	${SRCS_NAMES:.c=.d}

# DEPS_B			=	${BONUS:.c=.d}

# SRCS_B			=	$(addprefix $(DIR_BONUS)/,$(BONUS))

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

# OBJS_B			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES_B))

INC				=	-Iincludes -Ilibft/includes -I/usr/include -I/mlx/include/mlx.h 

LIB				=	-Llibft -lft -lm -lXext -lX11 -L/usr/lib -Lmlx -lXfixes -lmlx -L/usr/lib -Imlx

#LIB				=	-Llibft -lft -lm -L/usr/lib -L/opt/X11/lib -L/opt/homebrew/lib -framework Cocoa -framework OpenGL -framework IOKit -lglfw -framework OpenGL

CC				=	cc

CDFLAGS 		= 	-MMD -MP

CFLAGS			=	-g3 #-O3 -march=native  -Wall -Werror -Wextra

MAKEFLAGS		=	--no-print-directory

all:	${NAME}

# @make -C mlx/mlx
# mv mlx/mlx/libmlx.a mlx/mlx/libmlx_Linux.a mlx/
$(NAME): $(DIR_OBJS) $(OBJS) 
	@make -C libft
	@make -C mlx/mlx
	@cp mlx/mlx/libmlx.a mlx/mlx/libmlx_Linux.a .
	$(CC) $(OBJS) $(CFLAGS) $(LIB) $(MLX) -o $(NAME)
	@echo "\033[32;5mcub3d\033[0m"

# bonus: $(DIR_OBJS) $(OBJS_B) 
# 	@make -C libft
# 	@make -C mlx/mlx
# 	@cp mlx/mlx/libmlx.a mlx/mlx/libmlx_Linux.a .
# 	$(CC) $(OBJS_B) $(CFLAGS) $(LIB) $(MLX) -o $(NAME)
# 	@echo "\033[31;5mcub3d bonus\033[0m"

# $(OBJS_B) : $(DIR_OBJS)/%.o : $(DIR_BONUS)/%.c
# 	$(CC) $(CFLAGS) $(MLX_FLAGS)  $(CDFLAGS) $(INC) -c $< -o $@ 

$(OBJS) : $(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c
	$(CC) $(CFLAGS) $(MLX_FLAGS)  $(CDFLAGS) $(INC) -c $< -o $@ 

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	mkdir -p objs/parsing
	mkdir -p objs/exec
# mkdir -p objs/misc
# mkdir -p objs/help
# mkdir -p objs/game

leaks:	${NAME}
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3d $(dad)
clean:
	make clean -C libft
	make clean -C mlx/mlx
	rm -rf ${DIR_OBJS}

fclean:	clean
	make fclean -C libft
	rm -rf ${LIBFT}
	rm -rf ${MLX}
	rm -rf ${NAME}

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re bonus