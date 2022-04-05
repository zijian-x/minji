SRC_DIR := src
BIN_DIR := bin
NAME := $(BIN_DIR)/a.out

CC := clang++
LANG := c++
STD := c++20
WARNINGS := -Wall -Wextra -Wpedantic -Weffc++ -Wconversion -Wshadow -Wnon-virtual-dtor \
			-Wcast-align -Woverloaded-virtual -Wnull-dereference \
			-Wno-unused-parameter -Wno-unused-function
SAN := -fsanitize=address,undefined
CFLAGS := -x $(LANG) -std=$(STD) $(WARNINGS) -g -O0

src := $(shell find $(SRC_DIR) -type f -name "*cpp")
obj := $(src:.cpp=.o)

all: run

run: generate_cc $(NAME)
	@./$(NAME) $(ARGS)

rerun: fclean run

$(NAME): $(obj)
	$(CC) $(obj) $(SAN) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)

generate_cc:
	@echo $(CFLAGS) | sed 's/\s/\n/g' > compile_flags.txt

leak: $(NAME)
	valgrind --leak-check=full $(NAME)
