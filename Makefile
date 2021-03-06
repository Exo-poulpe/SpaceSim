CC = gcc -Wall -Wextra -Wpedantic -Wwrite-strings -Wsuggest-attribute=const -Wsuggest-attribute=malloc -Wsuggest-attribute=format -Walloc-zero -Wparentheses
LINKS = -lm -lSDL2
CFLAGS = -std=c11
SANIT = -g -pedantic -fsanitize=address -fsanitize=leak -fsanitize=undefined

CWARN = $(CC)
CWARN += -Waggregate-return
CWARN += -Wbad-function-cast
CWARN += -Wcast-align
CWARN += -Wcast-qual
CWARN += -Wdeclaration-after-statement
CWARN += -Wdisabled-optimization
CWARN += -Wdouble-promotion
CWARN += -Werror
CWARN += -Wfatal-errors
CWARN += -Wfloat-equal
CWARN += -Wformat=2
CWARN += -Wframe-larger-than=5000
CWARN += -Winit-self
CWARN += -Winline
CWARN += -Winvalid-pch
CWARN += -Wlarger-than=10000
CWARN += -Wmissing-declarations
CWARN += -Wmissing-include-dirs
CWARN += -Wmissing-prototypes
CWARN += -Wnested-externs
CWARN += -Wnull-dereference
CWARN += -Wold-style-definition
CWARN += -Wpacked
CWARN += -Wpedantic
CWARN += -pedantic-errors
CWARN += -Wredundant-decls
CWARN += -Wshadow
CWARN += -Wstack-protector
CWARN += -Wstrict-aliasing
CWARN += -Wstrict-overflow=5
CWARN += -Wstrict-prototypes
CWARN += -Wswitch-default
CWARN += -Wswitch-enum
CWARN += -Wundef
CWARN += -Wuninitialized
CWARN += -Wunknown-pragmas
CWARN += -Wunused-parameter
CWARN += -Wvla


# $^ = all element
# $< = first element
# $@ = name of rules

Exe : stack_list.o helper_gfx.o Point.o Vector.o Astre.o main.o
	$(CC) -o $@ $^ $(LINKS) $(CFLAGS) $(SANIT)

Vector.o : libs/Vector.c
	$(CC) -o $@ -c $< $(LINKS)

stack_list.o : libs/stack_list.c
	$(CC) -o $@ -c $< $(LINKS)

helper_gfx.o: libs/helper_gfx.c
	$(CC) -o $@ -c $< $(LINKS)

Point.o : libs/Point.c
	$(CC) -o $@ -c $< $(LINKS)

Astre.o : Astre.c
	$(CC) -o $@ -c $< $(LINKS)

main.o : Vector.o main.c
	$(CC) -c $^ $(LINKS)

gfx.o : libs/gfx.c 
	$(CC) -o $@ -c $< $(LINKS)

clean :
	rm -f *.o Exe

rebuild : clean Exe
