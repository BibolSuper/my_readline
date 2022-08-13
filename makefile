CC=gcc
OUT = my_readline
DEPS = my_readline.c

all:
	$(CC) $(DEPS) -o $(OUT)

clean:
	rm -f *.o my_readline 
