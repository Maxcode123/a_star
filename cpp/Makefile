CC=g++
SRC=src
SRCS=$(wildcard $(SRC)/*.cpp)
OBJ=obj
CC=g++
SRC=src
SRCS=$(wildcard $(SRC)/*.cpp)
OBJ=obj
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
BINDIR=bin
BIN=$(BINDIR)/main

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(BINDIR)/* $(OBJ)/*