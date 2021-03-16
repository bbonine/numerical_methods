####################################################
#Prototype make file															 #
#Warranty void if used, proceed at your own risk   #
####################################################


CC=g++
CFLAGS=-I.
LFLAGS=


#Source files:

SRC_DIR1 := src


OBJ1 := $(SRC_DIR1)/solver.cpp
TARGET1 := solver



all: solver

$(TARGET1): $(OBJ1)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@



TARGETS := $(TARGET1) 

.PHONY: clean

clean:
	\rm -f *.o *.mod $(TARGETS) *.lst
