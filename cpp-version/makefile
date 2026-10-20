CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2

# Integração com SDL2
SDL_FLAGS := $(shell pkg-config --cflags sdl2)
SDL_LIBS  := $(shell pkg-config --libs sdl2)

SRCS := $(wildcard *.cpp)
TARGET := main

.PHONY: all build run run-time clean

all: build

build: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SDL_FLAGS) $(SRCS) -o $(TARGET) $(SDL_LIBS)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)