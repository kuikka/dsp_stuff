CXX = g++
CFLAGS = -g
CXXFLAGS = -std=c++14
LDFLAGS = 

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $^

dsp: sinegen.o main.o
	$(CXX) $(LDFLAGS) $(CFLAGS) $(CXXFLAGS) -o $@ $^ 
