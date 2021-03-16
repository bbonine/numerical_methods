####################################################
#Prototype make file															 #
#Warranty void if used, proceed at your own risk   #
####################################################
#solver_1: quad_1.cpp
	#g++ -o solver main.cpp function.cpp -I.

CC=g++
CFLAGS=-I.
LFLAGS=

#quad_2: quad_2.o function_2.o
	#$(CC) -o quad_2 quad_2.o function_2.o

#Source files:

SRC_DIR1 := src/prob_1
SRC_DIR2 := src/prob_2
SRC_DIR3 := src/prob_4

OBJ1 := $(SRC_DIR1)/*.cpp
TARGET1 := quad_1

OBJ2 := $(SRC_DIR2)/*.cpp
TARGET2 := quad_2

OBJ3 := $(SRC_DIR3)/*.cpp
TARGET3 := quad_3

all: quad_1 quad_2 quad_3

$(TARGET1): $(OBJ1)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

$(TARGET3): $(OBJ3)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

TARGETS := $(TARGET1) $(TARGET2) $(TARGET3)

.PHONY: clean

clean:
	\rm -f *.o *.mod $(TARGETS) *.lst
