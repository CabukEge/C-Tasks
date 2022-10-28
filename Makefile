CC = clang
CFLAGS = -g -Wall -fsanitize=address
LDFLAGS = -g -Wall -fsanitize=address
DEPS = chessboard.h 
OBJ = chessboard.c springerproblem.c
#../a2/mystddef.h

mydemomake:$(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

clean:
	rm $(OBJ) mydemomake
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<
