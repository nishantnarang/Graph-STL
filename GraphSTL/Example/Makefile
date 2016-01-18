CC=g++

ifeq ($(DEBUG),yes)
	CXXFLAGS=-Wall -g
	LDFLAGS=-Wall -g
else
	CXXFLAGS=-Wall
	LDFLAGS=-Wall
endif

INCPATH=inc
SRCPATH=src
OBJPATH=obj
LIBPATH=lib
BINPATH=bin

INC=
SRC=$(SRCPATH)/example.cpp
OBJ=$(OBJPATH)/example.o
OUT= example

INCLUDES=-I ../GraphLibrary/$(INCPATH)
LIBRARIES=-L ../GraphLibrary/$(LIBPATH)
LIB=-lGraphLibrary

default: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(LDFLAGS) $(LIBRARIES) -static -o $@ $^ $(LIB)

$(OBJPATH)/%.o: $(SRCPATH)/%.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
