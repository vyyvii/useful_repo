##
## EPITECH PROJECT, 2026
## Makefile UtilsLib
## File description:
## Makefile UtilsLib
##

.PHONY: all clean fclean re

SRC = $(shell find src -name '*.c')
OBJ := $(patsubst %.c,%.o,$(SRC))

CC = epiclang
CFLAGS = -Wall -Wextra -g3 -Iinclude -O0

NAME = libUtilsLib.a
REMOVE = rm -f -r

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME) a.out
	$(REMOVE) **.gcno **.gcda **.html **.css

re: fclean all
