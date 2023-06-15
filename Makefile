#################### INCLUDE ####################

-include make/includes.mk
-include make/sources.mk

INCPATH		= includes/
INC			= -I $(INCPATH)
LIBFT		= libft/libft.a
MLX			= mlx/libmlx.a

################# FOLDER PATHS ##################

OBJPATH		= .objects/
SRCPATH		= sources/
LIBFTPATH	= libft/
MLXPATH		= mlx/

#################### MACROS #####################

OBJS		= $(SOURCES:.c=.o)
OBJS        := $(addprefix $(OBJPATH), $(OBJS))

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g -g3

LDFLAGS     = -L $(LIBFTPATH) -lft
MLXFLAGS	= -lX11 -lXext -L $(MLXPATH) -lmlx -lm

NAME		= fdf

#################### RULES ####################

$(NAME): $(MLX) $(OBJPATH) $(OBJS) $(INCLUDES) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) $(LDFLAGS) $(MLXFLAGS)

all: $(NAME)

.objects/%.o:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

$(OBJPATH):
	@mkdir -p $(OBJPATH)

$(LIBFT):
	@make gmk -C libft
	@make -sC libft

$(MLX):
	@git clone https://github.com/42Paris/minilibx-linux.git mlx 
	@make -sC mlx

clean:
	@if [ -d "$(OBJPATH)" ]; then rm -rf $(OBJPATH); fi
	@make clean -C libft
	@rm -rf mlx

fclean: clean
	@if [ "$(NAME)" ]; then rm -f $(NAME) ; fi
	@make fclean -C libft

re:
	@make clean
	@make all

.PHONY: all clean fclean re
