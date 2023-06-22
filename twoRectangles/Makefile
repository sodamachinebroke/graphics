CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lSDL2

SRC = main.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = twoRectangles

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
