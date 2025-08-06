# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dario <dario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 18:40:53 by dario             #+#    #+#              #
#    Updated: 2025/08/06 04:32:09 by dario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	tests

MAKEFLAGS	+=	--no-print-directory

CC			=	g++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror
RM			=	rm -f

VALFLAGS	=	--tool=helgrind --tool=drd

SRCS		=	Account.cpp tests.cpp

OBJS		=	$(SRCS:.cpp=.o)

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

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(MAGENTA)All $(NAME) source files compiled ✅$(RST)\033[0K\r"
	@echo "\n$(BG_GREEN)$(NAME) compiled!$(BG_RST)"
	@echo "$(MAGENTA)$$SIGNATURE$(RST)"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(MAGENTA)Compiling $< ✅$(RST)\033[0K\r"

CUT = $(shell cut -c 19- log.txt)


check: all
	@tmpfile=$$(mktemp); \
	./tests | cut -c19- > $$tmpfile; \
	if diff -c $$tmpfile 19920104_091532.log > /dev/null; then \
		echo "✅ Todo OK :3 ✅"; \
	else \
		echo "❌ Diferencias encontradas ❌:"; \
 		cat $$tmpfile; \
	fi; \
	rm $$tmpfile

clean:
	@echo "$(BG_BLUE)Cleaning...$(BG_RST)"
	@$(RM) $(OBJS)
	@echo "$(CYAN)libft objs cleaned!$(BG_RST)🧹"
	@echo "$(CYAN)$(NAME) objs cleaned!$(BG_RST)🧹"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) fully cleaned!$(BG_RST)🧹"
	@echo "$(BG_GREEN)All cleaned!$(BG_RST)"

re: fclean all

.PHONY: all clean fclean re
