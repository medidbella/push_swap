PROG = push_swap
FILES = before_sort.c parsing.c mondatory_main.c etc.c etc2.c sorting.c operations.c sorting2.c
OBJ_FILES = $(FILES:.c=.o)
C_flags =  -Wall -Wextra -Werror 

$(PROG): $(OBJ_FILES)
	cc $(C_flags) $(OBJ_FILES) -o $(PROG)

all: $(PROG)

clean:
	rm -f $(OBJ_FILES)
fclean: clean
	rm -f $(PROG)
re: fclean $(PROG)
