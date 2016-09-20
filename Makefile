NAME = eensim

CC=g++
CXXFLAGS=--std=c++11 -o
HFLAGS=--std=c++11 -c

SRCDIR = ./src/
ODIR = ./obj/
BINDIR = ./bin/

GRAPHOBJS = $(addprefix $(ODIR), graph.o)
GRAPHOBJSRC = $(addprefix $(SRCDIR)/graph/, graph.cpp)

SIMSRC = $(addprefix $(SRCDIR), main.cpp)

BINNAME = $(addprefix $(BINDIR), $(NAME))

all : $(SIMSRC) $(GRAPHOBJS)
	$(CC) $(CXXFLAGS) $(BINNAME) $(SIMSRC) $(GRAPHOBJS)

$(GRAPHOBJS) : $(GRAPHDOBJSRC)
	$(CC) $(HFLAGS) $(GRAPHOBJSRC) -o $@ $<
