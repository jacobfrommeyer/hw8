CC=g++
CFLAGS=-g -Wall
#Enable all warnings
DOXCONFIG=Doxyfile

#Build game, archive it, and document it
all: build archive doc

build: game

game: game.o samplemain.o mancala.o
	$(CC) $(CFLAGS) -o game game.o samplemain.o mancala.o

game.o: game.cc game.h
	$(CC) $(CFLAGS) -c game.cc

main.o: samplemain.cc game.h mancala.h
	$(CC) $(CFLAGS) -c samplemain.cc

mancala.o: mancala.cc mancala.h
	$(CC) $(CFLAGS) -c mancala.cc

archive: mancala.tgz

mancala.tgz: game Makefile README.md html Doxyfile
	tar -cvz --exclude=*.o --exclude='mancala.tgz' -f mancala.tgz *

doc: html

#Update documentation files
html: $(DOXCONFIG) *.cc *.h
	doxygen $(DOXCONFIG)

#Clean up old .o files, executable, and archived file
clean:
	-rm -f *.o game mancala.tgz
	-rm -rf html