######################################################################
## Filename:      Makefile
## Author:        Eddie Baron <baron@ou.edu>
## Created at:    Wed Aug  5 10:12:22 2009
## Modified at:   Mon Feb 22 14:27:48 2021
## Modified by:   Eddie Baron <baron@ou.edu>
## Version:       
## Description:   Makefile for SMP code
######################################################################
######################################################
# common (trivial) flags
######################################################

AR := ar
RANLIB := ranlib
#
# Flags for debugging:
#
FC := gfortran
FFLAGS := -g 

CC := gcc
CFLAGS := -g

CXX := g++
CXXFLAGS := -g


#LINKER FLAGS

LFLAGS :=

#Source files:

OBJ1 := euler.o
TARGET1 := euler

default: $(TARGET1)
$(TARGET1): $(OBJ1)
	$(CXX) $(CXXFLAGS) $(LFLAGS) $^ -o $@


OBJ3 := odeint.o bsstep.o pzextr.o mmid.o
OBJ4 := intbsstep.o
TARGET4 := intbsstep

default: $(TARGET4)


OBJ4: $(OBJ3)

$(TARGET4): $(OBJ3) $(OBJ4)
	$(CXX) $(CXXFLAGS) $(LFLAGS) $^ -o $@


.PHONY: clean

clean:
	\rm -f *.o


