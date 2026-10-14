CXX ?= c++
CXXFLAGS ?= -std=c++11 -O2 -Wall -Wextra
.PHONY: all clean
all: build/aquarium
build/aquarium: CED18I049_AQUARIUM.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) $< -lglut -lGLU -lGL -o $@
clean:
	rm -rf build
