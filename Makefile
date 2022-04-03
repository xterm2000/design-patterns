TARGET = main
TARGET_DIR = ./runtime/
CC = g++
CFLAGS = \
	-Wall \
	-O2 \
	-std=c++17 \
	-Wshadow \
	-g \

#-Wall \
#-fmax-errors=2 \
#-O2 \
#-std=c++17 \
#-Wshadow \
#-g \
#-pedantic
#-Wextra \
#-Wfatal-errors \ 
#-Werror \
#-pedantic 

default: builder 

builder: main.o concrete_builders.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o concrete_builders.o 


concrete_builders.o: concrete_builders.h concrete_builders.cpp
	$(CC) $(CFLAGS) -c concrete_builders.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	clear
	@echo Cleaning up
	rm -f *.exe *.swp *.o


