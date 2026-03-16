NAME		:= adventure
SRCS		:= main.cpp gamestate.cpp firstSegment.cpp inputProcessing.cpp underConstruction.cpp 
OBJS		:= $(SRCS:.cpp=.o)
CXX			:= g++ -std=c++17
CXXFLAGS	:= -Wall -Wextra -Werror
CPPFLAGS	:= -I .
RM			:= rm -f
MAKEFLAGS	:= --no-print-directory

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re