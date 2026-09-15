CXX = g++

# Flags with c++17
CXXFLAGS = -Wall -Wextra -pedantic -g -std=c++17 -I$(INCDIR)

# Libraries
CLI_LIBS = -lm -lncurses
SFML_LIBS = -lm -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Targets
CLI_TARGET = $(BINDIR)/main-cli
SFML_TARGET = $(BINDIR)/main-sfml

CORE_SOURCES = $(SRCDIR)/game.cpp $(SRCDIR)/snake.cpp

# CLI archives (ncurses)
CLI_SOURCES = $(SRCDIR)/main_cli.cpp $(SRCDIR)/terminalUI.cpp

# (SFML)
SFML_SOURCES = $(SRCDIR)/main_sfml.cpp $(SRCDIR)/sfmlUI.cpp

CORE_OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(CORE_SOURCES))
CLI_OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(CLI_SOURCES))
SFML_OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SFML_SOURCES))

# --- Compilation Rules ---

.PHONY: all cli sfml clean

all: cli sfml

cli: $(CLI_TARGET)

sfml: $(SFML_TARGET)

# CLI Build
$(CLI_TARGET): $(CORE_OBJECTS) $(CLI_OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(CLI_TARGET) $(CORE_OBJECTS) $(CLI_OBJECTS) $(CLI_LIBS)
	@echo "The CLI program was compiled successfully: $(CLI_TARGET)"

# SFML build (GUI)
$(SFML_TARGET): $(CORE_OBJECTS) $(SFML_OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(SFML_TARGET) $(CORE_OBJECTS) $(SFML_OBJECTS) $(SFML_LIBS)
	@echo "The SFML program was compiled successfully: $(SFML_TARGET)"

# Regra geral para transformar .cpp em .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning archives..."
	rm -rf $(OBJDIR) $(BINDIR)
