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
OBJS = $(addprefix $(OBJDIR)/,config.o cache.o bloco.o memprincipal.o simulador.o)
# Here on the OBJS I look for the files specified inside the (addprefix) and
# after the comma and add the $(OBJDIR) is added to the beginning of each of the
# files. More info on (https://www.gnu.org/software/make/manual/html_node/File-Name-Functions.html).

# Phony targets (for more information, visit https://www.gnu.org/software/make/manual/make.html#Phony-Targets)
.PHONY: clean cleanobj cleanbin
.PHONY: all main build
.PHONY: config cache bloco memprincipal simulador

# Use "make" to execute everything
all: build main

# Use "make main" to compile the main
main: $(BINDIR)/programa

# Use "make build" to build all the modules
build: config cache bloco memprincipal simulador

# Use "make SOMETHING" to build only the SOMETHING module
config: $(OBJDIR)/config.o 

cache: $(OBJDIR)/cache.o

bloco: $(OBJDIR)/bloco.o

memprincipal: $(OBJDIR)/memprincipal.o

simulador: $(OBJDIR)/simulador.o 

# Compiles the main
$(BINDIR)/programa: $(SRCDIR)/main.cpp $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/config.o: $(SRCDIR)/config.cpp $(INCDIR)/config.hpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/cache.o: $(SRCDIR)/cache.cpp $(INCDIR)/cache.hpp $(SRCDIR)/bloco.cpp $(INCDIR)/bloco.hpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/bloco.o: $(SRCDIR)/bloco.cpp $(INCDIR)/bloco.hpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/memprincipal.o: $(SRCDIR)/memprincipal.cpp $(INCDIR)/memprincipal.hpp $(SRCDIR)/bloco.cpp $(INCDIR)/bloco.hpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/simulador.o: $(SRCDIR)/simulador.cpp $(INCDIR)/simulador.hpp $(SRCDIR)/memprincipal.cpp $(INCDIR)/memprincipal.hpp $(SRCDIR)/cache.cpp $(INCDIR)/cache.hpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes all objects
cleanobj:
	$(RM) $(OBJDIR)/*.o

# Removes all executables
cleanbin:
	$(RM) $(BINDIR)/*

# Removes all executables and all objects
clean: cleanobj cleanbin