# build proj10

COMPILER = g++
CPPFLAGS := -std=c++2a -O2 -Wall
LIBS := 
VALGRIND = valgrind --tool=memcheck --log-file=memcheck.out --leak-check=full --verbose
EXECUTABLE = day01
SOURCE = $(EXECUTABLE).cpp
INCLUDE = $(EXECUTABLE).h

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE) $(INCLUDE)
	$(COMPILER) $(CPPFLAGS) -o $(EXECUTABLE) $< $(LIBS)

memcheck: $(EXECUTABLE)
	$(VALGRIND) ./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
	rm -f *.out

run: $(EXECUTABLE)
	./$(EXECUTABLE)


