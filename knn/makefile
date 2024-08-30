# Default target
# all:
# 	@echo "Specify a target (e.g., make alpha) to compile a specific C file."

# # The compiler
CC = clang
CFLAGS = -ferror-limit=2 -gdwarf-4 -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wshadow


# Pattern rule for compiling individual files
%: %.c
	@echo "compiling: $< --> $*.o"
	@$(CC) $(CFLAGS) -c $< -o $*.o
	@echo "linking: $*.o --> $*"
	@$(CC) $(CFLAGS) $*.o -o $* -lm
	@echo "DONE"

# Handle invalid arguments
%:
	@if [ ! -f $*.c ]; then \
		echo "make: *** Not a valid target. Stop."; \
	fi