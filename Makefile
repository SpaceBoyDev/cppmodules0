# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dario <dario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 18:40:53 by dario             #+#    #+#              #
#    Updated: 2025/08/11 04:01:31 by dario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cppmodules00

NBR			=	2

MAKEFLAGS	+=	--no-print-directory

CC			=	g++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror
RM			=	rm -f

DIR			=	$( srcs/utils/, $(UTILS))ex0

VALFLAGS	=	--tool=helgrind --tool=drd

define SIGNATURE
      _                                 _
     | |                               | |
   __| | __ _ _ __ _ __ ___   __ _ _ __| |_ _ 
  / _` |/ _` | '__| '_ ` _ \ / _` | '__| __| |  ╱|、
 | (_| | (_| | |  | | | | | | (_| | |  | |_| | (`O -  7
  \__,_|\__,_|_|  |_| |_| |_|\__,_|_|   \__|_|   |、⁻〵
                                                 じしˍ,)ノ                                                                                    
endef
export SIGNATURE

# Colors
RST			=	\033[0m
RED			=	\033[1;31m
BLUE		=	\033[1;34m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
MAGENTA		=	\033[1;35m
CYAN		=	\033[1;36m
WHITE		=	\033[1;37m

# Background colors
BG_RST		=	\033[0m
BG_RED		=	\033[41m
BG_GREEN	=	\033[42m
BG_YELLOW	=	\033[43m
BG_BLUE		=	\033[44m
BG_MAGENTA	=	\033[45m
BG_CYAN		=	\033[46m
BG_WHITE	=	\033[47m

all: $(NAME)

NUMS := $(shell printf "%2d\n" $$(seq 0 $(NBR)))

$(NAME):
	@for i in $(NUMS); do \
		printf "$(MAGENTA)Compiling $(DIR)$$i ✅$(RST)\033[0K\r"; \
		make -C $(DIR)$$i > /dev/null; \
	done
	@printf "$(BG_GREEN)All exercises compiled ✅$(BG_RST)\n"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(MAGENTA)Compiling $< ✅$(RST)\033[0K\r"

clean:
	@for i in $(NUMS); do \
		printf "$(MAGENTA)Cleaning $(DIR)$$i 🧹$(RST)\033[0K\r"; \
		make -C $(DIR)$$i clean > /dev/null; \
	done
	@printf "$(BG_GREEN)All exercises cleaned 🧹$(BG_RST)\n"

fclean: clean
	@for i in $(NUMS); do \
		printf "$(MAGENTA)Fully cleaning $(DIR)$$i 🧹$(RST)\033[0K\r"; \
		make -C $(DIR)$$i fclean > /dev/null; \
	done
	@printf "$(BG_GREEN)All exercises fully cleaned 🧹$(BG_RST)\n"

re: fclean all

.PHONY: all clean fclean re
