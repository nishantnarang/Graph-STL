CC=g++

ifeq ($(DEBUG),yes)
	CXXFLAGS=-Wall -g
	LDFLAGS=-Wall -g
else
	CXXFLAGS=-Wall
	LDFLAGS=-Wall
endif

AR=ar
ARFLAGS=rcs

INCPATH=inc
SRCPATH=src
OBJPATH=obj
LIBPATH=lib
BINPATH=bin

OBJ=$(OBJPATH)/Node.o
OBJ1 =$(OBJPATH)/Graph.o 

OUT=$(LIBPATH)/libGraphLibrary.a

INCLUDES=-I ./$(INCPATH)

default: $(OUT)

$(OUT): $(OBJ) $(OBJ1)
	$(AR) $(ARFLAGS) $@ $(OBJ) $(OBJ1)

$(OBJ): $(SRCPATH)/Node.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $(OBJ)


$(OBJ1): $(SRCPATH)/Graph.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $(OBJ1)


	
