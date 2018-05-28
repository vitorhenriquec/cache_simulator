## Makefile template created by João Pedro de Amorim Paula
#  Edited by Vitor Henrique Coelho Bezerra

SHELL = /bin/sh

# Define here the directories you'll use in your project.
INCDIR = ./include
SRCDIR = ./src
OBJDIR = ./build
BINDIR = ./bin

# Define here some variables (or macros) that you'll tons of times.
CC = g++
CFLAGS = -O0 -Wall -Wextra -ansi -pedantic -g -ggdb -std=c++11 -lm -I. -I$(INCDIR)
RM = rm
#OBJS = $(addprefix $(OBJDIR)/,livro.o cd.o dvd.o midias.o biblioteca.o)
OBJS = $(addprefix $(OBJDIR)/,config.o)
# Here on the OBJS I look for the files specified inside the (addprefix) and
# after the comma and add the $(OBJDIR) is added to the beginning of each of the
# files. More info on (https://www.gnu.org/software/make/manual/html_node/File-Name-Functions.html).

# Phony targets (for more information, visit https://www.gnu.org/software/make/manual/make.html#Phony-Targets)
.PHONY: clean cleanobj cleanbin
.PHONY: all main build
.PHONY: config

# Use "make" to execute everything
all: build main

# Use "make main" to compile the main
main: $(BINDIR)/programa

# Use "make build" to build all the modules
#build: livro dvd midias cd biblioteca 
build: config

# Use "make SOMETHING" to build only the SOMETHING module
config: $(OBJDIR)/config.o 

#cd: $(OBJDIR)/cd.o

#dvd: $(OBJDIR)/dvd.o

#midias: $(OBJDIR)/midias.o

#biblioteca: $(OBJDIR)/biblioteca.o

# Compiles the main
$(BINDIR)/programa: $(SRCDIR)/main.cpp $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/config.o: $(SRCDIR)/config.cpp $(INCDIR)/config.hpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

#$(OBJDIR)/midias.o: $(SRCDIR)/midias.cpp $(INCDIR)/midias.hpp
	#mkdir -p $(OBJDIR)
	#$(CC) $(CFLAGS) -c $< -o $@

#$(OBJDIR)/livro.o: $(SRCDIR)/livro.cpp $(INCDIR)/livro.hpp $(SRCDIR)/midias.cpp $(INCDIR)/midias.hpp
	#mkdir -p $(OBJDIR)
	#$(CC) $(CFLAGS) -c $< -o $@

#$(OBJDIR)/cd.o: $(SRCDIR)/cd.cpp $(INCDIR)/cd.hpp $(SRCDIR)/midias.cpp $(INCDIR)/midias.hpp
	#mkdir -p $(OBJDIR)
	#$(CC) $(CFLAGS) -c $< -o $@

#$(OBJDIR)/dvd.o: $(SRCDIR)/dvd.cpp $(INCDIR)/dvd.hpp $(SRCDIR)/midias.cpp $(INCDIR)/midias.hpp
	#mkdir -p $(OBJDIR)
	#$(CC) $(CFLAGS) -c $< -o $@

# Removes all objects
cleanobj:
	$(RM) $(OBJDIR)/*.o

# Removes all executables
cleanbin:
	$(RM) $(BINDIR)/*

# Removes all executables and all objects
clean: cleanobj cleanbin
