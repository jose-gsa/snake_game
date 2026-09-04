CXX = g++

# Flags with c++17
CXXFLAGS = -Wall -Wextra -pedantic -g -std=c++17 -I$(INCDIR)

# ncurses
LDLIBS = -lm -lncurses

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

TARGET = $(BINDIR)/main

SOURCES = $(wildcard $(SRCDIR)/*.cpp)

OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# --- Compilation Rules ---

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LDLIBS)
	@echo "The program was compiled successfully: $(TARGET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	@echo "Cleaning archives..."	
	rm -rf $(OBJDIR) $(BINDIR)
