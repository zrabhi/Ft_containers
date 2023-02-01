# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 06:33:45 by zrabhi            #+#    #+#              #
#    Updated: 2023/02/01 06:53:25 by zrabhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



BLUE 	:= \033[1;34m
SRC 	:= test.cpp 
CC 		:= clang++
RM 		:= rm -f
OBJ		:= $(SRC:%.cpp=%.o)
FLAG	:= -Wall -Werror -Wextra -std=c++98
NAME 	:= Map
HEADERS := Map.hpp

all: $(NAME)
	@sleep 1
	@echo ""
	@echo " \n$(BLUE)Creating :Map...$(BLUE)"
	@cat ascii-art.ans
	@echo " \n"
	@sleep 2

$(NAME) : $(OBJ)
	$(CC) $(FLAG) $(SRC) -o $(NAME)

%.o: %.cpp $(HEADERS)
	@$(CC) $(FLAG) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo " $(BLUE)Removing obj...$(BLUE)"
	
fclean : clean
	@echo " $(BLUE)file removed succesfully$(BLUE)"
	@$(RM) $(NAME)
	
re : fclean all