PROG = push_swap
B_PROG = checker
MAIN = mondatory_main.c
B_MAIN = bonus_main.c
FILES = before_sort.c parsing.c etc.c etc2.c sorting.c operations.c sorting2.c
B_FILES = before_sort.c parsing.c etc.c etc2.c sorting.c operations.c sorting2.c
OBJ_FILES = $(FILES:.c=.o) $(MAIN:.c=.o)
B_OBJ_FILES = $(B_FILES:.c=.o) $(MAIN:.c=.o)
C_flags =  -Wall -Wextra -Werror 

$(PROG): $(OBJ_FILES)
	cc $(C_flags) $(OBJ_FILES) -o $(PROG)

bonus: $(B_PROG)

$(B_PROG): $(OBJ_FILES)
	cc $(C_flags) $(B_OBJ_FILES) -o $(B_PROG)
all: $(PROG) bonus

clean:
	rm -f $(OBJ_FILES) $(B_OBJ_FILES)
fclean: clean
	rm -f $(PROG) $(B_PROG)
re: fclean $(PROG)
