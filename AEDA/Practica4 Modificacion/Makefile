CXX       := g++
CXX_FLAGS := #-Wall

BIN     := bin
SRC     := src
INCLUDE := include
LIBRARIES		:= $(INCLUDE)/*.h
EXECUTABLE  := main

all: $(BIN)/$(EXECUTABLE)

run:
		clear
		@echo "🚀 Executing..."
		./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
		@echo "🚧 Building..."
		$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBRARIES)

clean:
		@echo "🧹 Clearing..."
		-rm $(BIN)/*