CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET   = MilitarySystem
SRCS     = $(wildcard *.cpp)
OBJS     = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
