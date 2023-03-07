# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 15:20:31 by seunghoy          #+#    #+#              #
#    Updated: 2023/03/07 17:35:58 by seunghoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
CC := cc
CFLAGS := -Werror -Wall -Wextra
DEBUG_FLAGS := -g
LIB := libft.a
LIB_DIR := libft
SRCS_DIR := srcs
OBJS_DIR := objs

CHANGABLE_HEADERS = pipex.h

SRCS_C := $(addprefix $(SRCS_DIR)/, parse.c parse2.c path.c parent.c child.c)
SRCS_M := $(addprefix $(SRCS_DIR)/, pipex.c check_err.c check_err2.c)
SRCS_B := $(addprefix $(SRCS_DIR)/, )

OBJS_C := $(SRCS_C:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
OBJS_M := $(SRCS_M:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
OBJS_B := $(SRCS_B:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

$(NAME) :: $(LIB)
$(NAME) :: $(OBJS_M) $(OBJS_C) $(CHANGABLE_HEADERS)
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) $(OBJS_M) $(OBJS_C) $(LIB) \
		$(DEBUG_FLAGS) -o $(NAME)

all : $(NAME)

bonus : $(NAME)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< $(DEBUG_FLAGS) -o $@

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)

clean :
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS_C) $(OBJS_B) $(OBJS_M) $(LIB)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME) $(BONUS)

re :
	make fclean
	make all

.PHONY : clean fclean re
