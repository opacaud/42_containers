# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 10:47:26 by opacaud           #+#    #+#              #
#    Updated: 2022/02/24 11:18:00 by opacaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MINE		= ft_containers_mine
NAME_REAL		= ft_containers_real

SRCS_DIR		= .
INCLUDES		= .
CXX				= clang++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -g3
DEP_FLAGS		= -MMD -MP

OBJS_DIR_MINE	= objs_mine
OBJS_DIR_REAL	= objs_real

SRCS_MINE		= main_mine.cpp
SRCS_REAL		= main_real.cpp

OBJS_MINE		= $(addprefix ${OBJS_DIR_MINE}/,${SRCS_MINE:.cpp=.o})
OBJS_REAL		= $(addprefix ${OBJS_DIR_REAL}/,${SRCS_REAL:.cpp=.o})

DEP_MINE		= ${OBJS_MINE:.o=.d}
DEP_REAL		= ${OBJS_REAL:.o=.d}

all:			mine real

mine:			${NAME_MINE}

real:			${NAME_REAL}

${NAME_MINE}:	${OBJS_MINE}
				${CXX} -I${INCLUDES} ${CXXFLAGS} ${DEP_FLAGS} ${OBJS_MINE} -o $@

${NAME_REAL}:	${OBJS_REAL}
				${CXX} -I${INCLUDES} ${CXXFLAGS} ${DEP_FLAGS} ${OBJS_REAL} -o $@

${OBJS_DIR_MINE}/%.o:${SRCS_DIR}/%.cpp
				@mkdir -p ${@D}
				${CXX} ${CXXFLAGS} ${DEP_FLAGS} -c $< -o $@

${OBJS_DIR_REAL}/%.o:${SRCS_DIR}/%.cpp
				@mkdir -p ${@D}
				${CXX} ${CXXFLAGS} ${DEP_FLAGS} -c $< -o $@

clean:
				rm -rf ${OBJS_DIR_MINE} ${OBJS_DIR_REAL}

fclean:			clean
				rm -f ${NAME_MINE} ${NAME_REAL} mine real

re:				fclean all

.PHONY:			all mine real clean fclean re

-include ${DEP_MINE} ${DEP_REAL}
