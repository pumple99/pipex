# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:45:12 by seunghoy          #+#    #+#              #
#    Updated: 2023/02/24 15:25:44 by seunghoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
CFLAGS := -Werror -Wall -Wextra
DEBUG_FLAGS := -g
SRCS := ft_isalpha.c \
       ft_memcpy.c \
       ft_strlcpy.c \
       ft_toupper.c \
       ft_isascii.c \
       ft_memmove.c \
       ft_strlen.c \
       ft_atoi.c \
       ft_isdigit.c \
       ft_memset.c \
       ft_strncmp.c \
       ft_bzero.c \
       ft_isprint.c \
       ft_strchr.c \
       ft_strnstr.c \
       ft_calloc.c \
       ft_memchr.c \
       ft_strdup.c \
       ft_strrchr.c \
       ft_isalnum.c \
       ft_memcmp.c \
       ft_strlcat.c \
       ft_tolower.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_strtrim.c \
       ft_split.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
              ft_lstnew_bonus.c \
              ft_lstadd_front_bonus.c \
              ft_lstsize_bonus.c \
              ft_lstlast_bonus.c \
              ft_lstadd_back_bonus.c \
              ft_lstdelone_bonus.c \
              ft_lstclear_bonus.c \
              ft_lstiter_bonus.c \
              ft_lstmap_bonus.c \
       gnl.c \
       gnl_utils.c \
              pf_printf.c \
              pf_parse.c \
              pf_len.c \
              pf_len_conv.c \
              pf_copy.c \
			  pf_copy_conv.c \
              pf_copy_conv2.c
       

OBJS := $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $<

clean :
	rm -rf $(OBJS) $(DEPS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re
