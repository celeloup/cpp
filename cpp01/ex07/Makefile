NAME = replace

SRC = main.cpp

all: $(NAME)

$(NAME): $(SRC)
	@clang++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean re