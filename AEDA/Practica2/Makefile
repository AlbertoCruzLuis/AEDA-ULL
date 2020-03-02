CXX = g++
DEPS = celula.h tablero.h
OBJ = celula.o tablero.o main.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $<

main: $(OBJ)
	$(CXX) -o $@ $^

clean:
	rm *.o main