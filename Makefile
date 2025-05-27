
NAME = cub3d
LIBFTDIR = ./libft
MINILIBXDIR = ./minilibx-linux
HEADCUB3DIR = ./includes
INCLUDES = -I $(HEADCUB3DIR) -I $(MINILIBXDIR) -I $(LIBFTDIR)
ADDLIBFT = -L $(LIBFTDIR) -lft
ADDMINILIBX = -L $(MINILIBXDIR) -lmlx -lXext -lX11 -lm
CC  = cc
CFLAGS = -Wextra -Werror -Wall -g

SRCS	= $(addprefix src/, $(addsuffix .c, \
			main ))
SRCS	+= $(addprefix src/utils/, $(addsuffix .c, \
			put_pixel \
			ft_abs \
			ft_line \
			clear_image ))
SRCS	+= $(addprefix src/render/, $(addsuffix .c, \
			background ))
SRCS	+= $(addprefix src/utils/vector/, $(addsuffix .c, \
			angle_between_vector \
			dot_vector \
			magnitude_of_vector \
			mult_vector \
			norm_vector \
			rotate_vector \
			sub_vector \
			add_vector ))

OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(MINILIBXDIR)
	$(CC) $(CFLAGS) $(INCLUDES)  -o $(NAME) $(OBJS) $(ADDLIBFT) $(ADDMINILIBX)
	clear
	@echo "MANDATORY PART COMPILED!"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFTDIR)
	make clean -C $(MINILIBXDIR)
	rm -f $(OBJS)
	clear
	@echo "OBJECTS CLEANED!"
fclean: clean
		make fclean -C $(LIBFTDIR)
		rm -f $(NAME)
		clear
		@echo "ALL CLEANED!"
re: fclean all

run: all
	./cub3d maps/default.cub
