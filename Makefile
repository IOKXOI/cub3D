SRC_FILES		=	main.c cub3d_utils.c  hooks.c set_background.c \
				    raycasting.c hooks_utils.c \
					block_A_checker.c \
					block_A_getter.c \
					block_B_getter.c \
					check_files_acces.c \
					exit.c \
					utils.c \
					open_texture.c put_texture.c raycasting_utils.c \
					init_mlx.c\
					movements_hooks.c utils2.c get_pos.c check_texture.c

SRC_DIR 		= srcs

SRC		=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))

LIBS_FOLDER		=  lib

INCLUDES_DIR	= includes

INCLUDES_FILES	= 	includes.h\
					cub3d.h\
					struct.h

INCLUDES		= $(addprefix $(INCLUDES_DIR)/,$(INCLUDES_FILES))

OBJ_DIR = .build

OBJ		= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

MLX_DIR = minilibx
MLX = ./$(LIBS_FOLDER)/$(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR = 42_libft
LIBFT = ./$(LIBS_FOLDER)/$(LIBFT_DIR)/libft.a

LIBS = $(MLX) $(LIBFT)

NAME	=	cub3d

CC		=	clang

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBS)
					$(CC) $(OBJ) $(LIBS) -lm -lXext -lX11 -o $(NAME)
					@echo "\033[1;32m\nDone!\033[0m"

$(OBJ_DIR)/%.o 		:	$(SRC_DIR)/%.c $(INCLUDES)
									@printf "\033[0;33m Generating cub3d object... %-38.38s \r" $@
									@mkdir -p $(OBJ_DIR)
									@$(CC) -Wall -Wextra -Werror -g3 -c -I $(INCLUDES_DIR) $< -o $@

clean	:
					rm -rf $(OBJ_DIR)
					rm -rf $(OBJ_BONUS_DIR)
					make clean -C $(LIBS_FOLDER)/$(LIBFT_DIR)

fclean	:			clean
					rm -f $(NAME)
					rm -f $(LIBS_FOLDER)/$(LIBFT_DIR)/libft.a

re		:	fclean
			make re -C $(LIBS_FOLDER)/$(LIBFT_DIR)
			make

bonus	:	all

$(LIBS)	:				
			make -C $(LIBS_FOLDER)/$(MLX_DIR)
			make -C $(LIBS_FOLDER)/$(LIBFT_DIR)

cleanlib :
			make fclean -C $(LIBFT_DIR)

.PHONY	:	all clean fclean re cleanlib
