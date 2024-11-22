CXX = g++
CXXFLAGS = -std=c++11
LDFLAGS = -lncurses

OBJECTS = main.o game.o

gol: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) gol

