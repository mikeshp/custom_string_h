CC = gcc
CFLAGS = -Wall -Wextra -Wconversion -Werror -Wstrict-prototypes
COMMON = main.c globals.c functions.c demo_functions.c
CUSTOM = my_string.c
S_HDRS = demo_functions.h functions.h globals.h
C_HDRS = my_string_names.h my_string.h

.PHONY: all
all: binstan bincust

binstan: $(COMMON) $(S_HDRS)
	$(CC) $(CFLAGS) $(COMMON) -o binstan

bincust: $(COMMON) $(CUSTOM) $(S_HDRS) $(C_HDRS)
	$(CC) $(CFLAGS) -DCUSTOM_LIB $(COMMON) $(CUSTOM) -o bincust

.PHONY: clean
clean:
	rm -f bincust binstan
