NAME		:= adventure
SRCS		:= main.cpp gamestate.cpp firstSegment.cpp inputProcessing.cpp underConstruction.cpp 
OBJS		:= main.o gamestate.o firstSegment.o inputProcessing.o underConstruction.o
CXX			:= g++ -std=c++17
CXXFLAGS	:= -Wall -Wextra -Werror
CPPFLAGS	:= -I .
RM			:= rm -f
MAKEFLAGS	:= --no-print-directory

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re