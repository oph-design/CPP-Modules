# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 13:44:40 by oheinzel          #+#    #+#              #
#    Updated: 2023/05/15 08:48:08 by oheinzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	harlFilter
SRC_FILES 	=	main Harl
OBJS_DIR	=	obj/
COMP		=	c++
CFLAGS		=	-g -Wall -Werror -Wextra -std=c++98
RM			=	rm -f

GREEN		= \033[0;32m
CYAN		= \033[0;36m
WHITE		= \033[0m

SRCS 		= 	$(addsuffix .cpp, $(SRC_FILES))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all:		$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS)
			@$(COMP) $(OBJS) -o $(NAME)
			@echo "$(GREEN)exercise compiled!$(WHITE)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp | $(OBJSF)
			@echo "$(CYAN)Compiling $(WHITE): $<"
			@$(COMP) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@echo "$(GREEN)O-files removed!$(WHITE)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(GREEN)project cleaned!$(WHITE)"

re:			fclean all
			@echo "$(GREEN)exercise rebuild!$(WHITE)"

.PHONY:		all clean fclean re
