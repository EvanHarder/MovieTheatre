CXX=g++
CXXFLAGS=-Wall -I. -std=c++11
SFML_LIBS=-lsfml-graphics -lsfml-window -lsfml-system
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
TARGET=start

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)