NAME		:= adventure
SRCS		:= main.cpp leftPath.cpp rightPath.cpp inputProcessing.cpp underConstruction.cpp
OBJS		:= main.o leftPath.o rightPath.o inputProcessing.o underConstruction.o
CXX			:= g++
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