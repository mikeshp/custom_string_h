CC = gcc
CFLAGS = -Wall -Wextra -Wconversion -Werror -Wstrict-prototypes
COMMON = main.c globals.c functions.c demo_functions.c
CUSTOM = my_string.c my_string_names.h

.PHONY: all
all: binstan bincust

binstan: $(COMMON)
	$(CC) $(CFLAGS) $(COMMON) -o binstan

bincust: $(COMMON) $(CUSTOM)
	$(CC) $(CFLAGS) -DCUSTOM_LIB $(COMMON) $(CUSTOM) -o bincust

.PHONY: clean
clean:
	rm -f bincust binstan
