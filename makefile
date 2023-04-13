# *****************************************************
# compiler
CC = g++

CFLAGS  = -g -Wall -pedantic -O3

# The build target 
TARGET = a.out
RUN = ./
R = Rscript
RSCRIPT = plots.r

# ****************************************************
 
main: main.o point_mass_1D.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o point_mass_1D.o
 
main.o: main.cpp point_mass_1D.hpp
    #$(CC) $(CFLAGS) -c main.cpp  #if more .hpp

point_mass_1D.o: point_mass_1D.hpp

clean: main
	$(RM) main.o point_mass_1D.o
run:
	$(RUN)$(TARGET)

plots: main run 
	$(R) $(RSCRIPT)
