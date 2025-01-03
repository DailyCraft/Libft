# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 10:37:39 by dvan-hum          #+#    #+#              #
#    Updated: 2025/01/03 10:49:26 by dvan-hum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -Wall -Wextra -Werror -O3

SRC = ft_btree.c ft_char_alpha.c ft_char.c ft_lstdel.c ft_lstget.c ft_lstput.c \
	ft_math.c ft_memcpy.c ft_memget.c ft_memset.c ft_putfd.c get_next_line.c \
	conv/ft_antoi.c conv/ft_atof.c conv/ft_atoi.c conv/ft_itoa.c \
	conv/ft_ultoa_base.c conv/ft_utoa_base.c \
	printf/ft_printf.c printf/parsing.c printf/printf_utils.c \
	printf/writer_utils.c printf/writer.c \
	str/ft_split.c str/ft_strcat.c str/ft_strchr.c str/ft_strcmp.c \
	str/ft_strcpy.c str/ft_strdup.c str/ft_striteri.c str/ft_strjoin.c \
	str/ft_strlen.c str/ft_strmapi.c str/ft_strnstr.c str/ft_strtrim.c \
	str/ft_substr.c
OBJ = $(patsubst %.c, obj/%.o, $(SRC))
HEADERS = libft.h
INCLUDES = ./

ifndef VERBOSE
MAKEFLAGS += --silent
endif

all: $(NAME)

$(NAME): $(OBJ)
	echo "\n\t\e[1;32mBuilding\e[0m \e[36m$(NAME)\e[0m\n"
	ar rcs $(NAME) $(OBJ)

./obj/%.o: ./src/%.c $(HEADERS)
	echo "$(NAME) \e[90m➤\e[0m \e[32mCompiling\e[0m \e[36m$<\e[0m"
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@ -I $(INCLUDES)

clean:
	echo "$(NAME) \e[90m➤\e[0m\t\e[1;31mCleaning object files\e[0m"
	rm -rf ./obj

fclean: clean
	echo "$(NAME) \e[90m➤\e[0m\t\e[31mCleaning $(NAME)\e[0m"
	rm -f $(NAME)

re: fclean all