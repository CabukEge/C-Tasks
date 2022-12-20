CC = clang
CFLAGS = -g -Wall -fsanitize=address
LDFLAGS = -g -Wall -fsanitize=address
DEPS = 
OBJ = dotprod.c
#../a2/mystddef.h

dotprod:$(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

clean:
	rm $(OBJ) dotprod
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<
