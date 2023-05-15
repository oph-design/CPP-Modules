# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 13:44:40 by oheinzel          #+#    #+#              #
#    Updated: 2023/05/15 09:43:59 by oheinzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test
SRC_FILES 	=	main
OBJS_DIR	=	obj/
COMP		=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -f
FILE		=	file

GREEN		= \033[0;32m
CYAN		= \033[0;36m
WHITE		= \033[0m

SRCS 		= 	$(addsuffix .cpp, $(SRC_FILES))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all:		$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS) $(FILE)
			@$(COMP) $(OBJS) -o $(NAME)
			@echo "$(GREEN)exercise compiled!$(WHITE)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp | $(OBJSF)
			@echo "$(CYAN)Compiling $(WHITE): $<"
			@$(COMP) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)

$(FILE):
			@echo "Lorem ipsum dolor sit amet, consetetur sadipscing elitr," > file
			@echo "sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua." >> file
			@echo "At vero eos et accusam et justo duo dolores et ea rebum." >> file
			@echo "Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet." >> file
			@echo "Lorem ipsum dolor sit amet, consetetur sadipscing elitr," >> file
			@echo "sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua." >> file
			@echo "At vero eos et accusam et justo duo dolores et ea rebum." >> file
			@echo "Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet." >> file

clean:
			@$(RM) -rf $(OBJS_DIR)
			@echo "$(GREEN)O-files removed!$(WHITE)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(GREEN)project cleaned!$(WHITE)"

re:			fclean all
			@echo "$(GREEN)exercise rebuild!$(WHITE)"

.PHONY:		all clean fclean re
