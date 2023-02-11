# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 15:29:49 by zrabhi            #+#    #+#              #
#    Updated: 2023/02/11 16:09:42 by zrabhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE := \033[1;34m
SRC 	:= map_tests.cpp 
CC 		:= clang++
RM 		:= rm -f
OBJ		:= $(SRC:%.cpp=%.o)
FLAG	:= -Wall -Werror -Wextra -std=c++98 -g
STD 	:=  -D STL=1
FT		:=	-D STL=0
NAME 	:= FTmap
STL 	:= STDmap
HEADERS := Map.hpp