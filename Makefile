# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/20 21:48:41 by ligeorgi          #+#    #+#              #
#    Updated: 2020/05/20 21:49:05 by ligeorgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
NAME_VS = vs

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
LIBRARIES_1 = -lft -L$(LIBFT_DIRECTORY) -lmlx -L$(MINILIBX_DIRECTORY)\
 	-framework OpenGL\
 	-framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS_DIR) -I$(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS_DIR = $(LIBFT_DIRECTORY)includes/

include $(LIBFT_DIRECTORY)libft.mk

LIBFT_1 = $(subst ./, , $(LIBFT_HEADERS))
LIBFT_1 += $(subst ./, , $(LIBFT_SOURCES))
LIBFT_2 = $(addprefix $(LIBFT_DIRECTORY),$(LIBFT_1))

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADERS_LIST = push_swap.h\
	vs.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = 	stack_functions.c\
	stack_functions_sa.c\
	stack_functions_pa.c\
	stack_functions_ra.c\
	stack_functions_rra.c\
	get_data.c\
	select_stable_elems_in_a.c\
	move_from_a_to_b.c\
	move_from_b_to_a.c\
	utils.c
SOURCES_LIST_PS = push_swap.c
SOURCES_LIST_CH = checker.c
SOURCES_LIST_VS = vs.c\
	vs1.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
SOURCES_PS = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_PS))
SOURCES_CH = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_CH))
SOURCES_VS = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_VS))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_LIST_PS = $(patsubst %.c, %.o, $(SOURCES_LIST_PS))
OBJECTS_LIST_CH = $(patsubst %.c, %.o, $(SOURCES_LIST_CH))
OBJECTS_LIST_VS = $(patsubst %.c, %.o, $(SOURCES_LIST_VS))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
OBJECTS_PS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_PS))
OBJECTS_CH = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_CH))
OBJECTS_VS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_VS))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(LIBFT_2) $(NAME_PS) $(NAME_CH) $(NAME_VS)

$(LIBFT_2): $(MINILIBX)
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(NAME_PS): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(OBJECTS_PS) -o $(NAME_PS)
	@echo "$(NAME_PS): $(GREEN)$(NAME_PS) object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_PS) was created$(RESET)"

$(NAME_CH): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_CH)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(OBJECTS_CH) -o $(NAME_CH)
	@echo "$(NAME_PS): $(GREEN)$(NAME_CH) object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_CH) was created$(RESET)"

$(NAME_VS): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_VS)
	@$(CC) $(FLAGS) $(LIBRARIES_1) $(INCLUDES) $(OBJECTS) $(OBJECTS_VS) -o $(NAME_VS)
	@echo "$(NAME_PS): $(GREEN)$(NAME_VS) object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_VS) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME_PS): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS) $(LIBFT_2)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@echo "$(NAME_PS): $(GREEN)creating $(LIBFT) $(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(NAME_PS): $(GREEN)Creating $(MINILIBX) $(RESET)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME_PS): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME_PS): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(NAME_PS): $(RED)$(MINILIBX) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME_PS): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME_PS)
	@echo "$(NAME_PS): $(RED)$(NAME_PS) was deleted$(RESET)"
	@rm -f $(NAME_CH)
	@echo "$(NAME_PS): $(RED)$(NAME_CH) was deleted$(RESET)"
	@rm -f $(NAME_VS)
	@echo "$(NAME_PS): $(RED)$(NAME_VS) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE)
