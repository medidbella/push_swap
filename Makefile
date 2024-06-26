PROG = push_swap
B_PROG = checker
B_MAIN = bonus_main.c
MAIN = mondatory_main.c
FILES = spliting.c parsing.c extra_functoins.c extra_functoins2.c sorting.c operations.c sorting2.c ranking.c
OBJ_FILES = $(FILES:.c=.o)
MAIN_OBJ = $(MAIN:.c=.o)
B_MAIN_OBJ = $(B_MAIN:.c=.o)
C_flags =  -Wall -Wextra -Werror 

$(PROG): $(OBJ_FILES) $(MAIN_OBJ)
	cc $(C_flags) $(OBJ_FILES) $(MAIN_OBJ) -o $(PROG)

bonus: $(B_PROG)

$(B_PROG): $(OBJ_FILES) $(B_MAIN_OBJ)
	cc $(C_flags) $(OBJ_FILES) $(B_MAIN_OBJ) -o $(B_PROG)

all: $(PROG) $(B_PROG)

clean:
	rm -f $(OBJ_FILES) $(B_MAIN_OBJ) $(MAIN_OBJ)

fclean: clean
	rm -f $(PROG) $(B_PROG)

re: fclean $(PROG)
