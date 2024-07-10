CC = gcc
CFLAGS = -Wall -Iheaders
LIBS = -lSDL2 -lSDL2_image -lm
SRC = src/main.c
OBJ = $(SRC:.c=.o)
EXEC = 3D_Maze_Bunny

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJ) $(EXEC)
