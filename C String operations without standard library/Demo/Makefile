CC = clang
CFLAGS = -g -Wall -fsanitize=address
LDFLAGS = -g -Wall -fsanitize=address
DEPS = mystring.h mystddef.h
OBJ = mystring.c demo.c

mydemomake:$(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

clean:
	rm $(OBJ) mydemomake
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<
