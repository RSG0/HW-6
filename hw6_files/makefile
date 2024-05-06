SRC1 = bucket_sort.c
SRC2 = list.c
SRC3 = main.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)

EXE = unit_tests

CFLAGS = -g -std=c99

all: $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3)
	gcc $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) -o $(EXE)

$(OBJ1): $(SRC1)
	gcc $(CFLAGS) -c $(SRC1) -o $(OBJ1)

$(OBJ2): $(SRC2)
	gcc $(CFLAGS) -c $(SRC2) -o $(OBJ2)

$(OBJ3): $(SRC3)
	gcc $(CFLAGS) -c $(SRC3) -o $(OBJ3) -Wno-nonnull

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(EXE)