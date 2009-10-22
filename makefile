## Make file default settings
NAME := Chain
ROOT := .
BUILD := debug
COMPILER := g++
PWD := $(shell pwd)

## Universal flags and compiler defines
FLAGS := -Wall
DEFINES := -DUNIX -DLINUX -DLIB

## Default library, include, source and output directory
LIBDIR := $(ROOT)/lib
INCDIR := $(ROOT)/include
SRCDIR := $(ROOT)/src
OUTDIR := $(ROOT)/lib

## Libraries to use
# LIBS := -lGLEW -lGL -lGLU $(shell Magick++-config --cppflags --ldflags --libs)
LIBS :=

#LIBS += 

LIBPATH := -L$(LIBDIR)
INCLUDE := -I$(INCDIR)

## Debug setup
ifeq "$(BUILD)" "debug"

FLAGS += -g
DEFINES += -D_DEBUG
LIBS +=
OBJDIR := obj/Debug
TARGET := lib$(NAME)_Debug.a

else ## Non-debug setup

FLAGS +=
DEFINES += -DNDEBUG
LIBS +=
OBJDIR := obj/Release
TARGET := lib$(NAME).a

endif

## Create missing directories
$(shell if ! [ -d $(OBJDIR) ] ; then mkdir -p $(OBJDIR); fi)
$(shell if ! [ -d $(OUTDIR) ] ; then mkdir -p $(OUTDIR); fi)

## Get a list of files
FILES := $(shell cd $(SRCDIR) ; ls *.cpp ; cd $(PWD))

OBJECTS:= $(addprefix $(OBJDIR)/, $(FILES:.cpp=.o))

## Make all
all : $(OUTDIR)/$(TARGET)

## Create the lib by archiving them
$(OUTDIR)/$(TARGET): $(OBJECTS)
	ar rcs $(OUTDIR)/$(TARGET) $(OBJECTS)

## Compile the object files
$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(COMPILER) -c $(FLAGS) $(DEFINES) $(INCLUDE) $< -o $@

## Clean up by removing compiled object files and the output
clean :
	rm -f $(OUTDIR)/$(TARGET)
	rm -f $(OBJECTS)
