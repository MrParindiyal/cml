# Default target
# all:
# 	@echo "Specify a target (e.g., make alpha) to compile a specific C file."

# # The compiler
CC = clang
CFLAGS = -ferror-limit=2 -gdwarf-4 -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wshadow

OBJS = handle_csv.o knn_calc.o

# # Pattern rule for compiling individual files
%: %.c
	@echo "compiling: $< --> $*.o"
	@$(CC) $(CFLAGS) -c handle_csv.c -o handle_csv.o
	@$(CC) $(CFLAGS) -c knn_calc.c -o knn_calc.o
	@$(CC) $(CFLAGS) -c $< -o $*.o
	@echo "linking: $*.o $(OBJS) --> $*"
	@$(CC) $(CFLAGS) $*.o $(OBJS) -o $* -lm
	@echo "DONE"

# Pattern rule for compiling individual files
# %.o: %.c
# 	@echo "compiling: $< --> $*"
# 	@$(CC) $(CFLAGS) -c $< -o $*

# # Linking rule
# %: %.o $(OBJS)
# 	@echo "linking: $< $(OBJS) --> $@"
# 	@$(CC) $(CFLAGS) $< $(OBJS) -o $@ -lm
# 	@echo "DONE"

# Handle invalid arguments
%:
	@if [ ! -f $*.c ]; then \
		echo "make: *** Not a valid target. Stop."; \
	fi