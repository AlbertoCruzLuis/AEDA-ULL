BIN     := bin
SRC     := src
INCLUDE := include
LIBRARIES		:= 
EXECUTABLE  := main

CXX       := g++
CXX_FLAGS := -I$(INCLUDE)

all: $(BIN)/$(EXECUTABLE)

run:
		clear
		@echo "🚀 Executing..."
		./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
		@echo "🚧 Building..."
		$(CXX) $(CXX_FLAGS) $^ -o $@

clean:
		@echo "🧹 Clearing..."
		-rm $(BIN)/*