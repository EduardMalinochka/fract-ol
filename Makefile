SRCS = main.c init.c utils.c draw.c color.c interaction.c
OBJS = $(SRCS:.c=.o)
CC = gcc
MFLAGS = ./mlxlib/libmlx.a libft/libft.a
AFLAGS =  -Wall -Wextra -Werror -I./mlxlib
RM = rm -rf
NAME = fractol

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C libft
	make -C ./mlxlib

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	make clean -C ./mlxlib	
	make clean -C libft
	$(RM) ./*.o

re : fclean all

.PHONY : all fclean clean re