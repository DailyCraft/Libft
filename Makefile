# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 10:37:39 by dvan-hum          #+#    #+#              #
#    Updated: 2024/11/12 14:06:21 by dvan-hum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -Wall -Wextra -Werror

SRC = ft_bzero.c ft_calloc.c ft_char_alpha.c ft_char.c ft_lstget.c ft_lstput.c \
	ft_math.c ft_mem.c ft_putfd.c \
	conv/ft_antoi.c conv/ft_atoi.c conv/ft_itoa.c conv/ft_ultoa_base.c \
	conv/ft_utoa_base.c \
	str/ft_split.c str/ft_strcat.c str/ft_strchr.c str/ft_strcmp.c \
	str/ft_strcpy.c str/ft_strdup.c str/ft_striteri.c str/ft_strjoin.c \
	str/ft_strlen.c str/ft_strmapi.c str/ft_strnstr.c str/ft_strtrim.c \
	str/ft_substr.c
OBJ = $(patsubst %.c, obj/%.o, $(SRC))
INCLUDES = ./

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

./obj/%.o: %.c | ./obj
	$(CC) -c $< -o $@ -I $(INCLUDES)

./obj:
	mkdir ./obj ./obj/conv ./obj/str

clean: 
	rm -rf ./obj

fclean: clean
	rm -f $(NAME)

re: fclean all