## Make file default settings
NAME := simpleApp
ROOT := .
BUILD := debug
COMPILER := g++
PWD := $(shell pwd)

## Universal flags and compiler defines
FLAGS := -Wall
DEFINES := -DUNIX -DLINUX

## Default library, include, source and output directory
LIBDIR := $(ROOT)/../../lib
INCDIR := $(ROOT)/../../include
SRCDIR := $(ROOT)
OUTDIR := $(ROOT)

#LIBS := -lGLEW -lGL -lGLU -lSDL -lIL -lILU -lILUT -lMCG
LIBS := -llua5.1 -llualib50 -lGL -lGLU -lboost_filesystem-mt
LIBS += $(shell sdl-config --cflags  --libs --static-libs)

LIBPATH := -L$(LIBDIR)
INCLUDE := -I$(INCDIR)

ifeq "$(BUILD)" "debug"

FLAGS += -g
DEFINES += -D_DEBUG
LIBS += -lChain_Debug
OBJDIR := $(ROOT)/../../obj/$(NAME)-Debug
TARGET := $(NAME)_Debug

else

FLAGS +=
DEFINES += -DNDEBUG
LIBS += -lChain
OBJDIR := $(ROOT)/../../obj/$(NAME)-Release
TARGET := $(NAME)

endif

$(shell if ! [ -d $(OBJDIR) ] ; then mkdir -p $(OBJDIR); fi)
$(shell if ! [ -d $(OUTDIR) ] ; then mkdir -p $(OUTDIR); fi)

## Get a list of files
FILES := $(shell cd $(SRCDIR) ; ls *.cpp ; cd $(PWD))
OBJECTS:= $(addprefix $(OBJDIR)/, $(FILES:.cpp=.o))

all : $(OUTDIR)/$(TARGET)

## Create the lib by archiving them
$(OUTDIR)/$(TARGET): $(OBJECTS)
	$(COMPILER) $(FLAGS) $(OBJECTS) $(LIBPATH) $(LIBS) -o $(OUTDIR)/$(TARGET)

## Compile the object files
$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(COMPILER) -c $(FLAGS) $(DEFINES) $(INCLUDE) $< -o $@

## Clean up by removing compiled object files and the output
clean :
	rm -f $(OUTDIR)/$(TARGET)
	rm -f $(OBJECTS)
