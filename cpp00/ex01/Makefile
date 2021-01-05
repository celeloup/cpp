NAME = phonebook

SRC = main.cpp Contact.cpp

all: $(NAME)

$(NAME): $(SRC)
	@clang++ -Wall -Werror -Wextra $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean re