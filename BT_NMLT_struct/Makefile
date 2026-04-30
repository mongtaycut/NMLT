CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++11
TARGET = build/Debug/outDebug
SRCDIR = src
OBJDIR = build/obj

SOURCES = $(SRCDIR)/source.cpp $(SRCDIR)/tamgiac.cpp $(SRCDIR)/Diem.cpp
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build/

.PHONY: clean