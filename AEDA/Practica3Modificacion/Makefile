CXX = g++
DEPS = celula.h celula1.h celula2.h celula3.h celulax.h tablero.h
OBJ = celula.o celula1.o celula2.o celula3.o celulax.o tablero.o main.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $<

main: $(OBJ)
	$(CXX) -o $@ $^

clean:
	rm *.o main