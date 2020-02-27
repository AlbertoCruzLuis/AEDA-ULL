# main: main.o tablero.o celula.o
# 	g++ -o main main.o tablero.o celula.o
# main.o: main.cpp tablero.h celula.h
# 	 g++ -c main.cpp
# tablero.o: tablero.cpp tablero.h
# 	g++ -c tablero.cpp
# celula.o: tablero.h celula.cpp celula.h
# 	g++ -c celula.cpp 
  
# clean:
# 	rm *.o main


DEPS = celula.h tablero.h
OBJ = celula.o tablero.o main.o

%.o: %.cpp $(DEPS)
	g++ -c -o $@ $<

main: $(OBJ)
	g++ -o $@ $^

clean:
	rm *.o main